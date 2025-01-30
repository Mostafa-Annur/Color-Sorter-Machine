#include <Servo.h>
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
#define led1 13
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(8);
  bottomServo.attach(9);
  digitalWrite(led1,HIGH);
  Serial.begin(9600);
  bottomServo.write(75);
  delay(2000);
}
void loop() {
  
  topServo.write(120);
  delay(1000);
  
  for(int i = 120; i > 73; i--) {
    topServo.write(i);
    delay(4);
  }
  delay(2500);
   
  Serial.print("Reading color = \n");//printing name
  color = readColor();
  delay(1000);  
  switch (color) {
    case 1:
    bottomServo.write(20);
    break;
   /* case 2:
    bottomServo.write(75);
    break;*/
    case 3:
    bottomServo.write(48);
    break;
    case 4:
    bottomServo.write(107);
    break;
    case 5:
    bottomServo.write(135);
    break;
    case 6:
    bottomServo.write(75);
    break;
    
    case 0:
    break;
  }
  delay(600);
  
  for(int i = 73; i > 25; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(500);
  
  for(int i = 25; i < 120; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}
// Custom Function - readColor()
int readColor() {
  
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);


if(R<26 && R>22 && G<36 && G>34 && B<44 && B>42){
}
 else {
   
 if(R<11 && R>1 && G<20 && G>11 && B<15 && B>5){
    color = 1; // Red
 }

else if(R<24 && R>14 && G<15 && G>8 && B<15 && B>8){
    color = 3; // Green
    
  }
 else if(R<10 && R>0 && G<10 && G>1 && B<14 && B>5){
    color = 4; // Yellow
  }

else if(R<25 && R>15 && G<15 && G>5 && B<8 && B>0){
    color = 6; // Blue
  }

else
  color = 5;//other

}
 
  return color;  
}
