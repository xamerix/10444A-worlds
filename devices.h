#include "main.h"

using namespace pros;

extern Motor intake;
extern Motor unwind;
/*
extern Motor LF;
extern Motor LT;
extern Motor LB;
extern Motor RF;
extern Motor RT;
extern Motor RB;
extern Motor_Group LeftMotors;
extern Motor_Group RightMotors;
*/
extern Motor_Group pullback;
extern ADIDigitalIn slingLimit;
extern ADIDigitalOut slingRelease;
extern ADIDigitalOut endgames;
extern ADIDigitalOut bands;

extern int stateOP;
extern int unwindTimeOP;
extern int slingTimeOP;
extern int shootingCountOP;
extern bool intakeBool;
extern bool shootingOP;
extern int motorpos;
extern bool slingreleaseValue;
extern int pressed; 
extern bool unwindComplete;
extern bool pulling;
extern int desiredIntakeValue;