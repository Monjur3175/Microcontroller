void main() {
    TRISD = 0b00000000;   // Set PORTD as output port
    PORTD = 0b11111111;   // Initialize PORTD

    do {
        PORTD = 0b00000011;   // Energize two phases
        Delay_ms(500);        // 0.5 second delay

        PORTD = 0b00000110;   // Next step
        Delay_ms(500);

        PORTD = 0b00001100;   // Next step
        Delay_ms(500);

        PORTD = 0b00001001;   // Next step
        Delay_ms(500);

    } while(1);   // Infinite loop
}