% Parameters
pwm_frequency = 20e3;
x=600;
rps=x/6.28;
f_speed=pwm_frequency/100;
f_current=pwm_frequency/10
omg_cl = 2 * 3.14 * pwm_frequency;
%Bldc RPP parameters
Ld = 0.0018;
Lq = 0.0018;
R_s = 0.037;
flux_linkage = 0.0170;
motor_polepairs = 7;
Kv= 330;
J = 4.5e-5;
B = 0.0025;
Damping_viscous = 0.00012;
Trq_cnst = 0.025;
%Bldc RPP parameters
omg_cls = 2 * 3.14 * f_speed;
omg_clc = 2 * 3.14 * f_current;
Kp_Id = omg_clc * Ld;
Ki_Id = omg_clc * R_s;
Kp_Iq = omg_clc * Lq;
Ki_Iq = omg_clc * R_s;
kp_speed = ((J*omg_cls)/(1.5*motor_polepairs*flux_linkage)) ;
ki_speed = ((B *omg_cls * omg_cls)/(1.5*motor_polepairs*flux_linkage)) ;
Torque = [0,0.5,1.6,2];
speed = [0,0,5000.7900];
Vdc = [48];

%control data

reg_ctrl_1= ( bitshift(21,6) + bitshift(1,4) + bitshift(0,3) + bitshift(0,2) + bitshift(0,0));
reg_ctrl_2= ( bitshift(0,6) + bitshift(0,4) + bitshift(1,2) + bitshift(0,0));
read_reg = 1;
write_reg = 0;
ctrl_reg1 = 0x02;
ctrl_reg2 = 0x03;
stat_reg1 = 0x00;
stat_reg2 = 0x01;