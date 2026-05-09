#define FAN PORTB.F0

void main() {
    int adc_value;
    float temperature;

    TRISB = 0x00;   // PORTB output
    TRISA = 0xFF;   // PORTA input

    ADCON1 = 0x80;  // IMPORTANT: Configure ADC
    ADC_Init();

    while(1) {
        adc_value = ADC_Read(0);   // Read AN0

        temperature = (adc_value * 5.0 / 1023.0) * 100;

        if (temperature <= 32) {
            FAN = 0;
        } else {
            FAN = 1;
        }

        Delay_ms(200);
    }
}