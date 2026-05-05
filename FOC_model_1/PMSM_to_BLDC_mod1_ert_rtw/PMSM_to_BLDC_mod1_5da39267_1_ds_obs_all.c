/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t23, NeDsMethodOutput *out)
{
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
    [12];
  real_T t1[12];
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated;
  real_T
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq;
  size_t t11;
  t1[0ULL] = t23->mU.mX[0ULL];
  t1[1ULL] = 0.0;
  t1[2ULL] = t23->mU.mX[1ULL];
  t1[3ULL] = 0.0;
  t1[4ULL] = t23->mU.mX[3ULL];
  t1[5ULL] = 0.0;
  t1[6ULL] = t23->mU.mX[4ULL];
  t1[7ULL] = 0.0;
  t1[8ULL] = t23->mU.mX[5ULL];
  t1[9ULL] = 0.0;
  t1[10ULL] = t23->mU.mX[6ULL];
  t1[11ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11] = t1[t11];
  }

  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    = t23->mX.mX[6ULL] * (-t23->mX.mX[3ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    = t23->mX.mX[3ULL] * t23->mX.mX[6ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    = t23->mX.mX[7ULL] * (-t23->mX.mX[4ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    = t23->mX.mX[4ULL] * t23->mX.mX[7ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    = t23->mX.mX[8ULL] * (-t23->mX.mX[5ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    = t23->mX.mX[5ULL] * t23->mX.mX[8ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq =
    t23->mX.mX[10ULL] * -0.05;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ALL.mX[t11] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ALL.mX[12ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[13ULL] = 0.0;
  out->mOBS_ALL.mX[14ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[15ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[16ULL] = 0.0;
  out->mOBS_ALL.mX[17ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[18ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[19ULL] = 0.0;
  out->mOBS_ALL.mX[20ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[21ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[22ULL] = 0.0;
  out->mOBS_ALL.mX[23ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[24ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[25ULL] = 0.0;
  out->mOBS_ALL.mX[26ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[27ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[28ULL] = 0.0;
  out->mOBS_ALL.mX[29ULL] = t23->mU.mX[6ULL];
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ALL.mX[t11 + 30ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t11];
  }

  out->mOBS_ALL.mX[42ULL] = 0.0;
  out->mOBS_ALL.mX[43ULL] = 0.0;
  out->mOBS_ALL.mX[44ULL] = 0.0;
  out->mOBS_ALL.mX[45ULL] = 0.0;
  out->mOBS_ALL.mX[46ULL] = 0.0;
  out->mOBS_ALL.mX[47ULL] = 0.0;
  out->mOBS_ALL.mX[48ULL] = 0.0;
  out->mOBS_ALL.mX[49ULL] = 0.0;
  out->mOBS_ALL.mX[50ULL] = 0.0;
  out->mOBS_ALL.mX[51ULL] = 0.0;
  out->mOBS_ALL.mX[52ULL] = 0.0;
  out->mOBS_ALL.mX[53ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ALL.mX[t11 + 54ULL] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ALL.mX[66ULL] = 0.0;
  out->mOBS_ALL.mX[67ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[68ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[69ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[70ULL] = 48.0;
  out->mOBS_ALL.mX[71ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[72ULL] = 0.0;
  out->mOBS_ALL.mX[73ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[74ULL] = t23->mX.mX[6ULL];
  out->mOBS_ALL.mX[75ULL] = t23->mX.mX[6ULL];
  out->mOBS_ALL.mX[76ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[77ULL] = 48.0;
  out->mOBS_ALL.mX[78ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[79ULL] = -t23->mX.mX[3ULL] + 48.0;
  out->mOBS_ALL.mX[80ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[81ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[82ULL] = -t23->mX.mX[3ULL] + 48.0;
  out->mOBS_ALL.mX[83ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[84ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[85ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[86ULL] = 0.0;
  out->mOBS_ALL.mX[87ULL] = 0.0;
  out->mOBS_ALL.mX[88ULL] = t23->mX.mX[6ULL];
  out->mOBS_ALL.mX[89ULL] = t23->mX.mX[6ULL];
  out->mOBS_ALL.mX[90ULL] = 0.0;
  out->mOBS_ALL.mX[91ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[92ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[93ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[94ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[95ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[96ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[97ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[98ULL] = 48.0;
  out->mOBS_ALL.mX[99ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[100ULL] = 0.0;
  out->mOBS_ALL.mX[101ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[102ULL] = t23->mX.mX[7ULL];
  out->mOBS_ALL.mX[103ULL] = t23->mX.mX[7ULL];
  out->mOBS_ALL.mX[104ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[105ULL] = 48.0;
  out->mOBS_ALL.mX[106ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[107ULL] = -t23->mX.mX[4ULL] + 48.0;
  out->mOBS_ALL.mX[108ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[109ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[110ULL] = -t23->mX.mX[4ULL] + 48.0;
  out->mOBS_ALL.mX[111ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[112ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[113ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[114ULL] = 0.0;
  out->mOBS_ALL.mX[115ULL] = 0.0;
  out->mOBS_ALL.mX[116ULL] = t23->mX.mX[7ULL];
  out->mOBS_ALL.mX[117ULL] = t23->mX.mX[7ULL];
  out->mOBS_ALL.mX[118ULL] = 0.0;
  out->mOBS_ALL.mX[119ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[120ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[121ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[122ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[123ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[124ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[125ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[126ULL] = 48.0;
  out->mOBS_ALL.mX[127ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[128ULL] = 0.0;
  out->mOBS_ALL.mX[129ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[130ULL] = t23->mX.mX[8ULL];
  out->mOBS_ALL.mX[131ULL] = t23->mX.mX[8ULL];
  out->mOBS_ALL.mX[132ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[133ULL] = 48.0;
  out->mOBS_ALL.mX[134ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[135ULL] = -t23->mX.mX[5ULL] + 48.0;
  out->mOBS_ALL.mX[136ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[137ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[138ULL] = -t23->mX.mX[5ULL] + 48.0;
  out->mOBS_ALL.mX[139ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[140ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[141ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[142ULL] = 0.0;
  out->mOBS_ALL.mX[143ULL] = 0.0;
  out->mOBS_ALL.mX[144ULL] = t23->mX.mX[8ULL];
  out->mOBS_ALL.mX[145ULL] = t23->mX.mX[8ULL];
  out->mOBS_ALL.mX[146ULL] = 0.0;
  out->mOBS_ALL.mX[147ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[148ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[149ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[150ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[151ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ALL.mX[152ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[153ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[154ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[155ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[156ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[157ULL] = 0.0;
  out->mOBS_ALL.mX[158ULL] = 48.0;
  out->mOBS_ALL.mX[159ULL] = 0.0;
  out->mOBS_ALL.mX[160ULL] = 0.0;
  out->mOBS_ALL.mX[161ULL] = 0.0;
  out->mOBS_ALL.mX[162ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[163ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[164ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[165ULL] = t23->mX.mX[3ULL];
  out->mOBS_ALL.mX[166ULL] = t23->mX.mX[4ULL];
  out->mOBS_ALL.mX[167ULL] = t23->mX.mX[5ULL];
  out->mOBS_ALL.mX[168ULL] = 0.0;
  out->mOBS_ALL.mX[169ULL] = 0.0;
  out->mOBS_ALL.mX[170ULL] = 0.0;
  out->mOBS_ALL.mX[171ULL] = ((-t23->mX.mX[6ULL] - t23->mX.mX[7ULL]) -
    t23->mX.mX[8ULL]) - t23->mX.mX[9ULL];
  out->mOBS_ALL.mX[172ULL] = 0.0;
  out->mOBS_ALL.mX[173ULL] = 48.0;
  out->mOBS_ALL.mX[174ULL] = 48.0;
  out->mOBS_ALL.mX[175ULL] = 0.0;
  out->mOBS_ALL.mX[176ULL] = t23->mX.mX[0ULL];
  out->mOBS_ALL.mX[177ULL] = t23->mX.mX[0ULL];
  out->mOBS_ALL.mX[178ULL] = t23->mX.mX[10ULL];
  out->mOBS_ALL.mX[179ULL] = t23->mX.mX[0ULL];
  out->mOBS_ALL.mX[180ULL] = 0.0;
  out->mOBS_ALL.mX[181ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[182ULL] = t23->mX.mX[2ULL];
  out->mOBS_ALL.mX[183ULL] = t23->mX.mX[0ULL] * 500.0;
  out->mOBS_ALL.mX[184ULL] = t23->mU.mX[2ULL];
  out->mOBS_ALL.mX[185ULL] = 0.0;
  out->mOBS_ALL.mX[186ULL] = 48.0;
  out->mOBS_ALL.mX[187ULL] = 0.0;
  out->mOBS_ALL.mX[188ULL] = 0.0;
  out->mOBS_ALL.mX[189ULL] = t23->mX.mX[11ULL];
  out->mOBS_ALL.mX[190ULL] = 0.0;
  out->mOBS_ALL.mX[191ULL] = t23->mX.mX[9ULL];
  out->mOBS_ALL.mX[192ULL] = t23->mX.mX[12ULL] * 1000.0;
  out->mOBS_ALL.mX[193ULL] = t23->mX.mX[10ULL] * -0.002;
  out->mOBS_ALL.mX[194ULL] = t23->mX.mX[13ULL];
  out->mOBS_ALL.mX[195ULL] = t23->mX.mX[13ULL];
  out->mOBS_ALL.mX[196ULL] = t23->mX.mX[14ULL];
  out->mOBS_ALL.mX[197ULL] = t23->mX.mX[1ULL];
  out->mOBS_ALL.mX[198ULL] = t23->mX.mX[9ULL] * -0.037 + 48.0;
  out->mOBS_ALL.mX[199ULL] = t23->mX.mX[2ULL] * 9.5492965855137211;
  out->mOBS_ALL.mX[200ULL] = t23->mX.mX[2ULL];
  out->mOBS_ALL.mX[201ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[202ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[203ULL] = t23->mU.mX[2ULL];
  out->mOBS_ALL.mX[204ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[205ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[206ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[207ULL] = t23->mU.mX[6ULL];
  out->mOBS_ALL.mX[208ULL] = 0.0;
  out->mOBS_ALL.mX[209ULL] = t23->mU.mX[0ULL];
  out->mOBS_ALL.mX[210ULL] = 0.0;
  out->mOBS_ALL.mX[211ULL] = t23->mU.mX[1ULL];
  out->mOBS_ALL.mX[212ULL] = 0.0;
  out->mOBS_ALL.mX[213ULL] = t23->mU.mX[3ULL];
  out->mOBS_ALL.mX[214ULL] = 0.0;
  out->mOBS_ALL.mX[215ULL] = t23->mU.mX[4ULL];
  out->mOBS_ALL.mX[216ULL] = 0.0;
  out->mOBS_ALL.mX[217ULL] = t23->mU.mX[5ULL];
  out->mOBS_ALL.mX[218ULL] = 0.0;
  out->mOBS_ALL.mX[219ULL] = t23->mU.mX[6ULL];
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ALL.mX[t11 + 220ULL] = -((const _NeDynamicSystem*)(LC))->
      mField0[t11];
  }

  out->mOBS_ALL.mX[232ULL] = 0.0;
  out->mOBS_ALL.mX[233ULL] = 0.0;
  out->mOBS_ALL.mX[234ULL] = 0.0;
  out->mOBS_ALL.mX[235ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ALL.mX[t11 + 236ULL] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ALL.mX[248ULL] = t23->mX.mX[0ULL] * 20.0;
  out->mOBS_ALL.mX[249ULL] = t23->mX.mX[0ULL];
  out->mOBS_ALL.mX[250ULL] = -t23->mX.mX[10ULL];
  out->mOBS_ALL.mX[251ULL] = t23->mX.mX[10ULL] * 0.05;
  out->mOBS_ALL.mX[252ULL] = t23->mX.mX[0ULL] * 20.0;
  out->mOBS_ALL.mX[253ULL] = 0.0;
  out->mOBS_ALL.mX[254ULL] = t23->mX.mX[0ULL] * 500.0;
  out->mOBS_ALL.mX[255ULL] = 300.0;
  out->mOBS_ALL.mX[256ULL] = 0.0;
  out->mOBS_ALL.mX[257ULL] = t23->mX.mX[0ULL] * 20.0;
  out->mOBS_ALL.mX[258ULL] = 0.0;
  out->mOBS_ALL.mX[259ULL] = t23->mX.mX[15ULL];
  out->mOBS_ALL.mX[260ULL] = 0.0;
  out->mOBS_ALL.mX[261ULL] = t23->mX.mX[0ULL] * 500.0;
  out->mOBS_ALL.mX[262ULL] = 0.0;
  out->mOBS_ALL.mX[263ULL] = t23->mX.mX[16ULL];
  out->mOBS_ALL.mX[264ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq;
  out->mOBS_ALL.mX[265ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq *
    -0.04;
  (void)LC;
  (void)out;
  return 0;
}
