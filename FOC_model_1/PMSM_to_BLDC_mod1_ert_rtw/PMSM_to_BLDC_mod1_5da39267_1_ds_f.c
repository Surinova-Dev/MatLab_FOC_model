/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_f.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_f(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t11, NeDsMethodOutput *out)
{
  real_T t8;
  real_T t9;
  real_T zc_int0;
  boolean_T intrm_sf_mf_2;
  (void)LC;
  t8 = t11->mX.mX[9ULL] * -0.037 + 48.0;
  t9 = t11->mX.mX[14ULL] * t11->mX.mX[14ULL] * 0.86624797433542056;
  intrm_sf_mf_2 = (t11->mX.mX[11ULL] < 0.5);
  zc_int0 = fabs(t11->mX.mX[2ULL]);
  if (t11->mM.mX[0ULL] != 0) {
    out->mF.mX[3ULL] = (-t11->mX.mX[3ULL] + 48.0) - t11->mX.mX[6ULL] * 0.001;
  } else {
    out->mF.mX[3ULL] = (-t11->mX.mX[3ULL] + 48.0) * 1.0E-6 - t11->mX.mX[6ULL];
  }

  if (t11->mM.mX[1ULL] != 0) {
    out->mF.mX[4ULL] = t11->mX.mX[3ULL] - t11->mX.mX[6ULL] * 0.001;
  } else {
    out->mF.mX[4ULL] = t11->mX.mX[3ULL] * 1.0E-6 - t11->mX.mX[6ULL];
  }

  if (t11->mM.mX[3ULL] != 0) {
    out->mF.mX[5ULL] = (-t11->mX.mX[4ULL] + 48.0) - t11->mX.mX[7ULL] * 0.001;
  } else {
    out->mF.mX[5ULL] = (-t11->mX.mX[4ULL] + 48.0) * 1.0E-6 - t11->mX.mX[7ULL];
  }

  if (t11->mM.mX[4ULL] != 0) {
    out->mF.mX[6ULL] = t11->mX.mX[4ULL] - t11->mX.mX[7ULL] * 0.001;
  } else {
    out->mF.mX[6ULL] = t11->mX.mX[4ULL] * 1.0E-6 - t11->mX.mX[7ULL];
  }

  if (t11->mM.mX[5ULL] != 0) {
    out->mF.mX[7ULL] = (-t11->mX.mX[5ULL] + 48.0) - t11->mX.mX[8ULL] * 0.001;
  } else {
    out->mF.mX[7ULL] = (-t11->mX.mX[5ULL] + 48.0) * 1.0E-6 - t11->mX.mX[8ULL];
  }

  if (t11->mM.mX[6ULL] != 0) {
    out->mF.mX[8ULL] = t11->mX.mX[5ULL] - t11->mX.mX[8ULL] * 0.001;
  } else {
    out->mF.mX[8ULL] = t11->mX.mX[5ULL] * 1.0E-6 - t11->mX.mX[8ULL];
  }

  if (t11->mX.mX[11ULL] < 0.5) {
    if (t11->mM.mX[8ULL] != 0) {
      out->mF.mX[11ULL] = t11->mX.mX[14ULL] - t11->mX.mX[13ULL];
    } else if (t11->mM.mX[9ULL] != 0) {
      out->mF.mX[11ULL] = t11->mX.mX[14ULL] - (-t11->mX.mX[13ULL]);
    } else {
      out->mF.mX[11ULL] = t11->mX.mX[14ULL] - t11->mX.mX[1ULL];
    }
  } else {
    out->mF.mX[11ULL] = t11->mX.mX[14ULL];
  }

  if (intrm_sf_mf_2) {
    out->mF.mX[12ULL] = t11->mX.mX[9ULL] - (t11->mX.mX[2ULL] * t11->mX.mX[14ULL]
      * 0.001 + t9) / (t8 == 0.0 ? 1.0E-16 : t8) * 1000.0;
  } else {
    out->mF.mX[12ULL] = t11->mX.mX[9ULL];
  }

  if (intrm_sf_mf_2) {
    out->mF.mX[13ULL] = t11->mX.mX[12ULL] - ((t11->mX.mX[9ULL] * t11->mX.mX[9ULL]
      * 3.7E-5 + t11->mX.mX[2ULL] * t11->mX.mX[2ULL] * 2.5E-6) + t9);
  } else {
    out->mF.mX[13ULL] = t11->mX.mX[12ULL] - t11->mX.mX[2ULL] * t11->mX.mX[2ULL] *
      2.5E-6;
  }

  if (t11->mM.mX[10ULL] != 0) {
    out->mF.mX[14ULL] = t11->mX.mX[13ULL] - 0.1;
  } else {
    out->mF.mX[14ULL] = t11->mX.mX[13ULL] - 0.03 / (zc_int0 == 0.0 ? 1.0E-16 :
      zc_int0) * 1000.0;
  }

  out->mF.mX[0ULL] = -0.0;
  out->mF.mX[1ULL] = -0.0;
  out->mF.mX[2ULL] = -0.0;
  out->mF.mX[9ULL] = -(real_T)(t11->mM.mX[7ULL] != 0);
  out->mF.mX[10ULL] = 0.0;
  out->mF.mX[15ULL] = 0.0;
  out->mF.mX[16ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}
