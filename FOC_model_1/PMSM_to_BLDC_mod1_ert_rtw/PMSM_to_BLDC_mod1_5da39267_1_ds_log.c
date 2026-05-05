/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'.
 */

#include "ne_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_sys_struct.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_log.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_externals.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T PMSM_to_BLDC_mod1_5da39267_1_ds_log(const NeDynamicSystem *LC, const
  NeDynamicSystemInput *t19, NeDsMethodOutput *out)
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
  size_t t7;
  (void)LC;
  t1[0ULL] = t19->mU.mX[0ULL];
  t1[1ULL] = 0.0;
  t1[2ULL] = t19->mU.mX[1ULL];
  t1[3ULL] = 0.0;
  t1[4ULL] = t19->mU.mX[3ULL];
  t1[5ULL] = 0.0;
  t1[6ULL] = t19->mU.mX[4ULL];
  t1[7ULL] = 0.0;
  t1[8ULL] = t19->mU.mX[5ULL];
  t1[9ULL] = 0.0;
  t1[10ULL] = t19->mU.mX[6ULL];
  t1[11ULL] = 0.0;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t7] = t1[t7];
  }

  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    = t19->mX.mX[6ULL] * (-t19->mX.mX[3ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    = t19->mX.mX[3ULL] * t19->mX.mX[6ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    = t19->mX.mX[7ULL] * (-t19->mX.mX[4ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    = t19->mX.mX[4ULL] * t19->mX.mX[7ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    = t19->mX.mX[8ULL] * (-t19->mX.mX[5ULL] + 48.0) * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    = t19->mX.mX[5ULL] * t19->mX.mX[8ULL] * 0.001;
  Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq =
    t19->mX.mX[10ULL] * -0.05;
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mLOG.mX[t7] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t7];
  }

  out->mLOG.mX[12ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[13ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[14ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[15ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[16ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[17ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[18ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[19ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[20ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[21ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[22ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[23ULL] = t19->mU.mX[6ULL];
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mLOG.mX[t7 + 24ULL] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t7];
  }

  out->mLOG.mX[36ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[37ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[38ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[39ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[40ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[41ULL] = t19->mX.mX[6ULL];
  out->mLOG.mX[42ULL] = t19->mX.mX[6ULL];
  out->mLOG.mX[43ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[44ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[45ULL] = -t19->mX.mX[3ULL] + 48.0;
  out->mLOG.mX[46ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[47ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q1_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[48ULL] = -t19->mX.mX[3ULL] + 48.0;
  out->mLOG.mX[49ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[50ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[51ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[52ULL] = t19->mX.mX[6ULL];
  out->mLOG.mX[53ULL] = t19->mX.mX[6ULL];
  out->mLOG.mX[54ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[55ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[56ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[57ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[58ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q2_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[59ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[60ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[61ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[62ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[63ULL] = t19->mX.mX[7ULL];
  out->mLOG.mX[64ULL] = t19->mX.mX[7ULL];
  out->mLOG.mX[65ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[66ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[67ULL] = -t19->mX.mX[4ULL] + 48.0;
  out->mLOG.mX[68ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[69ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q3_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[70ULL] = -t19->mX.mX[4ULL] + 48.0;
  out->mLOG.mX[71ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[72ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[73ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[74ULL] = t19->mX.mX[7ULL];
  out->mLOG.mX[75ULL] = t19->mX.mX[7ULL];
  out->mLOG.mX[76ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[77ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[78ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[79ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[80ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q4_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[81ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[82ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[83ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[84ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[85ULL] = t19->mX.mX[8ULL];
  out->mLOG.mX[86ULL] = t19->mX.mX[8ULL];
  out->mLOG.mX[87ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[88ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[89ULL] = -t19->mX.mX[5ULL] + 48.0;
  out->mLOG.mX[90ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[91ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q5_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[92ULL] = -t19->mX.mX[5ULL] + 48.0;
  out->mLOG.mX[93ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[94ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[95ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[96ULL] = t19->mX.mX[8ULL];
  out->mLOG.mX[97ULL] = t19->mX.mX[8ULL];
  out->mLOG.mX[98ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[99ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[100ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[101ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[102ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_Q6_ideal_switch_power_dissipated
    * 1000.0;
  out->mLOG.mX[103ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[104ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[105ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[106ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[107ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[108ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[109ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[110ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[111ULL] = t19->mX.mX[3ULL];
  out->mLOG.mX[112ULL] = t19->mX.mX[4ULL];
  out->mLOG.mX[113ULL] = t19->mX.mX[5ULL];
  out->mLOG.mX[114ULL] = ((-t19->mX.mX[6ULL] - t19->mX.mX[7ULL]) - t19->mX.mX
    [8ULL]) - t19->mX.mX[9ULL];
  out->mLOG.mX[115ULL] = t19->mX.mX[0ULL];
  out->mLOG.mX[116ULL] = t19->mX.mX[0ULL];
  out->mLOG.mX[117ULL] = t19->mX.mX[10ULL];
  out->mLOG.mX[118ULL] = t19->mX.mX[0ULL];
  out->mLOG.mX[119ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[120ULL] = t19->mX.mX[2ULL];
  out->mLOG.mX[121ULL] = t19->mX.mX[0ULL] * 500.0;
  out->mLOG.mX[122ULL] = t19->mU.mX[2ULL];
  out->mLOG.mX[123ULL] = t19->mX.mX[11ULL];
  out->mLOG.mX[124ULL] = t19->mX.mX[9ULL];
  out->mLOG.mX[125ULL] = t19->mX.mX[12ULL] * 1000.0;
  out->mLOG.mX[126ULL] = t19->mX.mX[10ULL] * -0.002;
  out->mLOG.mX[127ULL] = t19->mX.mX[13ULL];
  out->mLOG.mX[128ULL] = t19->mX.mX[13ULL];
  out->mLOG.mX[129ULL] = t19->mX.mX[14ULL];
  out->mLOG.mX[130ULL] = t19->mX.mX[1ULL];
  out->mLOG.mX[131ULL] = t19->mX.mX[9ULL] * -0.037 + 48.0;
  out->mLOG.mX[132ULL] = t19->mX.mX[2ULL] * 9.5492965855137211;
  out->mLOG.mX[133ULL] = t19->mX.mX[2ULL];
  out->mLOG.mX[134ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[135ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[136ULL] = t19->mU.mX[2ULL];
  out->mLOG.mX[137ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[138ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[139ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[140ULL] = t19->mU.mX[6ULL];
  out->mLOG.mX[141ULL] = t19->mU.mX[0ULL];
  out->mLOG.mX[142ULL] = t19->mU.mX[1ULL];
  out->mLOG.mX[143ULL] = t19->mU.mX[3ULL];
  out->mLOG.mX[144ULL] = t19->mU.mX[4ULL];
  out->mLOG.mX[145ULL] = t19->mU.mX[5ULL];
  out->mLOG.mX[146ULL] = t19->mU.mX[6ULL];
  for (t7 = 0ULL; t7 < 12ULL; t7++) {
    out->mLOG.mX[t7 + 147ULL] =
      Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Converter_Three_Phase_G_V
      [t7];
  }

  out->mLOG.mX[159ULL] = t19->mX.mX[0ULL] * 20.0;
  out->mLOG.mX[160ULL] = t19->mX.mX[0ULL];
  out->mLOG.mX[161ULL] = -t19->mX.mX[10ULL];
  out->mLOG.mX[162ULL] = t19->mX.mX[10ULL] * 0.05;
  out->mLOG.mX[163ULL] = t19->mX.mX[0ULL] * 20.0;
  out->mLOG.mX[164ULL] = t19->mX.mX[0ULL] * 500.0;
  out->mLOG.mX[165ULL] = t19->mX.mX[0ULL] * 20.0;
  out->mLOG.mX[166ULL] = t19->mX.mX[15ULL];
  out->mLOG.mX[167ULL] = 0.0;
  out->mLOG.mX[168ULL] = t19->mX.mX[0ULL] * 500.0;
  out->mLOG.mX[169ULL] = t19->mX.mX[16ULL];
  out->mLOG.mX[170ULL] = 0.0;
  out->mLOG.mX[171ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq;
  out->mLOG.mX[172ULL] = 0.0;
  out->mLOG.mX[173ULL] =
    Subsystem_FOC_Inverter_Simulation_Simscape_Plantmodel_Worm_Gear_gear_trq *
    -0.04;
  (void)LC;
  (void)out;
  return 0;
}
