// parameter for stroboscopes
int analogPin = 2;
int ledPin = 13;

// timing parameters in ms
long onTime = 250;

// Strobe effect timing range in milliseconds (ms)
int minDelay = 1; 
int maxDelay = 100;

long strobeDelay = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  strobeDelay = map(analogRead(analogPin), 0, 1023, minDelay, maxFinishedelay);

  digitalWrite(ledPin, HIGH); // LED on
  delayMicroseconds(onTime); // set on duration
  digitalWrite(ledPin, LOW); // LED off
  delay(strobeDelay); // next flash
}
