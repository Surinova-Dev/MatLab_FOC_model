/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[266] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, true,
    false, false, true, false, false, true, false, false, true, false, false,
    true, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, false, true, true, true, true,
    true, true, false, true, false, false, true, false, true, false, true, true,
    true, true, true, true, false, true, false, false, true, false, true, false,
    true, true, true, true, true, true, false, true, false, false, true, false,
    true, false, true, true, true, true, true, true, false, true, false, false,
    true, false, true, false, true, true, true, true, true, true, false, true,
    false, false, true, false, true, false, true, true, true, true, true, true,
    false, true, false, false, true, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, false, true, true, false,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, true,
    false, true, false, true, false, true, false, true, false, true, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true };

  int32_T i;
  (void)t1;
  (void)LC;
  for (i = 0; i < 266; i++) {
    out->mOBS_IL.mX[i] = _cg_const_1[i];
  }

  (void)LC;
  (void)out;
  return 0;
}
