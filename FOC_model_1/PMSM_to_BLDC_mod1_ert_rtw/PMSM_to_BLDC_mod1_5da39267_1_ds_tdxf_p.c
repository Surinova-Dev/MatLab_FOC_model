/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[39] = { 10, 15, 16, 1, 11, 2, 10, 12, 13, 14, 3, 4,
    5, 6, 7, 8, 3, 4, 5, 6, 7, 8, 12, 13, 0, 2, 9, 11, 12, 13, 13, 11, 14, 2, 11,
    12, 13, 15, 16 };

  static int32_T _cg_const_1[18] = { 0, 3, 5, 10, 12, 14, 16, 18, 20, 22, 24, 26,
    30, 31, 33, 37, 38, 39 };

  (void)t1;
  (void)LC;
  out->mTDXF_P.mNumCol = 17ULL;
  out->mTDXF_P.mNumRow = 17ULL;
  out->mTDXF_P.mJc[0] = _cg_const_1[0];
  out->mTDXF_P.mJc[1] = _cg_const_1[1];
  out->mTDXF_P.mJc[2] = _cg_const_1[2];
  out->mTDXF_P.mJc[3] = _cg_const_1[3];
  out->mTDXF_P.mJc[4] = _cg_const_1[4];
  out->mTDXF_P.mJc[5] = _cg_const_1[5];
  out->mTDXF_P.mJc[6] = _cg_const_1[6];
  out->mTDXF_P.mJc[7] = _cg_const_1[7];
  out->mTDXF_P.mJc[8] = _cg_const_1[8];
  out->mTDXF_P.mJc[9] = _cg_const_1[9];
  out->mTDXF_P.mJc[10] = _cg_const_1[10];
  out->mTDXF_P.mJc[11] = _cg_const_1[11];
  out->mTDXF_P.mJc[12] = _cg_const_1[12];
  out->mTDXF_P.mJc[13] = _cg_const_1[13];
  out->mTDXF_P.mJc[14] = _cg_const_1[14];
  out->mTDXF_P.mJc[15] = _cg_const_1[15];
  out->mTDXF_P.mJc[16] = _cg_const_1[16];
  out->mTDXF_P.mJc[17] = _cg_const_1[17];
  out->mTDXF_P.mIr[0] = _cg_const_2[0];
  out->mTDXF_P.mIr[1] = _cg_const_2[1];
  out->mTDXF_P.mIr[2] = _cg_const_2[2];
  out->mTDXF_P.mIr[3] = _cg_const_2[3];
  out->mTDXF_P.mIr[4] = _cg_const_2[4];
  out->mTDXF_P.mIr[5] = _cg_const_2[5];
  out->mTDXF_P.mIr[6] = _cg_const_2[6];
  out->mTDXF_P.mIr[7] = _cg_const_2[7];
  out->mTDXF_P.mIr[8] = _cg_const_2[8];
  out->mTDXF_P.mIr[9] = _cg_const_2[9];
  out->mTDXF_P.mIr[10] = _cg_const_2[10];
  out->mTDXF_P.mIr[11] = _cg_const_2[11];
  out->mTDXF_P.mIr[12] = _cg_const_2[12];
  out->mTDXF_P.mIr[13] = _cg_const_2[13];
  out->mTDXF_P.mIr[14] = _cg_const_2[14];
  out->mTDXF_P.mIr[15] = _cg_const_2[15];
  out->mTDXF_P.mIr[16] = _cg_const_2[16];
  out->mTDXF_P.mIr[17] = _cg_const_2[17];
  out->mTDXF_P.mIr[18] = _cg_const_2[18];
  out->mTDXF_P.mIr[19] = _cg_const_2[19];
  out->mTDXF_P.mIr[20] = _cg_const_2[20];
  out->mTDXF_P.mIr[21] = _cg_const_2[21];
  out->mTDXF_P.mIr[22] = _cg_const_2[22];
  out->mTDXF_P.mIr[23] = _cg_const_2[23];
  out->mTDXF_P.mIr[24] = _cg_const_2[24];
  out->mTDXF_P.mIr[25] = _cg_const_2[25];
  out->mTDXF_P.mIr[26] = _cg_const_2[26];
  out->mTDXF_P.mIr[27] = _cg_const_2[27];
  out->mTDXF_P.mIr[28] = _cg_const_2[28];
  out->mTDXF_P.mIr[29] = _cg_const_2[29];
  out->mTDXF_P.mIr[30] = _cg_const_2[30];
  out->mTDXF_P.mIr[31] = _cg_const_2[31];
  out->mTDXF_P.mIr[32] = _cg_const_2[32];
  out->mTDXF_P.mIr[33] = _cg_const_2[33];
  out->mTDXF_P.mIr[34] = _cg_const_2[34];
  out->mTDXF_P.mIr[35] = _cg_const_2[35];
  out->mTDXF_P.mIr[36] = _cg_const_2[36];
  out->mTDXF_P.mIr[37] = _cg_const_2[37];
  out->mTDXF_P.mIr[38] = _cg_const_2[38];
  (void)LC;
  (void)out;
  return 0;
}
