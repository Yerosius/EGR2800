/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-02 20:48:41
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-02 21:14:12
 * @FilePath: /作业/数码管学号.c
 */
/*
作业2 数码管学号
内容：在4位LED数码管上显示自己学号的后4位。
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    PLL_init();
    led_disable();
    seg7_enable();
    while(1){
        seg7_on(0x06,0);//1
        seg7_on(0x66,1);//4
        seg7_on(0x07,2);//7
        seg7_on(0x6d,3);//5
    }
    return 0;
}