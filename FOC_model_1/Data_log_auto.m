%% ================================================================
%% Simulink Signal Logger — .mat Data Log with Gate_pulse Scaling
%% Logs all signals into a structured .mat file per run
%% Named with custom prefix + timestamp
%% ================================================================

%% ========== CONFIGURATION ==========
MODEL_NAME    = 'PMSM_to_BLDC_mod1';
DEST_FOLDER   = 'D:\Harini\Matlab_FOC_studymodels\Data_logging_Sensorlessmod';
FILE_PREFIX   = 'Sensorless_log';
SIM_STOP_TIME = 47;

% --- Signals to log ---
SIGNAL_NAMES = { ...
    'W_inp', ...
    'W_mes', ...
    'Gate_pulse', ...
    'idq_ref', ...
    'Id', ...
    'Iq', ...
    'W_fb_sim', ...
    'Phase_current', ...
    'Pos', ...
    'Duty cycle', ...
    'Vabc' ...
};

% --- Gate_pulse zoom window (seconds) ---
GATE_ZOOM_START    = 46.5;
GATE_ZOOM_END      = 47.0;
GATE_PULSE_CHANNELS = {'GA_H', 'GB_H', 'GC_H', 'GA_L', 'GB_L', 'GC_L'};
%% ===================================


%% 1. Setup destination folder
if ~exist(DEST_FOLDER, 'dir')
    mkdir(DEST_FOLDER);
    fprintf('Created folder: %s\n', DEST_FOLDER);
end

%% 2. Timestamped run ID
timestamp  = datestr(now, 'yyyymmdd_HHMMSS');
run_id     = sprintf('%s_%s', FILE_PREFIX, timestamp);
fprintf('Run ID   : %s\n', run_id);
fprintf('Saving to: %s\n\n', DEST_FOLDER);

%% 3. Load and configure model
if ~bdIsLoaded(MODEL_NAME)
    load_system(MODEL_NAME);
    fprintf('Loaded model: %s\n', MODEL_NAME);
end
set_param(MODEL_NAME, 'SignalLogging',     'on');
set_param(MODEL_NAME, 'SignalLoggingName', 'logsout');
set_param(MODEL_NAME, 'SaveFormat',        'Dataset');
set_param(MODEL_NAME, 'StopTime',          num2str(SIM_STOP_TIME));

%% 4. Run simulation
fprintf('Running simulation...\n');
simOut  = sim(MODEL_NAME);
logsout = simOut.logsout;
fprintf('Simulation complete. Signals available: %d\n\n', logsout.numElements);

%% 5. Build lookup map from logsout
logsout_map = containers.Map();
for k = 1:logsout.numElements
    logsout_map(logsout{k}.Name) = k;
end

% Print all available signal names for reference
fprintf('Signals found in logsout:\n');
disp(keys(logsout_map));

%% 6. Extract signals into structured log
log_data  = struct();
n_saved   = 0;
n_skipped = 0;

for i = 1:numel(SIGNAL_NAMES)
    sig_name  = SIGNAL_NAMES{i};
    safe_name = regexprep(sig_name, '[^\w]', '_');  % e.g. 'Duty cycle' -> 'Duty_cycle'

    %% -- Check signal exists --
    if ~isKey(logsout_map, sig_name)
        fprintf('  [SKIP] "%s" not found in logsout.\n', sig_name);
        n_skipped = n_skipped + 1;
        continue;
    end

    %% -- Extract time and data --
    s    = logsout{logsout_map(sig_name)};
    t    = s.Values.Time;
    data = squeeze(s.Values.Data);

    %% -- Store full signal --
    log_data.(safe_name).time   = t;
    log_data.(safe_name).data   = data;
    log_data.(safe_name).name   = sig_name;
    log_data.(safe_name).run_id = run_id;

    %% -- Gate_pulse: zoom window + channel labels --
    if strcmp(sig_name, 'Gate_pulse')
        idx = t >= GATE_ZOOM_START & t <= GATE_ZOOM_END;

        log_data.(safe_name).zoomed_time = t(idx);

        if ~isvector(data)
            zoomed_data = data(idx, :);
            log_data.(safe_name).zoomed_data = zoomed_data;

            n_ch = size(data, 2);
            if n_ch == numel(GATE_PULSE_CHANNELS)
                log_data.(safe_name).channels = GATE_PULSE_CHANNELS;
            else
                % Fallback channel names if count doesn't match
                log_data.(safe_name).channels = arrayfun( ...
                    @(n) sprintf('CH%d', n), 1:n_ch, 'UniformOutput', false);
            end
        else
            log_data.(safe_name).zoomed_data = data(idx);
            log_data.(safe_name).channels    = {'Gate_pulse'};
        end

        fprintf('  [OK] Logged: %s  (full + zoomed [%.1f–%.1f s], %d channels)\n', ...
                sig_name, GATE_ZOOM_START, GATE_ZOOM_END, ...
                numel(log_data.(safe_name).channels));
    else
        fprintf('  [OK] Logged: %s\n', sig_name);
    end

    n_saved = n_saved + 1;
end

%% 7. Add run metadata
log_meta.run_id      = run_id;
log_meta.model       = MODEL_NAME;
log_meta.timestamp   = timestamp;
log_meta.stop_time   = SIM_STOP_TIME;
log_meta.signals     = SIGNAL_NAMES;
log_meta.saved_count = n_saved;

%% 8. Save .mat log file
mat_filename = fullfile(DEST_FOLDER, [run_id '.mat']);
save(mat_filename, 'log_data', 'log_meta', '-v7.3');
fprintf('\n[SAVED] %s\n', mat_filename);

%% 9. Summary
fprintf('\n========== Run Summary ==========\n');
fprintf('Run ID   : %s\n',        run_id);
fprintf('Model    : %s\n',        MODEL_NAME);
fprintf('Stop time: %d s\n',      SIM_STOP_TIME);
fprintf('Signals  : %d/%d saved\n', n_saved, numel(SIGNAL_NAMES));
if n_skipped > 0
    fprintf('Skipped  : %d signal(s) not found\n', n_skipped);
end
fprintf('File     : %s\n',        mat_filename);
fprintf('=================================\n');