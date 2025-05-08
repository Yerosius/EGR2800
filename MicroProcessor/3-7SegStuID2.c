/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-02 17:00:13
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-02 21:47:22
 * @FilePath: /作业/数码管学号2.c
 */
/*
作业3 数码管学号2
内容：在4位LED数码管上首先显示自己学号的后4位，然后每隔1s，加1个数，加1000个数后，显示在该值不动。
Example：若学号为20231568，从1568开始，每隔1s加1，至2568后，显示2568不动。
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
#define MOD 10
int main(){
    PLL_init();
    led_disable();
    seg7_enable();
    while(1){
        int num=1475,cnt=0;
        while(cnt<=1000){
            int temp=num;
            for(int idx=0;idx<5;idx++){
                seg7dec(temp%10,idx);
                temp/=10;
            }
            ms_delay(1000);
            num++,cnt++;
        }
    }
    return 0;
}