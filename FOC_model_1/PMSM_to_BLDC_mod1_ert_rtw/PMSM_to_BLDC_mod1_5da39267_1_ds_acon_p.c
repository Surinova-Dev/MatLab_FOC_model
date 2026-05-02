/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[18] = { 0, 3, 4, 6, 6, 6, 6, 6, 6, 6, 6, 8, 9, 9, 9,
    10, 11, 12 };

  static int32_T _cg_const_2[12] = { 10, 15, 16, 1, 2, 10, 0, 2, 9, 2, 15, 16 };

  (void)t1;
  (void)LC;
  out->mACON_P.mNumCol = 17ULL;
  out->mACON_P.mNumRow = 17ULL;
  out->mACON_P.mJc[0] = _cg_const_1[0];
  out->mACON_P.mJc[1] = _cg_const_1[1];
  out->mACON_P.mJc[2] = _cg_const_1[2];
  out->mACON_P.mJc[3] = _cg_const_1[3];
  out->mACON_P.mJc[4] = _cg_const_1[4];
  out->mACON_P.mJc[5] = _cg_const_1[5];
  out->mACON_P.mJc[6] = _cg_const_1[6];
  out->mACON_P.mJc[7] = _cg_const_1[7];
  out->mACON_P.mJc[8] = _cg_const_1[8];
  out->mACON_P.mJc[9] = _cg_const_1[9];
  out->mACON_P.mJc[10] = _cg_const_1[10];
  out->mACON_P.mJc[11] = _cg_const_1[11];
  out->mACON_P.mJc[12] = _cg_const_1[12];
  out->mACON_P.mJc[13] = _cg_const_1[13];
  out->mACON_P.mJc[14] = _cg_const_1[14];
  out->mACON_P.mJc[15] = _cg_const_1[15];
  out->mACON_P.mJc[16] = _cg_const_1[16];
  out->mACON_P.mJc[17] = _cg_const_1[17];
  out->mACON_P.mIr[0] = _cg_const_2[0];
  out->mACON_P.mIr[1] = _cg_const_2[1];
  out->mACON_P.mIr[2] = _cg_const_2[2];
  out->mACON_P.mIr[3] = _cg_const_2[3];
  out->mACON_P.mIr[4] = _cg_const_2[4];
  out->mACON_P.mIr[5] = _cg_const_2[5];
  out->mACON_P.mIr[6] = _cg_const_2[6];
  out->mACON_P.mIr[7] = _cg_const_2[7];
  out->mACON_P.mIr[8] = _cg_const_2[8];
  out->mACON_P.mIr[9] = _cg_const_2[9];
  out->mACON_P.mIr[10] = _cg_const_2[10];
  out->mACON_P.mIr[11] = _cg_const_2[11];
  (void)LC;
  (void)out;
  return 0;
}
