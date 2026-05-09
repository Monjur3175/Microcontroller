void main() {
    int adc_value;

    TRISA = 0xFF;   // input
    TRISB = 0x00;   // output
    PORTB = 0x00;

    ADC_Init();

    while(1) {
        adc_value = ADC_Read(0);

        if(adc_value > 512) {
            PORTB.F0 = 1;   // LED ON
        } else {
            PORTB.F0 = 0;   // LED OFF
        }

        Delay_ms(200);
    }
}