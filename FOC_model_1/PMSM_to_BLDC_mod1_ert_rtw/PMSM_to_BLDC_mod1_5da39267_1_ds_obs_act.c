/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t25, NeDsMethodOutput *out)
{
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
    [12];
  real_T t1[12];
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated;
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated;
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated;
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated;
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated;
  real_T
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated;
  real_T Subsystem_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq;
  size_t t11;
  t1[0ULL] = t25->mU.mX[0ULL];
  t1[1ULL] = 0.0;
  t1[2ULL] = t25->mU.mX[1ULL];
  t1[3ULL] = 0.0;
  t1[4ULL] = t25->mU.mX[3ULL];
  t1[5ULL] = 0.0;
  t1[6ULL] = t25->mU.mX[4ULL];
  t1[7ULL] = 0.0;
  t1[8ULL] = t25->mU.mX[5ULL];
  t1[9ULL] = 0.0;
  t1[10ULL] = t25->mU.mX[6ULL];
  t1[11ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V[t11]
      = t1[t11];
  }

  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    = t25->mX.mX[6ULL] * (-t25->mX.mX[3ULL] + 48.0) * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    = t25->mX.mX[3ULL] * t25->mX.mX[6ULL] * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    = t25->mX.mX[7ULL] * (-t25->mX.mX[4ULL] + 48.0) * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    = t25->mX.mX[4ULL] * t25->mX.mX[7ULL] * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    = t25->mX.mX[8ULL] * (-t25->mX.mX[5ULL] + 48.0) * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    = t25->mX.mX[5ULL] * t25->mX.mX[8ULL] * 0.001;
  Subsystem_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq =
    t25->mX.mX[10ULL] * -0.05;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ACT.mX[t11] =
      Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ACT.mX[12ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[13ULL] = 0.0;
  out->mOBS_ACT.mX[14ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[15ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[16ULL] = 0.0;
  out->mOBS_ACT.mX[17ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[18ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[19ULL] = 0.0;
  out->mOBS_ACT.mX[20ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[21ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[22ULL] = 0.0;
  out->mOBS_ACT.mX[23ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[24ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[25ULL] = 0.0;
  out->mOBS_ACT.mX[26ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[27ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[28ULL] = 0.0;
  out->mOBS_ACT.mX[29ULL] = t25->mU.mX[6ULL];
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ACT.mX[t11 + 30ULL] = ((const _NeDynamicSystem*)(LC))->mField0[t11];
  }

  out->mOBS_ACT.mX[42ULL] = 0.0;
  out->mOBS_ACT.mX[43ULL] = 0.0;
  out->mOBS_ACT.mX[44ULL] = 0.0;
  out->mOBS_ACT.mX[45ULL] = 0.0;
  out->mOBS_ACT.mX[46ULL] = 0.0;
  out->mOBS_ACT.mX[47ULL] = 0.0;
  out->mOBS_ACT.mX[48ULL] = 0.0;
  out->mOBS_ACT.mX[49ULL] = 0.0;
  out->mOBS_ACT.mX[50ULL] = 0.0;
  out->mOBS_ACT.mX[51ULL] = 0.0;
  out->mOBS_ACT.mX[52ULL] = 0.0;
  out->mOBS_ACT.mX[53ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ACT.mX[t11 + 54ULL] =
      Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ACT.mX[66ULL] = 0.0;
  out->mOBS_ACT.mX[67ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[68ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[69ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[70ULL] = 48.0;
  out->mOBS_ACT.mX[71ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[72ULL] = 0.0;
  out->mOBS_ACT.mX[73ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[74ULL] = t25->mX.mX[6ULL];
  out->mOBS_ACT.mX[75ULL] = t25->mX.mX[6ULL];
  out->mOBS_ACT.mX[76ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[77ULL] = 48.0;
  out->mOBS_ACT.mX[78ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[79ULL] = -t25->mX.mX[3ULL] + 48.0;
  out->mOBS_ACT.mX[80ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[81ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[82ULL] = -t25->mX.mX[3ULL] + 48.0;
  out->mOBS_ACT.mX[83ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[84ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[85ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[86ULL] = 0.0;
  out->mOBS_ACT.mX[87ULL] = 0.0;
  out->mOBS_ACT.mX[88ULL] = t25->mX.mX[6ULL];
  out->mOBS_ACT.mX[89ULL] = t25->mX.mX[6ULL];
  out->mOBS_ACT.mX[90ULL] = 0.0;
  out->mOBS_ACT.mX[91ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[92ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[93ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[94ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[95ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[96ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[97ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[98ULL] = 48.0;
  out->mOBS_ACT.mX[99ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[100ULL] = 0.0;
  out->mOBS_ACT.mX[101ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[102ULL] = t25->mX.mX[7ULL];
  out->mOBS_ACT.mX[103ULL] = t25->mX.mX[7ULL];
  out->mOBS_ACT.mX[104ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[105ULL] = 48.0;
  out->mOBS_ACT.mX[106ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[107ULL] = -t25->mX.mX[4ULL] + 48.0;
  out->mOBS_ACT.mX[108ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[109ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[110ULL] = -t25->mX.mX[4ULL] + 48.0;
  out->mOBS_ACT.mX[111ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[112ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[113ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[114ULL] = 0.0;
  out->mOBS_ACT.mX[115ULL] = 0.0;
  out->mOBS_ACT.mX[116ULL] = t25->mX.mX[7ULL];
  out->mOBS_ACT.mX[117ULL] = t25->mX.mX[7ULL];
  out->mOBS_ACT.mX[118ULL] = 0.0;
  out->mOBS_ACT.mX[119ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[120ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[121ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[122ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[123ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[124ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[125ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[126ULL] = 48.0;
  out->mOBS_ACT.mX[127ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[128ULL] = 0.0;
  out->mOBS_ACT.mX[129ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[130ULL] = t25->mX.mX[8ULL];
  out->mOBS_ACT.mX[131ULL] = t25->mX.mX[8ULL];
  out->mOBS_ACT.mX[132ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[133ULL] = 48.0;
  out->mOBS_ACT.mX[134ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[135ULL] = -t25->mX.mX[5ULL] + 48.0;
  out->mOBS_ACT.mX[136ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[137ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[138ULL] = -t25->mX.mX[5ULL] + 48.0;
  out->mOBS_ACT.mX[139ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[140ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[141ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[142ULL] = 0.0;
  out->mOBS_ACT.mX[143ULL] = 0.0;
  out->mOBS_ACT.mX[144ULL] = t25->mX.mX[8ULL];
  out->mOBS_ACT.mX[145ULL] = t25->mX.mX[8ULL];
  out->mOBS_ACT.mX[146ULL] = 0.0;
  out->mOBS_ACT.mX[147ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[148ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[149ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[150ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[151ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mOBS_ACT.mX[152ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[153ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[154ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[155ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[156ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[157ULL] = 0.0;
  out->mOBS_ACT.mX[158ULL] = 48.0;
  out->mOBS_ACT.mX[159ULL] = 0.0;
  out->mOBS_ACT.mX[160ULL] = 0.0;
  out->mOBS_ACT.mX[161ULL] = 0.0;
  out->mOBS_ACT.mX[162ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[163ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[164ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[165ULL] = t25->mX.mX[3ULL];
  out->mOBS_ACT.mX[166ULL] = t25->mX.mX[4ULL];
  out->mOBS_ACT.mX[167ULL] = t25->mX.mX[5ULL];
  out->mOBS_ACT.mX[168ULL] = 0.0;
  out->mOBS_ACT.mX[169ULL] = 0.0;
  out->mOBS_ACT.mX[170ULL] = 0.0;
  out->mOBS_ACT.mX[171ULL] = ((-t25->mX.mX[6ULL] - t25->mX.mX[7ULL]) -
    t25->mX.mX[8ULL]) - t25->mX.mX[9ULL];
  out->mOBS_ACT.mX[172ULL] = 0.0;
  out->mOBS_ACT.mX[173ULL] = 48.0;
  out->mOBS_ACT.mX[174ULL] = 48.0;
  out->mOBS_ACT.mX[175ULL] = 0.0;
  out->mOBS_ACT.mX[176ULL] = t25->mX.mX[0ULL];
  out->mOBS_ACT.mX[177ULL] = t25->mX.mX[0ULL];
  out->mOBS_ACT.mX[178ULL] = t25->mX.mX[10ULL];
  out->mOBS_ACT.mX[179ULL] = t25->mX.mX[0ULL];
  out->mOBS_ACT.mX[180ULL] = 0.0;
  out->mOBS_ACT.mX[181ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[182ULL] = t25->mX.mX[2ULL];
  out->mOBS_ACT.mX[183ULL] = t25->mX.mX[0ULL] * 500.0;
  out->mOBS_ACT.mX[184ULL] = t25->mU.mX[2ULL];
  out->mOBS_ACT.mX[185ULL] = 0.0;
  out->mOBS_ACT.mX[186ULL] = 48.0;
  out->mOBS_ACT.mX[187ULL] = 0.0;
  out->mOBS_ACT.mX[188ULL] = 0.0;
  out->mOBS_ACT.mX[189ULL] = t25->mX.mX[11ULL];
  out->mOBS_ACT.mX[190ULL] = 0.0;
  out->mOBS_ACT.mX[191ULL] = t25->mX.mX[9ULL];
  out->mOBS_ACT.mX[192ULL] = t25->mX.mX[12ULL] * 1000.0;
  out->mOBS_ACT.mX[193ULL] = t25->mX.mX[10ULL] * -0.002;
  out->mOBS_ACT.mX[194ULL] = t25->mX.mX[13ULL];
  out->mOBS_ACT.mX[195ULL] = t25->mX.mX[13ULL];
  out->mOBS_ACT.mX[196ULL] = t25->mX.mX[14ULL];
  out->mOBS_ACT.mX[197ULL] = t25->mX.mX[1ULL];
  out->mOBS_ACT.mX[198ULL] = t25->mX.mX[9ULL] * -0.037 + 48.0;
  out->mOBS_ACT.mX[199ULL] = t25->mX.mX[2ULL] * 9.5492965855137211;
  out->mOBS_ACT.mX[200ULL] = t25->mX.mX[2ULL];
  out->mOBS_ACT.mX[201ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[202ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[203ULL] = t25->mU.mX[2ULL];
  out->mOBS_ACT.mX[204ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[205ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[206ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[207ULL] = t25->mU.mX[6ULL];
  out->mOBS_ACT.mX[208ULL] = 0.0;
  out->mOBS_ACT.mX[209ULL] = t25->mU.mX[0ULL];
  out->mOBS_ACT.mX[210ULL] = 0.0;
  out->mOBS_ACT.mX[211ULL] = t25->mU.mX[1ULL];
  out->mOBS_ACT.mX[212ULL] = 0.0;
  out->mOBS_ACT.mX[213ULL] = t25->mU.mX[3ULL];
  out->mOBS_ACT.mX[214ULL] = 0.0;
  out->mOBS_ACT.mX[215ULL] = t25->mU.mX[4ULL];
  out->mOBS_ACT.mX[216ULL] = 0.0;
  out->mOBS_ACT.mX[217ULL] = t25->mU.mX[5ULL];
  out->mOBS_ACT.mX[218ULL] = 0.0;
  out->mOBS_ACT.mX[219ULL] = t25->mU.mX[6ULL];
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ACT.mX[t11 + 220ULL] = -((const _NeDynamicSystem*)(LC))->
      mField0[t11];
  }

  out->mOBS_ACT.mX[232ULL] = 0.0;
  out->mOBS_ACT.mX[233ULL] = 0.0;
  out->mOBS_ACT.mX[234ULL] = 0.0;
  out->mOBS_ACT.mX[235ULL] = 0.0;
  for (t11 = 0ULL; t11 < 12ULL; t11++) {
    out->mOBS_ACT.mX[t11 + 236ULL] =
      Subsystem_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t11];
  }

  out->mOBS_ACT.mX[248ULL] = t25->mX.mX[0ULL] * 20.0;
  out->mOBS_ACT.mX[249ULL] = t25->mX.mX[0ULL];
  out->mOBS_ACT.mX[250ULL] = -t25->mX.mX[10ULL];
  out->mOBS_ACT.mX[251ULL] = t25->mX.mX[10ULL] * 0.05;
  out->mOBS_ACT.mX[252ULL] = t25->mX.mX[0ULL] * 20.0;
  out->mOBS_ACT.mX[253ULL] = 0.0;
  out->mOBS_ACT.mX[254ULL] = t25->mX.mX[0ULL] * 500.0;
  out->mOBS_ACT.mX[255ULL] = 300.0;
  out->mOBS_ACT.mX[256ULL] = 0.0;
  out->mOBS_ACT.mX[257ULL] = t25->mX.mX[0ULL] * 20.0;
  out->mOBS_ACT.mX[258ULL] = 0.0;
  out->mOBS_ACT.mX[259ULL] = t25->mX.mX[15ULL];
  out->mOBS_ACT.mX[260ULL] = 0.0;
  out->mOBS_ACT.mX[261ULL] = t25->mX.mX[0ULL] * 500.0;
  out->mOBS_ACT.mX[262ULL] = 0.0;
  out->mOBS_ACT.mX[263ULL] = t25->mX.mX[16ULL];
  out->mOBS_ACT.mX[264ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq;
  out->mOBS_ACT.mX[265ULL] =
    Subsystem_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq * -0.04;
  (void)LC;
  (void)out;
  return 0;
}
