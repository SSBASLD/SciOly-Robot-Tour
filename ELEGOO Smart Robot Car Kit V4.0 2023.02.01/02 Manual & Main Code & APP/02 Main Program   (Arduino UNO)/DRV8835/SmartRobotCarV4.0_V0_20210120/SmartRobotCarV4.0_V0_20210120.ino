/*
 * @Author: ELEGOO
 * @Date: 2019-10-22 11:59:09
 * @LastEditTime: 2021-01-04 14:36:47
 * @LastEditors: Changhua
 * @Description: Smart Robot Car V4.0
 * @FilePath: 
 */
#include <avr/wdt.h>
#include "ApplicationFunctionSet_xxx0.h"
void setup()
{
  // put your setup code here, to run once:
  Application_FunctionSet.ApplicationFunctionSet_Init();
  wdt_enable(WDTO_2S);
}

void loop()
{
  AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_just, /*speed_A*/ CMD_is_MotorSpeed_L,
                                             /*direction_B*/ direction_just, /*speed_B*/ CMD_is_MotorSpeed_R,
                                              /*controlED*/ control_enable); //Motor control  

  //put your main code here, to run repeatedly :
  wdt_reset();
  Application_FunctionSet.ApplicationFunctionSet_SensorDataUpdate();
  Application_FunctionSet.ApplicationFunctionSet_KeyCommand();
  Application_FunctionSet.ApplicationFunctionSet_RGB();
  Application_FunctionSet.ApplicationFunctionSet_Follow();
  Application_FunctionSet.ApplicationFunctionSet_Obstacle();
  Application_FunctionSet.ApplicationFunctionSet_Tracking();
  Application_FunctionSet.ApplicationFunctionSet_Rocker();
  Application_FunctionSet.ApplicationFunctionSet_Standby();
  Application_FunctionSet.ApplicationFunctionSet_IRrecv();
  Application_FunctionSet.ApplicationFunctionSet_SerialPortDataAnalysis();

  Application_FunctionSet.CMD_ServoControl_xxx0();
  Application_FunctionSet.CMD_MotorControl_xxx0();
  Application_FunctionSet.CMD_CarControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_CarControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_MotorControlSpeed_xxx0();
  Application_FunctionSet.CMD_LightingControlTimeLimit_xxx0();
  Application_FunctionSet.CMD_LightingControlNoTimeLimit_xxx0();
  Application_FunctionSet.CMD_ClearAllFunctions_xxx0();
}
