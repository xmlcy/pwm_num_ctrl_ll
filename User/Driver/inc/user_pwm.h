#ifndef __USER_PWM_H
#define __USER_PWM_H

#define PWM_TIMx     htim1
#define PWM_CHANNEL  TIM_CHANNEL_1
#define PWM_COMPARE_RATIO 50
#define PWM_CK_CNT 72000000
#define CNT_TIMx htim3

#define PWM_TIM2     htim2
#define CNT_TIM2    htim4

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "tim.h"

/* Fuctions ------------------------------------------------------------------*/
void UserPwmOutput(uint32_t Frequency, uint32_t Dutycycle, uint32_t NumPulse);
void LL_TIM3_Callback(void);
void LL_TIM4_Callback(void);






#endif /* __USER_PWM_H */



