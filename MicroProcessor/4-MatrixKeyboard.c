/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-16 14:55:10
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-16 15:09:00
 * @FilePath: /作业/4-MatrixKeyboard.c
 */
/*
作业4：矩阵键盘
内容：用矩阵键盘点亮第3个位置的7段数码管，点亮1s后熄灭。
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    PLL_init();
    led_disable();
    seg7_enable();
    keypad_enable();
    while(1){
        seg7dec(getkey(),3);
        wait_keyup();
        ms_delay(1000);
    }
    return 0;
}