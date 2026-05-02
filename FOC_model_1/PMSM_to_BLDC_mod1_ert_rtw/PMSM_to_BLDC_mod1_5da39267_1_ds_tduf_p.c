/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[8] = { 0, 1, 2, 3, 4, 5, 6, 8 };

  static int32_T _cg_const_2[8] = { 3, 4, 1, 5, 6, 7, 8, 9 };

  (void)t1;
  (void)LC;
  out->mTDUF_P.mNumCol = 7ULL;
  out->mTDUF_P.mNumRow = 17ULL;
  out->mTDUF_P.mJc[0] = _cg_const_1[0];
  out->mTDUF_P.mJc[1] = _cg_const_1[1];
  out->mTDUF_P.mJc[2] = _cg_const_1[2];
  out->mTDUF_P.mJc[3] = _cg_const_1[3];
  out->mTDUF_P.mJc[4] = _cg_const_1[4];
  out->mTDUF_P.mJc[5] = _cg_const_1[5];
  out->mTDUF_P.mJc[6] = _cg_const_1[6];
  out->mTDUF_P.mJc[7] = _cg_const_1[7];
  out->mTDUF_P.mIr[0] = _cg_const_2[0];
  out->mTDUF_P.mIr[1] = _cg_const_2[1];
  out->mTDUF_P.mIr[2] = _cg_const_2[2];
  out->mTDUF_P.mIr[3] = _cg_const_2[3];
  out->mTDUF_P.mIr[4] = _cg_const_2[4];
  out->mTDUF_P.mIr[5] = _cg_const_2[5];
  out->mTDUF_P.mIr[6] = _cg_const_2[6];
  out->mTDUF_P.mIr[7] = _cg_const_2[7];
  (void)LC;
  (void)out;
  return 0;
}
