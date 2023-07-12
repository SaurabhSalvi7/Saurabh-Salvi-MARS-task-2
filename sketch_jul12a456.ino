/*
Saurabh Salvi ME22B1033

MARS Task 2

Subtask - 2

*/

int motorclock = 5;
int motoranticlock = 6;
int interruptPincl = 2;
int interruptPinanticl = 3;
int state = LOW;
int state1 = HIGH;

void setup() {
  pinMode(motorclock, OUTPUT);
  pinMode(motoranticlock, OUTPUT);
  pinMode(interruptPincl, INPUT_PULLUP);
  pinMode(interruptPinanticl, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPincl), clock, RISING);
  
  attachInterrupt(digitalPinToInterrupt(interruptPinanticl), anticlock, RISING);
}

void loop() {
  digitalWrite(motorclock, state);
  digitalWrite(motoranticlock, state1);
}

void clock() {
  state = !state;
}

void anticlock() {
  state1 = !state1;
}