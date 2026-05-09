#define LED PORTB.F0  // LED connected to RB0
#define POT_CHANNEL 0 // AN0 for potentiometer

void main() {
    int potValue;

    TRISB = 0x00; // PORTB output
    TRISA = 0xFF; // PORTA input (ADC)

    ADC_Init(); // Initialize ADC

    while(1) {
        potValue = ADC_Read(POT_CHANNEL); // Read potentiometer (0-1023)

        // Scale to 0-100 for easier threshold comparison
        potValue = (potValue * 100) / 1023;

        // Decision Tree Logic
        if(potValue <= 75) {
            LED = 0; // OFF
        } else {
            LED = 1; // ON
        }
    }
}