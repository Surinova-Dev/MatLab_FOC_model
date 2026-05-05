/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "PMSM_to_BLDC_mod1_5da39267_1.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_gateway.h"

void PMSM_to_BLDC_mod1_5da39267_1_gateway(void)
{
  NeModelParameters modelparams = { (enum NeSolverTypeTag)1, 0.001, 0.001, 0.001,
    FALSE, FALSE, (enum NeModifyAbsTolTag)0, 0.0001, 0.0, FALSE, FALSE, FALSE, (
    enum SscLoggingSettingTag)0, 699887660.0, TRUE, FALSE, FALSE };

  NeSolverParameters solverparams = { TRUE, TRUE, FALSE, FALSE, FALSE, FALSE,
    TRUE, FALSE, FALSE, 0.001, 0.001, 1e-09, FALSE, FALSE, 100U, FALSE, 1U, (
    enum NeConsistencySolverTag)2, (enum NeIndexReductionMethodTag)1, TRUE,
    1e-09, (enum NeToleranceSourceTag)1, 0.001, 0.001, 0.001, FALSE, (enum
    NeLocalSolverChoiceTag)0, TRUE, 1U, 0.001, FALSE, 3U, 2U, FALSE, 2U, (enum
    NeLinearAlgebraChoiceTag)0, 0U, (enum NeEquationFormulationChoiceTag)0,
    1024U, FALSE, 0.001, (enum NePartitionStorageMethodTag)0, 1024U, (enum
    NePartitionMethodTag)0, TRUE, (enum NeMultibodyLocalSolverChoiceTag)0, 0.001
  };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int rtpDaes[1] = { 0 };

  int* rtwLogDaes = NULL;
  int* solverHitDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0U, 0U }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  PMSM_to_BLDC_mod1_5da39267_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group(
    "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    1,
    rtpDaes,
    0,
    rtwLogDaes,
    0,
    solverHitDaes);
}
