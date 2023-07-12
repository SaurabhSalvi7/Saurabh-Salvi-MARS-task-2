/*
Saurabh Salvi
ME22B1033
Another option for subtask-2 in Task#2
i.e. with just 1 button, control clockwise and anticlockwise
	for single motor
*/

int motorclock = 3;
int motoranticlock = 4;
int interruptPincl = 2;
int en = 6;
//int interruptPinanticl = 3;
int state = HIGH;
//int state1 = HIGH;

void setup() {
  pinMode(motorclock, OUTPUT);
  pinMode(motoranticlock, OUTPUT);
  pinMode(interruptPincl, INPUT_PULLUP);
  //pinMode(interruptPinanticl, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPincl), clock, RISING);
  
  //attachInterrupt(digitalPinToInterrupt(interruptPinanticl), anticlock, RISING);
}

void loop() {
  if(state == LOW){
  digitalWrite(en, !state);
  digitalWrite(motorclock, HIGH);
  digitalWrite(motoranticlock, LOW);
  }
  else{
  digitalWrite(en, state);
  digitalWrite(motorclock, LOW);
  digitalWrite(motoranticlock, HIGH);
  }
}

void clock() {
  state = !state;
}

