
#include <math.h>


int signal1[2] = {12,13} ;
int signal2[2] = {10,11} ;

const int triggerpin1 = 8;
const int echopin1 = 9;
const int triggerpin2 = 7;
const int echopin2 = 6 ;


int sig_delay = 1000;


long time;                    // Variable for storing the time traveled
int d1, d2;           // Variables for storing the density 


void setup(){
  Serial.begin(115200);

  
  // Declaring LED pins as output
  for(int i=0; i<2; i++){
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);

  }
  // Declaring ultrasonic sensor pins as output
  pinMode(triggerpin1, OUTPUT);  
  pinMode(echopin1, INPUT);      
  pinMode(triggerpin2, OUTPUT);  
  pinMode(echopin2, INPUT);
 
}


void softInterr()
{
  // Reading from first ultrasonic sensor
  digitalWrite(triggerpin1, LOW);  
  delayMicroseconds(2);
  digitalWrite(triggerpin1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerpin1, LOW);

  time = pulseIn(echopin1, HIGH); 
  d1= time*0.034/2;

  // Reading from second ultrasonic sensor
  digitalWrite(triggerpin2, LOW);  
  delayMicroseconds(2);
  digitalWrite(triggerpin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerpin2, LOW);

  time = pulseIn(echopin2, HIGH); 
  d2= time*0.034/2;



  // Print density values on serial monitor for debugging
  Serial.print("  S1: ");
  Serial.print(d1);
  Serial.print("  S2: ");
  Serial.print(d2);


}

void loop()
{
  softInterr() ;
  int max_d = d1 ;
  max_d = min(max_d,d2) ;


  if (max_d==d1) {
    signal1Function();
    loop() ;
  }
  if (max_d==d2) {
    signal2Function();
    loop() ;
  }


}



void low()
{
  for(int i=1; i<2; i++)
  {
    digitalWrite(signal1[i], LOW);
    
    digitalWrite(signal2[i], LOW);
    

  }
  for(int i=0; i<1; i++)
  {
    digitalWrite(signal1[i], HIGH);
    
    digitalWrite(signal2[i], HIGH);
    

  }
}


void signal1Function()
{
  Serial.println("1");
  low();
  
  digitalWrite(signal1[0], LOW);
 
  digitalWrite(signal1[1], HIGH);
  delay(sig_delay);
  
}

void signal2Function()
{
  Serial.println("2");
  low();
  digitalWrite(signal2[0], LOW);
 
  digitalWrite(signal2[1], HIGH);
  delay(sig_delay);
  
}
