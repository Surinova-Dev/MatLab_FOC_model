/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_dxf.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_dxf(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t61, NeDsMethodOutput *out)
{
  real_T intermediate_der30;
  real_T t4;
  real_T t40;
  real_T t5;
  boolean_T intrm_sf_mf_2;
  (void)LC;
  t40 = t61->mX.mX[9ULL] * -0.037 + 48.0;
  intrm_sf_mf_2 = (t61->mX.mX[11ULL] < 0.5);
  t4 = fabs(t61->mX.mX[2ULL]);
  intermediate_der30 = t61->mX.mX[14ULL] * 1.7324959486708411;
  if (t61->mX.mX[2ULL] != t61->mX.mX[2ULL]) {
    t5 = t61->mX.mX[2ULL];
  } else if (t61->mX.mX[2ULL] > 0.0) {
    t5 = 1.0;
  } else {
    t5 = t61->mX.mX[2ULL] < 0.0 ? -1.0 : 0.0;
  }

  if (t61->mX.mX[11ULL] < 0.5) {
    if (t61->mM.mX[8ULL] != 0) {
      out->mDXF.mX[0ULL] = 0.0;
    } else {
      out->mDXF.mX[0ULL] = t61->mM.mX[9ULL] != 0 ? 0.0 : -1.0;
    }
  } else {
    out->mDXF.mX[0ULL] = 0.0;
  }

  if (intrm_sf_mf_2) {
    out->mDXF.mX[1ULL] = -(t61->mX.mX[14ULL] * 0.001 / (t40 == 0.0 ? 1.0E-16 :
      t40) * 1000.0);
  } else {
    out->mDXF.mX[1ULL] = 0.0;
  }

  if (intrm_sf_mf_2) {
    out->mDXF.mX[2ULL] = -(t61->mX.mX[2ULL] * 5.0E-6);
  } else {
    out->mDXF.mX[2ULL] = -(t61->mX.mX[2ULL] * 5.0E-6);
  }

  if (t61->mM.mX[10ULL] != 0) {
    out->mDXF.mX[3ULL] = 0.0;
  } else {
    t4 *= t4;
    out->mDXF.mX[3ULL] = -(-0.03 / (t4 == 0.0 ? 1.0E-16 : t4) * t5 * 1000.0);
  }

  if (t61->mM.mX[0ULL] != 0) {
    out->mDXF.mX[4ULL] = -1.0;
  } else {
    out->mDXF.mX[4ULL] = -1.0E-6;
  }

  if (t61->mM.mX[3ULL] != 0) {
    out->mDXF.mX[6ULL] = -1.0;
  } else {
    out->mDXF.mX[6ULL] = -1.0E-6;
  }

  if (t61->mM.mX[5ULL] != 0) {
    out->mDXF.mX[8ULL] = -1.0;
  } else {
    out->mDXF.mX[8ULL] = -1.0E-6;
  }

  if (t61->mM.mX[0ULL] != 0) {
    out->mDXF.mX[10ULL] = -0.001;
  } else {
    out->mDXF.mX[10ULL] = -1.0;
  }

  if (t61->mM.mX[3ULL] != 0) {
    out->mDXF.mX[12ULL] = -0.001;
  } else {
    out->mDXF.mX[12ULL] = -1.0;
  }

  if (t61->mM.mX[5ULL] != 0) {
    out->mDXF.mX[14ULL] = -0.001;
  } else {
    out->mDXF.mX[14ULL] = -1.0;
  }

  if (intrm_sf_mf_2) {
    t4 = t40 * t40;
    out->mDXF.mX[16ULL] = 1.0 - -(t61->mX.mX[2ULL] * t61->mX.mX[14ULL] * 0.001 +
      t61->mX.mX[14ULL] * t61->mX.mX[14ULL] * 0.86624797433542056) / (t4 == 0.0 ?
      1.0E-16 : t4) * -0.037 * 1000.0;
  } else {
    out->mDXF.mX[16ULL] = 1.0;
  }

  if (intrm_sf_mf_2) {
    out->mDXF.mX[17ULL] = -(t61->mX.mX[9ULL] * 7.4E-5);
  } else {
    out->mDXF.mX[17ULL] = 0.0;
  }

  if (t61->mX.mX[11ULL] < 0.5) {
    if (t61->mM.mX[8ULL] != 0) {
      out->mDXF.mX[19ULL] = -1.0;
    } else {
      out->mDXF.mX[19ULL] = (real_T)(t61->mM.mX[9ULL] != 0);
    }
  } else {
    out->mDXF.mX[19ULL] = 0.0;
  }

  if (intrm_sf_mf_2) {
    out->mDXF.mX[22ULL] = -((t61->mX.mX[2ULL] * 0.001 + intermediate_der30) /
      (t40 == 0.0 ? 1.0E-16 : t40) * 1000.0);
  } else {
    out->mDXF.mX[22ULL] = 0.0;
  }

  out->mDXF.mX[5ULL] = t61->mM.mX[1ULL] != 0 ? 1.0 : 1.0E-6;
  out->mDXF.mX[7ULL] = t61->mM.mX[4ULL] != 0 ? 1.0 : 1.0E-6;
  out->mDXF.mX[9ULL] = t61->mM.mX[6ULL] != 0 ? 1.0 : 1.0E-6;
  out->mDXF.mX[11ULL] = t61->mM.mX[1ULL] != 0 ? -0.001 : -1.0;
  out->mDXF.mX[13ULL] = t61->mM.mX[4ULL] != 0 ? -0.001 : -1.0;
  out->mDXF.mX[15ULL] = t61->mM.mX[6ULL] != 0 ? -0.001 : -1.0;
  out->mDXF.mX[23ULL] = intrm_sf_mf_2 ? -intermediate_der30 : 0.0;
  out->mDXF.mX[18ULL] = 1.0;
  out->mDXF.mX[20ULL] = 1.0;
  out->mDXF.mX[21ULL] = 1.0;
  (void)LC;
  (void)out;
  return 0;
}
