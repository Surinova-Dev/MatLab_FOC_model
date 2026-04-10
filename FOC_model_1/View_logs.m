%% View_logs.m — Load and plot all signals from a saved .mat log

%% 1. Load the file
d = load('D:\Harini\Matlab_FOC_studymodels\Data_logging_Sensorlessmod\Sensorless_log_20260410_154204.mat');
fprintf('Loaded run: %s\n\n', d.log_meta.run_id);

%% 2. Print metadata
fprintf('===== Run Metadata =====\n');
fprintf('Run ID    : %s\n', d.log_meta.run_id);
fprintf('Model     : %s\n', d.log_meta.model);
fprintf('Timestamp : %s\n', d.log_meta.timestamp);
fprintf('Stop time : %d s\n', d.log_meta.stop_time);
fprintf('Signals   : %d saved\n', d.log_meta.saved_count);
fprintf('========================\n\n');

%% 3. Plot each signal in its OWN figure
signal_fields = fieldnames(d.log_data);

for k = 1:numel(signal_fields)
    f    = signal_fields{k};
    name = d.log_data.(f).name;
    t    = d.log_data.(f).time;
    data = d.log_data.(f).data;

    figure(k);                          % unique figure per signal
    clf;
    set(gcf, 'Color', 'w', ...
             'Name', name, ...
             'NumberTitle', 'off', ...
             'Position', [100 + mod(k,4)*30, 100 + floor(k/4)*30, 900, 350]);

    %% -- Gate_pulse: zoomed + channel legend --
    if strcmp(name, 'Gate_pulse') && isfield(d.log_data.(f), 'zoomed_time')
        t_z    = d.log_data.(f).zoomed_time;
        data_z = d.log_data.(f).zoomed_data;
        chs    = d.log_data.(f).channels;
        ch_colors = lines(numel(chs));
        hold on;
        for c = 1:numel(chs)
            plot(t_z, data_z(:, c), 'Color', ch_colors(c,:), 'LineWidth', 1.2);
        end
        hold off;
        legend(chs, 'Location', 'best', 'FontSize', 8);
        xlabel(sprintf('Time (s)  [last %.1fs]', t_z(end) - t_z(1)), 'FontSize', 10);

    %% -- Multi-channel signals (e.g. Vabc, idq_ref) --
    elseif ~isvector(data)
        ch_colors = lines(size(data, 2));
        hold on;
        leg_entries = cell(1, size(data, 2));
        for c = 1:size(data, 2)
            plot(t, data(:, c), 'Color', ch_colors(c,:), 'LineWidth', 1.2);
            leg_entries{c} = sprintf('%s[%d]', name, c);
        end
        hold off;
        legend(leg_entries, 'Location', 'best', 'FontSize', 8, 'Interpreter', 'none');
        xlabel('Time (s)', 'FontSize', 10);
        if numel(t) > 1 && t(1) < t(end)
            xlim([t(1), t(end)]);
        end

    %% -- Single channel signals --
    else
        plot(t, data, 'LineWidth', 1.5, 'Color', [0.13 0.55 0.13]);
        xlabel('Time (s)', 'FontSize', 10);
        if numel(t) > 1 && t(1) < t(end)
            xlim([t(1), t(end)]);
        end
    end

    %% -- Smart Y scaling --
    valid_data = data(isfinite(data));
    if ~isempty(valid_data)
        y_low   = prctile(valid_data(:), 1);
        y_high  = prctile(valid_data(:), 99);
        y_range = y_high - y_low;
        if y_range == 0, y_range = abs(y_high) * 0.1 + 1e-6; end
        y_pad   = 0.10 * y_range;
        ylim([y_low - y_pad, y_high + y_pad]);
    end

    ylabel(name, 'FontSize', 11, 'Interpreter', 'none');
    title(sprintf('%s   |   %s', name, d.log_meta.run_id), ...
          'FontSize', 12, 'Interpreter', 'none');
    grid on;
    drawnow;

    fprintf('  [OK] Plotted: %s\n', name);
end

fprintf('\nAll %d signal plots displayed.\n', numel(signal_fields));