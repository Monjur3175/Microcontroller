  char arr[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };
void main() {
 int count=0,left,right;
 TRISB = TRISC = 0x00;
 TRISD = 0xff;
 PORTB = PORTC = PORTD = 0x00;
 while(1){
  if(PORTD.F0 == 1){
 Delay_ms(30);          // debounce
 if(PORTD.F0 == 1){
  count++;
  if(count == 100) count = 0;
  while(PORTD.F0 == 1); }      // wait till release
}
       //descrease button
  if(PORTD.F1 == 1){
 Delay_ms(30);          // debounce
 if(PORTD.F1 == 1){
  if(count == 0) count = 0;
  else count--;
  while(PORTD.F1 == 1); // wait till release
 }
}

       //reset button
 if(PORTD.F2  == 1){
 delay_ms(30);
 if(PORTD.F2 == 1) {
 count = 0;
  }
 }

  left  = count/10;
  right = count%10;

  PORTC.F0 = 1;
  PORTB = arr[left];    //segment show
  Delay_ms(5);
  PORTC.F0 = 0;

  PORTC.F1 = 1;
  PORTB = arr[right];
  Delay_ms(5);
  PORTC.F1 = 0;
 }
}