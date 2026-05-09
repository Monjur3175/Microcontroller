void MSDelay(unsigned char Time){
    unsigned char y,z;
    for(y=0;y<Time;y++) {
        for(z=0;z<20;z++);
    }
}

void main() {
    TRISC=0x00; // ???? ???????? (Data)
    TRISD=0x00; // ?? ????????? (Scanning)

    while(1) {
        // Column 1: Full vertical line (The backbone of R)
        PORTD = 0x80; PORTC = 0xFF; MSDelay(10);

        // Column 2: Top and Middle dots
        PORTD = 0x40; PORTC = 0x88; MSDelay(10);

        // Column 3: Top and Middle dots
        PORTD = 0x20; PORTC = 0x88; MSDelay(10);

        // Column 4: Top and Middle dots
        PORTD = 0x10; PORTC = 0x88; MSDelay(10);

        // Column 5: The curve and the diagonal leg
        PORTD = 0x08; PORTC = 0x77; MSDelay(10);

        // ???? ???????? ???? ????? ???? ??????? ???????? ???? ???
        PORTD = 0x04; PORTC = 0x00; MSDelay(10);
        PORTD = 0x02; PORTC = 0x00; MSDelay(10);
        PORTD = 0x01; PORTC = 0x00; MSDelay(10);
    }
}