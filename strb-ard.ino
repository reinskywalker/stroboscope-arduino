void setup() {
    pinMode(PIN_SYNC,OUTPUT);
    digitalWrite(PIN_SYNC,LOW);
    analogWrite(PIN_PWM10,0);     
    analogWrite(PIN_PWM11,0);
    analogWrite(PIN_STROBE,1);    
    //write for strobe color digitally 
    TCCR1B = 0;              
    TCCR1A = 0x82;               
    ICR1 = FlashPdCt;
    OCR1A = flength;
    TCNT1 = FlashLengthCt - 1;
    TCCR1B = 0x18 | TCCRxB_CS; 

    pinMode(PIN_KNOB_B,INPUT_PULLUP);
    pinMode(PIN_KNOB_A,INPUT_PULLUP);

    KnobState = digitalRead(PIN_KNOB_A);
    Button = PrevButton = ReadButtons(PIN_BUTTONS);

    attachInterrupt((PIN_KNOB_A - 2),KnobHandler,CHANGE);

    Serial.begin(9600);
    fdevopen(&s_putc,0); 
           (int)ffreq,(int)(100.0 * (ffreq - trunc(ffreq))),
           (int)(1e6 * flength));

    MillisThen = millis();

}
