/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-02 20:38:53
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-02 23:51:05
 * @FilePath: /作业/1-StreamLED.c
 */
/*
作业1 流水灯
内容：设给定PORTB的初值为0xfe。在LED使能情况下,采用每次左移1次或者右移1次的方式实现LED流水灯。
Hint：点亮LED小灯的值为高电平，因此此时除最低位的LED灯不亮外，其他灯均处于点亮状态。要想使得最低位的灯亮，则需要leds_on(~0xfe)
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    PLL_init();
    led_enable();
    seg7_disable();
    PORTB=0xfe;
    ms_delay(500);
    while(1){
        for(;PORTB!=0x80;PORTB<<=1){
            leds_on(PORTB);
            ms_delay(500);
        }
        for(;PORTB!=0xff;PORTB>>=1){
            leds_on(PORTB);
            ms_delay(500);
        }
    }
    return 0;
}