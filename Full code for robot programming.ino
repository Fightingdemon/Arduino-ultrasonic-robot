#include <Servo.h>
Servo myservo;
const int motorpin1 = 11;  //right motor edit to uor pins
const int motorpin2 = 12;

const int motorpin3 = 6;  //left motor edit to your pins
const int motorpin4 = 5;
const int trigPin = 3;   //output pin for ultrasonic
const int echoPin = 2;  //input pin for ultrasonic

long duration; 
int distanceR = 0; 
int distanceL = 0;
int distance = 40;

void setup() {
  pinMode (trigPin, OUTPUT);
   pinMode (echoPin, INPUT); 
    Serial.begin(9600);
     pinMode (motorpin1, OUTPUT);
      pinMode (motorpin2, OUTPUT);
       pinMode (motorpin3, OUTPUT);
        pinMode (motorpin4, OUTPUT);
         myservo.attach(9);
          myservo.write(115);
           delay(2000);
}  

void loop()
 {
  if(distance<=30)
  {
   moveStop();  
    delay(100);
      moveBackward();
       delay(300);
        moveStop();
         delay(200);
          distanceR = lookRight();
           delay(200);
            distanceL = lookLeft();
             delay(200);

   if(distanceL>=distanceR)
       {
   turnRight();
    moveStop();
     delay(400);
       }
       else
       {
        turnLeft();
       moveStop();
      delay(400);
       }
    }
else
{
  moveForward();
  distM;
}
distM;   
 }

 void distM()
 {
  digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
       duration = pulseIn(echoPin, HIGH);
        distance= duration*0.034/2;
         Serial.print("Distance: ");
          Serial.println(distance);
           delay(100);
 }
 int lookRight()
 {
    myservo.write(50);
     delay(500);
      distM();
       myservo.write(115);
        return distance;
 }
int lookLeft()
{
    myservo.write(170);
     delay(500);
      distM();
       myservo.write(115);
        return distance;
         delay (1000);
    }
    void moveStop() {
      analogWrite(motorpin1, 0);
       analogWrite(motorpin2, 0);
        analogWrite(motorpin3, 0);
         analogWrite(motorpin4, 0);
    }
    void moveForward() {
       analogWrite(motorpin1, 180);
        analogWrite(motorpin2, 0);
         analogWrite(motorpin3, 185);
          analogWrite(motorpin4, 0);
           distM();
            Serial.print("moveforward");
         }
     void moveBackward(){
        analogWrite(motorpin1, 0);
         analogWrite(motorpin2, 180);
          analogWrite(motorpin3, 0);
           analogWrite(motorpin4, 180);
            distM();
             Serial.print("movebackward");
         }
     void turnRight() {
      analogWrite(motorpin1, 180);
       analogWrite(motorpin2, 0);
        analogWrite(motorpin3, 0);
         analogWrite(motorpin4, 180);
          Serial.print("turn Right");
           delay(400);
            moveForward();
         }
      void turnLeft() {
       analogWrite(motorpin1,0);
        analogWrite(motorpin2, 180);
         analogWrite(motorpin3, 180);
          analogWrite(motorpin4, 0);
           Serial.print("turn Left");
            delay(300);
             moveForward();
          }
          //Written by Jacob Spijkerbosch if you don't see this I guees you just copyed my code and didnt even check if I did it right :p so shame on you if you just took all my work XD.
