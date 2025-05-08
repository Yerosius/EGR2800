/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-25 20:55:47
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-25 23:01:56
 * @FilePath: /作业/7-voltage.c
 */
/*
作业6：电压采集
内容：将ad采集到的数字量还原成电压值，并将其显示在4位7段LED数码管上，同时也显示在LCD上。
如根据数字量算得的模拟量V=3.825V，将3.825和V=3.825V分别显示在4位7段LED数码管上和LCD上，注意，LCD上要有V=    V。
*/
//Warning:Not Sure Correct!不确保正确性!
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    PLL_init();
    seg7_enable();
    lcd_init();
    ad0_enable();
    //在LCD上硬编码电压格式
    char dis[]="V";
    set_lcd_addr(0x00);
    type_lcd(dis);
    data8('=');
    set_lcd_addr(0x03);
    data8('.');
    set_lcd_addr(0x07);
    type_lcd(dis);
    while(1){
        int t=ad0conv(7);
        t>>=1;
        t=(t/1023.0*5.0)*1000;
        seg7_on(0x80,0);//显示小数点
        for(int i=0;i<4;i++){
            int x=t%10;
            seg7dec(x,3-i);
            if(i!=3) set_lcd_addr(0x06-i);
            else set_lcd_addr(0x02);
            data8(x+'0');
            t/=10;
        }
        ms_delay(100);
    }
    return 0;
}