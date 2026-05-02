/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t10, NeDsMethodOutput *out)
{
  size_t t7;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mOBS_EXP.mX[t7] = ((const _NeDynamicSystem*)(LC))->mField0[t7];
  }

  out->mOBS_EXP.mX[12ULL] = 0.0;
  out->mOBS_EXP.mX[13ULL] = 0.0;
  out->mOBS_EXP.mX[14ULL] = 0.0;
  out->mOBS_EXP.mX[15ULL] = 0.0;
  out->mOBS_EXP.mX[16ULL] = 0.0;
  out->mOBS_EXP.mX[17ULL] = 0.0;
  out->mOBS_EXP.mX[18ULL] = 0.0;
  out->mOBS_EXP.mX[19ULL] = 0.0;
  out->mOBS_EXP.mX[20ULL] = 0.0;
  out->mOBS_EXP.mX[21ULL] = 0.0;
  out->mOBS_EXP.mX[22ULL] = 0.0;
  out->mOBS_EXP.mX[23ULL] = 0.0;
  out->mOBS_EXP.mX[24ULL] = 0.0;
  out->mOBS_EXP.mX[25ULL] = 0.0;
  out->mOBS_EXP.mX[26ULL] = 0.0;
  out->mOBS_EXP.mX[27ULL] = 0.0;
  out->mOBS_EXP.mX[28ULL] = 0.0;
  out->mOBS_EXP.mX[29ULL] = 0.0;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mOBS_EXP.mX[t7 + 30ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t7];
  }

  out->mOBS_EXP.mX[42ULL] = 0.0;
  out->mOBS_EXP.mX[43ULL] = 0.0;
  out->mOBS_EXP.mX[44ULL] = 0.0;
  out->mOBS_EXP.mX[45ULL] = 0.0;
  out->mOBS_EXP.mX[46ULL] = 0.0;
  out->mOBS_EXP.mX[47ULL] = 0.0;
  out->mOBS_EXP.mX[48ULL] = 0.0;
  out->mOBS_EXP.mX[49ULL] = 0.0;
  out->mOBS_EXP.mX[50ULL] = 0.0;
  out->mOBS_EXP.mX[51ULL] = 0.0;
  out->mOBS_EXP.mX[52ULL] = 0.0;
  out->mOBS_EXP.mX[53ULL] = 0.0;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mOBS_EXP.mX[t7 + 54ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t7];
  }

  out->mOBS_EXP.mX[66ULL] = 293.15;
  out->mOBS_EXP.mX[67ULL] = 0.0;
  out->mOBS_EXP.mX[68ULL] = 0.0;
  out->mOBS_EXP.mX[69ULL] = 0.0;
  out->mOBS_EXP.mX[70ULL] = 0.0;
  out->mOBS_EXP.mX[71ULL] = 0.0;
  out->mOBS_EXP.mX[72ULL] = 0.0;
  out->mOBS_EXP.mX[73ULL] = 0.0;
  out->mOBS_EXP.mX[74ULL] = 0.0;
  out->mOBS_EXP.mX[75ULL] = 0.0;
  out->mOBS_EXP.mX[76ULL] = 0.0;
  out->mOBS_EXP.mX[77ULL] = 0.0;
  out->mOBS_EXP.mX[78ULL] = 0.0;
  out->mOBS_EXP.mX[79ULL] = 0.0;
  out->mOBS_EXP.mX[80ULL] = 0.0;
  out->mOBS_EXP.mX[81ULL] = 0.0;
  out->mOBS_EXP.mX[82ULL] = 0.0;
  out->mOBS_EXP.mX[83ULL] = 0.0;
  out->mOBS_EXP.mX[84ULL] = 0.0;
  out->mOBS_EXP.mX[85ULL] = 0.0;
  out->mOBS_EXP.mX[86ULL] = 0.0;
  out->mOBS_EXP.mX[87ULL] = 0.0;
  out->mOBS_EXP.mX[88ULL] = 0.0;
  out->mOBS_EXP.mX[89ULL] = 0.0;
  out->mOBS_EXP.mX[90ULL] = 0.0;
  out->mOBS_EXP.mX[91ULL] = 0.0;
  out->mOBS_EXP.mX[92ULL] = 0.0;
  out->mOBS_EXP.mX[93ULL] = 0.0;
  out->mOBS_EXP.mX[94ULL] = 0.0;
  out->mOBS_EXP.mX[95ULL] = 0.0;
  out->mOBS_EXP.mX[96ULL] = 0.0;
  out->mOBS_EXP.mX[97ULL] = 0.0;
  out->mOBS_EXP.mX[98ULL] = 0.0;
  out->mOBS_EXP.mX[99ULL] = 0.0;
  out->mOBS_EXP.mX[100ULL] = 0.0;
  out->mOBS_EXP.mX[101ULL] = 0.0;
  out->mOBS_EXP.mX[102ULL] = 0.0;
  out->mOBS_EXP.mX[103ULL] = 0.0;
  out->mOBS_EXP.mX[104ULL] = 0.0;
  out->mOBS_EXP.mX[105ULL] = 0.0;
  out->mOBS_EXP.mX[106ULL] = 0.0;
  out->mOBS_EXP.mX[107ULL] = 0.0;
  out->mOBS_EXP.mX[108ULL] = 0.0;
  out->mOBS_EXP.mX[109ULL] = 0.0;
  out->mOBS_EXP.mX[110ULL] = 0.0;
  out->mOBS_EXP.mX[111ULL] = 0.0;
  out->mOBS_EXP.mX[112ULL] = 0.0;
  out->mOBS_EXP.mX[113ULL] = 0.0;
  out->mOBS_EXP.mX[114ULL] = 0.0;
  out->mOBS_EXP.mX[115ULL] = 0.0;
  out->mOBS_EXP.mX[116ULL] = 0.0;
  out->mOBS_EXP.mX[117ULL] = 0.0;
  out->mOBS_EXP.mX[118ULL] = 0.0;
  out->mOBS_EXP.mX[119ULL] = 0.0;
  out->mOBS_EXP.mX[120ULL] = 0.0;
  out->mOBS_EXP.mX[121ULL] = 0.0;
  out->mOBS_EXP.mX[122ULL] = 0.0;
  out->mOBS_EXP.mX[123ULL] = 0.0;
  out->mOBS_EXP.mX[124ULL] = 0.0;
  out->mOBS_EXP.mX[125ULL] = 0.0;
  out->mOBS_EXP.mX[126ULL] = 0.0;
  out->mOBS_EXP.mX[127ULL] = 0.0;
  out->mOBS_EXP.mX[128ULL] = 0.0;
  out->mOBS_EXP.mX[129ULL] = 0.0;
  out->mOBS_EXP.mX[130ULL] = 0.0;
  out->mOBS_EXP.mX[131ULL] = 0.0;
  out->mOBS_EXP.mX[132ULL] = 0.0;
  out->mOBS_EXP.mX[133ULL] = 0.0;
  out->mOBS_EXP.mX[134ULL] = 0.0;
  out->mOBS_EXP.mX[135ULL] = 0.0;
  out->mOBS_EXP.mX[136ULL] = 0.0;
  out->mOBS_EXP.mX[137ULL] = 0.0;
  out->mOBS_EXP.mX[138ULL] = 0.0;
  out->mOBS_EXP.mX[139ULL] = 0.0;
  out->mOBS_EXP.mX[140ULL] = 0.0;
  out->mOBS_EXP.mX[141ULL] = 0.0;
  out->mOBS_EXP.mX[142ULL] = 0.0;
  out->mOBS_EXP.mX[143ULL] = 0.0;
  out->mOBS_EXP.mX[144ULL] = 0.0;
  out->mOBS_EXP.mX[145ULL] = 0.0;
  out->mOBS_EXP.mX[146ULL] = 0.0;
  out->mOBS_EXP.mX[147ULL] = 0.0;
  out->mOBS_EXP.mX[148ULL] = 0.0;
  out->mOBS_EXP.mX[149ULL] = 0.0;
  out->mOBS_EXP.mX[150ULL] = 0.0;
  out->mOBS_EXP.mX[151ULL] = 0.0;
  out->mOBS_EXP.mX[152ULL] = 0.0;
  out->mOBS_EXP.mX[153ULL] = 0.0;
  out->mOBS_EXP.mX[154ULL] = 0.0;
  out->mOBS_EXP.mX[155ULL] = 0.0;
  out->mOBS_EXP.mX[156ULL] = 0.0;
  out->mOBS_EXP.mX[157ULL] = 0.0;
  out->mOBS_EXP.mX[158ULL] = 0.0;
  out->mOBS_EXP.mX[159ULL] = 0.0;
  out->mOBS_EXP.mX[160ULL] = 0.0;
  out->mOBS_EXP.mX[161ULL] = 0.0;
  out->mOBS_EXP.mX[162ULL] = 0.0;
  out->mOBS_EXP.mX[163ULL] = 0.0;
  out->mOBS_EXP.mX[164ULL] = 0.0;
  out->mOBS_EXP.mX[165ULL] = 0.0;
  out->mOBS_EXP.mX[166ULL] = 0.0;
  out->mOBS_EXP.mX[167ULL] = 0.0;
  out->mOBS_EXP.mX[168ULL] = 0.0;
  out->mOBS_EXP.mX[169ULL] = 0.0;
  out->mOBS_EXP.mX[170ULL] = 0.0;
  out->mOBS_EXP.mX[171ULL] = 0.0;
  out->mOBS_EXP.mX[172ULL] = 0.0;
  out->mOBS_EXP.mX[173ULL] = 0.0;
  out->mOBS_EXP.mX[174ULL] = 0.0;
  out->mOBS_EXP.mX[175ULL] = 0.0;
  out->mOBS_EXP.mX[176ULL] = 0.0;
  out->mOBS_EXP.mX[177ULL] = 0.0;
  out->mOBS_EXP.mX[178ULL] = 0.0;
  out->mOBS_EXP.mX[179ULL] = t10->mP_R.mX[0ULL];
  out->mOBS_EXP.mX[180ULL] = 0.0;
  out->mOBS_EXP.mX[181ULL] = 0.0;
  out->mOBS_EXP.mX[182ULL] = 0.0;
  out->mOBS_EXP.mX[183ULL] = 0.0;
  out->mOBS_EXP.mX[184ULL] = 0.0;
  out->mOBS_EXP.mX[185ULL] = 0.0;
  out->mOBS_EXP.mX[186ULL] = 0.0;
  out->mOBS_EXP.mX[187ULL] = 0.0;
  out->mOBS_EXP.mX[188ULL] = 0.0;
  out->mOBS_EXP.mX[189ULL] = 0.0;
  out->mOBS_EXP.mX[190ULL] = 0.0;
  out->mOBS_EXP.mX[191ULL] = 0.0;
  out->mOBS_EXP.mX[192ULL] = 0.0;
  out->mOBS_EXP.mX[193ULL] = 0.0;
  out->mOBS_EXP.mX[194ULL] = 0.0;
  out->mOBS_EXP.mX[195ULL] = 0.0;
  out->mOBS_EXP.mX[196ULL] = 0.0;
  out->mOBS_EXP.mX[197ULL] = 0.0;
  out->mOBS_EXP.mX[198ULL] = 0.0;
  out->mOBS_EXP.mX[199ULL] = 0.0;
  out->mOBS_EXP.mX[200ULL] = 0.0;
  out->mOBS_EXP.mX[201ULL] = 0.0;
  out->mOBS_EXP.mX[202ULL] = 0.0;
  out->mOBS_EXP.mX[203ULL] = 0.0;
  out->mOBS_EXP.mX[204ULL] = 0.0;
  out->mOBS_EXP.mX[205ULL] = 0.0;
  out->mOBS_EXP.mX[206ULL] = 0.0;
  out->mOBS_EXP.mX[207ULL] = 0.0;
  out->mOBS_EXP.mX[208ULL] = 0.0;
  out->mOBS_EXP.mX[209ULL] = 0.0;
  out->mOBS_EXP.mX[210ULL] = 0.0;
  out->mOBS_EXP.mX[211ULL] = 0.0;
  out->mOBS_EXP.mX[212ULL] = 0.0;
  out->mOBS_EXP.mX[213ULL] = 0.0;
  out->mOBS_EXP.mX[214ULL] = 0.0;
  out->mOBS_EXP.mX[215ULL] = 0.0;
  out->mOBS_EXP.mX[216ULL] = 0.0;
  out->mOBS_EXP.mX[217ULL] = 0.0;
  out->mOBS_EXP.mX[218ULL] = 0.0;
  out->mOBS_EXP.mX[219ULL] = 0.0;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mOBS_EXP.mX[t7 + 220ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t7];
  }

  out->mOBS_EXP.mX[232ULL] = 0.0;
  out->mOBS_EXP.mX[233ULL] = 0.0;
  out->mOBS_EXP.mX[234ULL] = 0.0;
  out->mOBS_EXP.mX[235ULL] = 0.0;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mOBS_EXP.mX[t7 + 236ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t7];
  }

  out->mOBS_EXP.mX[248ULL] = 0.0;
  out->mOBS_EXP.mX[249ULL] = 0.0;
  out->mOBS_EXP.mX[250ULL] = 0.0;
  out->mOBS_EXP.mX[251ULL] = 0.0;
  out->mOBS_EXP.mX[252ULL] = 0.0;
  out->mOBS_EXP.mX[253ULL] = 293.15;
  out->mOBS_EXP.mX[254ULL] = 0.0;
  out->mOBS_EXP.mX[255ULL] = 300.0;
  out->mOBS_EXP.mX[256ULL] = 0.0;
  out->mOBS_EXP.mX[257ULL] = 0.0;
  out->mOBS_EXP.mX[258ULL] = 0.0;
  out->mOBS_EXP.mX[259ULL] = 0.0;
  out->mOBS_EXP.mX[260ULL] = 0.0;
  out->mOBS_EXP.mX[261ULL] = 0.0;
  out->mOBS_EXP.mX[262ULL] = 0.0;
  out->mOBS_EXP.mX[263ULL] = 0.0;
  out->mOBS_EXP.mX[264ULL] = 0.0;
  out->mOBS_EXP.mX[265ULL] = 0.0;
  (void)LC;
  (void)out;
  return 0;
}
