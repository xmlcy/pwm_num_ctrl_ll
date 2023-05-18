#include "user_main.h"
#include "main.h"
#include "user_pwm.h"
#include "usart.h"

/*
 * 函数  : UserMain
 * 描述  : 用户主函数
 * 输入  :
 * 输出  :
 */
void UserMain(void)
{
    while (1)
    {
        LL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        LL_mDelay(1);
        UserPwmOutput(100000, 50, 3);
    }
}



