void servoRotate0() // 0 Degree
{
    unsigned int i;
    for(i = 0; i < 50; i++)
    {
        PORTB.F0 = 1;
        Delay_us(800);
        PORTB.F0 = 0;
        Delay_us(19200);
    }
}

void servoRotate90() // 90 Degree
{
    unsigned int i;
    for(i = 0; i < 50; i++)
    {
        PORTB.F0 = 1;
        Delay_us(1500);
        PORTB.F0 = 0;
        Delay_us(18500);
    }
}

void servoRotate180() // 180 Degree
{
    unsigned int i;
    for(i = 0; i < 50; i++)
    {
        PORTB.F0 = 1;
        Delay_us(2200);
        PORTB.F0 = 0;
        Delay_us(17800);
    }
}

int position = 0;

void main()
{
    TRISB.F0 = 0;   // RB0 output for servo
    TRISD.F0 = 1;   // RD0 input (INC)
    TRISD.F1 = 1;   // RD1 input (DEC)

    PORTD.F0 = 0;
    PORTD.F1 = 0;

    while(1)
    {
        // INC Button
        if(PORTD.F0 == 1)
        {
            Delay_ms(50); // debounce

            if(position < 2)
            {
                position++;
            }

            while(PORTD.F0 == 1);

            if(position == 0)
                servoRotate0();

            else if(position == 1)
                servoRotate90();

            else if(position == 2)
                servoRotate180();
        }

        // DEC Button
        if(PORTD.F1 == 1)
        {
            Delay_ms(50); // debounce

            if(position > 0)
            {
                position--;
            }

            while(PORTD.F1 == 1);

            if(position == 0)
                servoRotate0();

            else if(position == 1)
                servoRotate90();

            else if(position == 2)
                servoRotate180();
        }
    }
}