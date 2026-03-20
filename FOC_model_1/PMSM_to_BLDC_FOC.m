% Parameters
pwm_frequency = 20e3;
%Bldc 5065 parameters
Ld = 0.000035;
Lq = Ld;
R_s = 0.064;
flux_linkage = 0.0055;
motor_polepairs = 7;
Kv= 270;
J = 5.5e-5;
B = 1e-4;
%Bldc 5065 parameters
omg_cl = 2 * 3.14 * pwm_frequency;
Kp_Id = omg_cl * Ld;
Ki_Id = omg_cl * R_s;
Kp_Iq = omg_cl * Lq;
Ki_Iq = omg_cl * R_s;
kp_speed = ((J*omg_cl)/(1.5*motor_polepairs*flux_linkage)) ;
ki_speed = ((B *omg_cl * omg_cl)/(1.5*motor_polepairs*flux_linkage)) ;