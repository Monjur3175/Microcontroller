// LCD connections - Port B
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

// Button connections - Port D
sbit BTN_INC at RD0_bit;   // Pin 19 - Increment
sbit BTN_DEC at RD1_bit;   // Pin 20 - Decrement
sbit BTN_SET at RD2_bit;   // Pin 21 - Set / Confirm

char txt[16];

void main() {

    int  exp_count = 0;   // 1 unit = 0.5 years, range 0-20 (0.0 - 10.0 yrs)
    float experience;
    float salary;

    TRISA = 0xFF;          // Port A input (not used but safe)
    TRISB = 0x00;          // Port B output (LCD)
    TRISD = 0xFF;          // Port D input (buttons)
    PORTB = 0x00;

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

    // Welcome screen
    Lcd_Out(1, 1, "ML Salary Pred");
    Lcd_Out(2, 1, "INC/DEC + SET");
    Delay_ms(2000);
    Lcd_Cmd(_LCD_CLEAR);

    // Show initial value
    experience = 0.0;
    Lcd_Out(1, 1, "Exp(yrs): 0.0");
    Lcd_Out(2, 1, "Press INC/DEC");

    while(1) {

        // --- INCREMENT button (RD0, pin 19) ---
        if (BTN_INC == 0) {
            Delay_ms(30);                  // Debounce
            if (BTN_INC == 0) {
                if (exp_count < 20)
                    exp_count++;

                experience = exp_count * 0.5;

                Lcd_Cmd(_LCD_CLEAR);
                Lcd_Out(1, 1, "Exp(yrs):");
                FloatToStr(experience, txt);
                Lcd_Out(1, 10, txt);
                Lcd_Out(2, 1, "Press SET->Sal");

                while (BTN_INC == 0);      // Wait release
                Delay_ms(30);
            }
        }

        // --- DECREMENT button (RD1, pin 20) ---
        if (BTN_DEC == 0) {
            Delay_ms(30);
            if (BTN_DEC == 0) {
                if (exp_count > 0)
                    exp_count--;

                experience = exp_count * 0.5;

                Lcd_Cmd(_LCD_CLEAR);
                Lcd_Out(1, 1, "Exp(yrs):");
                FloatToStr(experience, txt);
                Lcd_Out(1, 10, txt);
                Lcd_Out(2, 1, "Press SET->Sal");

                while (BTN_DEC == 0);      // Wait release
                Delay_ms(30);
            }
        }

        // --- SET button (RD2, pin 21) ---
        if (BTN_SET == 0) {
            Delay_ms(30);
            if (BTN_SET == 0) {

                experience = exp_count * 0.5;

                // ML Linear Regression equation
                salary = (105.40289 * experience) + 64754.78;

                Lcd_Cmd(_LCD_CLEAR);
                Lcd_Out(1, 1, "Exp:");
                FloatToStr(experience, txt);
                Lcd_Out(1, 5, txt);

                Lcd_Out(2, 1, "Sal:");
                FloatToStr(salary, txt);
                Lcd_Out(2, 5, txt);

                while (BTN_SET == 0);      // Wait release
                Delay_ms(30);
            }
        }

    }
}