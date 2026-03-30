% Parameters
pwm_frequency = 20e3;
x=600;
rps=x;
f_speed= pwm_frequency/100;
f_current=pwm_frequency/10
omg_cl = 2 * 3.14 * pwm_frequency;
%Bldc RPP parameters
Ld = 0.0018;
Lq = 0.0018;
R_s = 0.037;
flux_linkage = 0.0170;
motor_polepairs = 7;
Kv= 77;
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