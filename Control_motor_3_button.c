char state = 0;

void main() {
    // ??? ??????????
    TRISB = 0x00;  // PORTB ?????? (???? ???????? ???)
    TRISD = 0xFF;  // PORTD ????? (????)

    PORTB = 0x00;  // ?????? ?? ????

    while(1) {
        // ???? ?: State 1 (Clockwise)
        if(PORTD.F0 == 1) {
            Delay_ms(50); // Debounce delay
            if(PORTD.F0 == 1) {
                state = 1;
            }
            while(PORTD.F0 == 1); // ???? ???? ????? ??????? ???????
        }

        // ???? ?: State 2 (Anticlockwise)
        if(PORTD.F1 == 1) {
            Delay_ms(50);
            if(PORTD.F1 == 1) {
                state = 2;
            }
            while(PORTD.F1 == 1);
        }

        // ???? ?: State 0 (Stop)
        if(PORTD.F2 == 1) {
            Delay_ms(50);
            if(PORTD.F2 == 1) {
                state = 0;
            }
            while(PORTD.F2 == 1);
        }

        // --- ???? ???????? ???? ---
        if(state == 1) {
            // Forward / Clockwise
            PORTB.F0 = 1;
            PORTB.F1 = 0;
            PORTB.F2 = 1; // Enable ??? ??? ??? ???? (????? ???? ???????)
        }
        else if(state == 2) {
            // Backward / Anticlockwise
            PORTB.F0 = 0;
            PORTB.F1 = 1;
            PORTB.F2 = 1;
        }
        else {
            // Stop (state == 0)
            PORTB.F0 = 0;
            PORTB.F1 = 0;
            PORTB.F2 = 0;
        }
    }
}