/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[18] = { 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3 };

  (void)t1;
  (void)LC;
  out->mMCON_P.mNumCol = 17ULL;
  out->mMCON_P.mNumRow = 17ULL;
  out->mMCON_P.mJc[0] = _cg_const_1[0];
  out->mMCON_P.mJc[1] = _cg_const_1[1];
  out->mMCON_P.mJc[2] = _cg_const_1[2];
  out->mMCON_P.mJc[3] = _cg_const_1[3];
  out->mMCON_P.mJc[4] = _cg_const_1[4];
  out->mMCON_P.mJc[5] = _cg_const_1[5];
  out->mMCON_P.mJc[6] = _cg_const_1[6];
  out->mMCON_P.mJc[7] = _cg_const_1[7];
  out->mMCON_P.mJc[8] = _cg_const_1[8];
  out->mMCON_P.mJc[9] = _cg_const_1[9];
  out->mMCON_P.mJc[10] = _cg_const_1[10];
  out->mMCON_P.mJc[11] = _cg_const_1[11];
  out->mMCON_P.mJc[12] = _cg_const_1[12];
  out->mMCON_P.mJc[13] = _cg_const_1[13];
  out->mMCON_P.mJc[14] = _cg_const_1[14];
  out->mMCON_P.mJc[15] = _cg_const_1[15];
  out->mMCON_P.mJc[16] = _cg_const_1[16];
  out->mMCON_P.mJc[17] = _cg_const_1[17];
  out->mMCON_P.mIr[0] = 0;
  out->mMCON_P.mIr[1] = 1;
  out->mMCON_P.mIr[2] = 2;
  (void)LC;
  (void)out;
  return 0;
}
