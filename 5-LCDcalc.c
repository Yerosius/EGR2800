/*
 * @Author: Yerosius yerosius@163.com
 * @Date: 2025-04-16 15:12:48
 * @LastEditors: Yerosius yerosius@163.com
 * @LastEditTime: 2025-04-16 21:13:35
 * @FilePath: /作业/5-LCDcalc.c
 */
/*
作业5：LCD计算器
内容：根据LCD1602的例子，利用按B键实现减法运算，按C键实现乘法运算，按D键实现除法运算(注意除数不能为0，需判断)。
*/
#include <hidef.h>
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h"
int main(){
    long long a,b;
    char kbuf[12];
    char* ptr=kbuf;
    char blanks[16];
    for(int i=0;i<16;i++) blanks[i]=' ';
    char invalid[16]="Cannot divided 0";
    char c,d;
    int i=0;
    PLL_init();
    lcd_init();
    keypad_enable();
    set_lcd_addr(0x00);
    while(1){
        c=getkey();
        d=hex2asc(c);
        kbuf[i]=d;
        if(c<10){
            data8(d);
            wait_keyup();
            i++;
        }else{
            switch(c){
                case 0xE://输入完一个数
                    a=number(ptr);
                    set_lcd_addr(0x40);
                    write_long_lcd(a);
                    set_lcd_addr(0x00);
                    type_lcd(blanks);
                    wait_keyup();
                    i=0;
                    set_lcd_addr(0x00);
                    break;
                case 0xB://减法
                    b=number(ptr);
                    a-=b;
                    set_lcd_addr(0x40);
                    write_long_lcd(a);
                    set_lcd_addr(0x00);
                    type_lcd(blanks);
                    wait_keyup();
                    i=0;
                    set_lcd_addr(0x00);
                    break;
                case 0xC://乘法
                    b=number(ptr);
                    a*=b;
                    set_lcd_addr(0x40);
                    write_long_lcd(a);
                    set_lcd_addr(0x00);
                    type_lcd(blanks);
                    wait_keyup();
                    i=0;
                    set_lcd_addr(0x00);
                    break;
                case 0xD://乘法
                    b=number(ptr);
                    if(b){
                        a/=b;
                        set_lcd_addr(0x40);
                        write_long_lcd(a);
                    }else{
                        set_lcd_addr(0x40);
                        type_lcd(invalid);
                    }
                    set_lcd_addr(0x00);
                    type_lcd(blanks);
                    wait_keyup();
                    i=0;
                    set_lcd_addr(0x00);
                    break;
                case 0xF://清屏
                    clear_lcd();
                    wait_keyup();
                    i=0;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}