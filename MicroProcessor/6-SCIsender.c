/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-18 12:10:20
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-18 12:20:13
 * @FilePath: /作业/6-SCIsender.c
 */
/*
作业6：串口发送
内容：利用串口调试助手发送'1',dragon-12 plus开发板接收，将接受到的字符"1",同时显示在第1个数码管上【利用seg7dec(c,i)】。
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    char c;
    PLL_init();
    lcd_init();
    SCI0_init(9600);
    while(1){
        c=inchar0();
        data8(c);
        outchar0(c);
        seg7dec(c-'0',0);
    }
    return 0;
}