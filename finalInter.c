sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;
char txt[16];
void main(){
     int adc_value;
     float experiance;
     float salary;
     TRISA=0xFF;
     TRISB=0x00;
     PORTB=0x00;
     Adc_Init();
     ADCON1=0x80;
     Lcd_Init();
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Cmd(_LCD_CURSOR_OFF);
     while(1){
     adc_value=ADC_Read(0);
     experiance=(adc_value*10.0)/1023.0;
     salary=(105.40289*experiance)+64754.78;
     
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,1,"SQ:");
     FloatToStr(experiance,txt);
     Lcd_Out(1,5,txt);
     
     Lcd_Out(2,1,"Pr:");
     FloatToStr(salary,txt);
     Lcd_Out(2,5,txt);
     
     delay_ms(500);
     }
}
     