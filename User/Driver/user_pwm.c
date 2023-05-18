#include "user_pwm.h"
#include "stm32f1xx_ll_tim.h"

/*
 * 函数  : UserMain
 * 描述  : 用户主函数
 * 输入  :
 * 输出  :
 */
void UserPwmOutput(uint32_t Frequency, uint32_t Dutycycle, uint32_t NumPulse)
{
    uint32_t pwm_period;
    uint32_t pwm_pulse;
    
    /* 输出PWM */
    pwm_period = PWM_CK_CNT/Frequency - 1;                             //计算出计数周期(决定输出的频率)
    pwm_pulse  = (pwm_period + 1)*Dutycycle / 100;                     //计算出脉宽值(决定PWM占空比)

        /* 脉冲个数计时 */
    LL_TIM_DisableCounter(TIM3);
    LL_TIM_DisableIT_UPDATE(TIM3);
    LL_TIM_SetCounter(TIM3, 0);
    LL_TIM_SetAutoReload(TIM3, NumPulse-1);
    LL_TIM_EnableCounter(TIM3);
    LL_TIM_ClearFlag_UPDATE(TIM3);
    LL_TIM_EnableIT_UPDATE(TIM3);

//        /* 脉冲个数计时 */
    LL_TIM_DisableCounter(TIM4);
    LL_TIM_DisableIT_UPDATE(TIM4);
    LL_TIM_SetCounter(TIM4, 0);
    LL_TIM_SetAutoReload(TIM4, NumPulse-1);
    LL_TIM_EnableCounter(TIM4);
    LL_TIM_ClearFlag_UPDATE(TIM4);
    LL_TIM_EnableIT_UPDATE(TIM4);


//    LL_TIM_PWM_Stop(&PWM_TIMx, PWM_CHANNEL);                                        //失能TIM
//    LL_TIM_SET_COUNTER(&PWM_TIMx, 0);                                       //计数清零
//    LL_TIM_SetAutoReload(TIM1, pwm_period);                           //更改频率
//    LL_TIM_OC_SetCompareCH1(TIM1, pwm_pulse);                          //更改占空比
//    LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
//    LL_TIM_EnableCounter(TIM1);
//    LL_TIM_EnableAllOutputs(TIM1);
    


//    LL_TIM_PWM_Stop(&PWM_TIM2, PWM_CHANNEL);                                        //失能TIM
    LL_TIM_SetCounter(TIM2, 0);                                       //计数清零
    LL_TIM_SetAutoReload(TIM2, pwm_period);                           //更改频率
    LL_TIM_OC_SetCompareCH1(TIM2, pwm_pulse);                         //更改占空比
    LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);
    LL_TIM_EnableCounter(TIM2);
    LL_TIM_EnableAllOutputs(TIM2);

    LL_TIM_SetCounter(TIM1, 0);
    LL_TIM_SetAutoReload(TIM1, pwm_period);                           //更改频率
    LL_TIM_OC_SetCompareCH1(TIM1, pwm_pulse);                         //更改占空比
    LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
    LL_TIM_EnableCounter(TIM1);
    LL_TIM_EnableAllOutputs(TIM1);

}


void LL_TIM3_Callback(void)
{
    LL_TIM_DisableCounter(TIM1);
    LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH1);
    LL_TIM_DisableCounter(TIM3);
    LL_TIM_DisableIT_UPDATE(TIM3);

}
void LL_TIM4_Callback(void)
{
    LL_TIM_DisableCounter(TIM2);
    LL_TIM_CC_DisableChannel(TIM2, LL_TIM_CHANNEL_CH1);
    LL_TIM_DisableCounter(TIM4);
    LL_TIM_DisableIT_UPDATE(TIM4);
    
}






