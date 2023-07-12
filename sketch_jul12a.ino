/*
Saurabh Salvi ME22B1033

MARS Task-2 Assignment

Subtask-3
*/

int in1 = 5;
int in2 = 4;
int enM1 = 9;
int enM2 = 11;
int in3 = 7;
int in4 = 6;
int trig = 12;
int echo = 10;
int interruptPin = 2;
int automanual = 3;
int control = 0;
int state = LOW;
float time;
float distance;
//int buzzer = 8;
int led=13;

void setup(){
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enM1, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enM2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(automanual, INPUT_PULLUP);
  pinMode(echo, INPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(led, OUTPUT);
  //pinMode(buzzer, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), startStop, FALLING);
  attachInterrupt(digitalPinToInterrupt(automanual),AM, FALLING);

}

void loop(){
  digitalWrite(trig, LOW);// Clearing purpose
  delayMicroseconds(10);
  
  digitalWrite(trig, HIGH);//On the trig pin
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  
  time = pulseIn(echo, HIGH);
  distance = (time * 0.034)/2 ;
  
  if(distance < 70){
  		digitalWrite(led, HIGH);
    	//digitalWrite(buzzer, HIGH);
  }
  else{
  		digitalWrite(led, LOW);
    	//digitalWrite(buzzer, LOW);
  }
 
  if(control == 0){ //AUTO
    		 		digitalWrite(enM1, state);
                    digitalWrite(in3, HIGH);//clock
                    digitalWrite(in4, LOW);
                    digitalWrite(enM2, state);
                    digitalWrite(in1,LOW);//anticlock
                    digitalWrite(in2,HIGH);
  if(distance < 70){
    //Wait for the instructions (car waits for input)
    				digitalWrite(enM1, state);
                    digitalWrite(in3, LOW);//clock
                    digitalWrite(in4, LOW);
                    digitalWrite(enM2, state);
                    digitalWrite(in1,LOW);//anticlock
                    digitalWrite(in2,LOW);
    
      if(Serial.available()>0)
       {     
          char data= Serial.read(); // reading the data received from the bluetooth module
          Serial.println(data);
        switch(data)
          {
            case 'r': 
               // while(distance < 70){

                //right turn
                    digitalWrite(enM1, state);
                    digitalWrite(in3,HIGH); //clock
                    digitalWrite(in4,LOW);
                    digitalWrite(enM2, state);
                    digitalWrite(in1,LOW);
                    digitalWrite(in2,LOW);
                  	/*delay(2000);
                  	break;*/
                  
                //}

                break; // when r is pressed on the app on your smart phone


            case 'l': 
                // while(distance < 70){

                      //left turn
                      digitalWrite(enM1, state);
                      digitalWrite(in3,LOW); 
                      digitalWrite(in4,LOW);
                      digitalWrite(enM2, state);
                      digitalWrite(in1,HIGH);//anticlock
                      digitalWrite(in2,LOW);
                   	
                  //}
                
                      
                
                break; // when l is pressed on the app on your smart phone

            default :
            		/*digitalWrite(enM1, LOW);
                   	digitalWrite(in3, LOW);
                    digitalWrite(in4, LOW);
                    digitalWrite(enM2, LOW);
                    digitalWrite(in1,LOW);
                    digitalWrite(in2,LOW);*/
                break;
          }
          
       }
   /* else{
    				digitalWrite(enM1, LOW);
                   	digitalWrite(in3, HIGH);//clock
                    digitalWrite(in4, LOW);
                    digitalWrite(enM2, LOW);
                    digitalWrite(in1,LOW);//anticlock
                    digitalWrite(in2,HIGH);
    }*/
  }
   delay(50);
  }
    
else if(control == 1){ //manual
    
  		if(Serial.available()>0)
       {     
          char data= Serial.read(); // reading the data received from the bluetooth module
          Serial.println(data);
          switch(data)
          {
            case 'r': 
                

                //right turn
                    digitalWrite(enM1, state);
                    digitalWrite(in3,HIGH); //clock
                    digitalWrite(in4,LOW);
                    digitalWrite(enM2, state);
                    digitalWrite(in1,LOW);
                    digitalWrite(in2,LOW);
              

                break; // when r is pressed on the app on your smart phone


            case 'l': 
                 

                      //left turn
                      digitalWrite(enM1, state);
                      digitalWrite(in3,LOW); 
                      digitalWrite(in4,LOW);
                      digitalWrite(enM2, state);
                      digitalWrite(in1,LOW);//anticlock
                      digitalWrite(in2,HIGH);
                  
                
                break; // when l is pressed on the app on your smart phone
			case 'f':
            		  digitalWrite(enM1, state);
                      digitalWrite(in3,HIGH); //clock
                      digitalWrite(in4,LOW);
                      digitalWrite(enM2, state);
                      digitalWrite(in1,LOW);//anticlock
                      digitalWrite(in2,HIGH);
            			break;
            
            case 'b':
            		  digitalWrite(enM1, state);
                      digitalWrite(in3,LOW); //anticlock
                      digitalWrite(in4,HIGH);
                      digitalWrite(enM2, state);
                      digitalWrite(in1,HIGH);//clock
                      digitalWrite(in2,LOW);
            			break;
            case 's':
            		digitalWrite(enM1, LOW);
                      digitalWrite(in3,LOW); //anticlock
                      digitalWrite(in4,LOW);
                      digitalWrite(enM2, LOW);
                      digitalWrite(in1,LOW);//clock
                      digitalWrite(in2,LOW);
            			break;
            default :
            		digitalWrite(enM1, LOW);
                   	digitalWrite(in3, LOW);
                    digitalWrite(in4, LOW);
                    digitalWrite(enM2, LOW);
                    digitalWrite(in1,LOW);
                    digitalWrite(in2,LOW);
                break;
          }
          
       }
  	}
}

void startStop(){
	state = !state;
}
  
void AM(){
  	control = !control;
 /* if(control==0){
  	Serial.println("------AUTO mode-------")
  }
  else{
  	Serial.println("------MANUAL mode-----")
  }*/
  }


