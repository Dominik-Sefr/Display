#include "mbed.h"
#include "LCD_DISCO_F469NI.h"

LCD_DISCO_F469NI lcd;
DigitalIn button(PA_0);
DigitalOut led1(LED1);
Thread thread1;
Thread thread2;
Thread thread3;
#define WAIT 1000ms
#define ASYNC 777ms
void DisplayBlink(){
    while(true){
        ThisThread::sleep_for(WAIT);
        lcd.SetBackColor(LCD_COLOR_BLUE);
        lcd.SetTextColor(LCD_COLOR_WHITE);
        lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"DISCOVERY", CENTER_MODE);
        lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"STM32F469NI", CENTER_MODE);
        ThisThread::sleep_for(WAIT);
        lcd.SetTextColor(LCD_COLOR_BLUE);
        lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"DISCOVERY", CENTER_MODE);
        lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"STM32F469NI", CENTER_MODE);
    }
}
void LedBlink(){
    while(true){
        led1 = !led1;
        ThisThread::sleep_for(ASYNC);
    }
}
void ButtonDisp(){
    while(true){

        if(button){
            lcd.SetTextColor(LCD_COLOR_WHITE);
            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Tlačítko", CENTER_MODE);
            ThisThread::sleep_for(ASYNC);
            lcd.SetTextColor(LCD_COLOR_BLUE);
            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Tlačítko", CENTER_MODE);
        }
    }
}
int main()
{    
    lcd.Clear(LCD_COLOR_BLUE);
    thread1.start(DisplayBlink);
    thread2.start(LedBlink);
    thread3.start(ButtonDisp);
}

