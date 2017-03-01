/************************************
Chip'n"Moto" V1 by Stéphen Stipe
mr.stephen.stipe@gmail.com
Derived from Chip'n'Bot V1 by Stéphane Caviglioli and Ardumoto by Timothy Holmberg at SparkFun Electronics 
cavimaster@gmail.com and unpublished respectively
************************************/
#include <Servo.h>         //inclu la librairie Servo.h

// HC-SR04
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
int leftDistance, rightDistance; //distances on either side
long cm;
// HC-SR04
//MotorShield
int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //direction control for motor outputs 3 and 4 is on digital pin 13
int val = 0;     //value for fade

Servo servoSonar;          // Servo détection obstacle


void setup() { 

  pinMode(trigPin, OUTPUT); //HC-SR04 OUT
  pinMode(echoPin, INPUT);  //HC-SR04 IN
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  analogWrite(pwm_a, 0);  //set both motors to run at (0/255 = 0)% duty cycle (stopped)
  analogWrite(pwm_b, 0);
   
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
  pinMode(echoPin, INPUT); 
 
  servoSonar.attach(5);  //Attach the SG90 servo pwm to pin 5  
  servoSonar.write(90);
} 

void loop() {            // Loop through motion tests

  
  int distanceFwd = ping();
  if (distanceFwd>15) {forward();}
  else //if path is blocked
  {
    stopRobot();
    servoSonar.write(0); 
    delay(500);
    rightDistance = ping(); //scan to the right
    delay(500);
    servoSonar.write(180);
    delay(700);
    leftDistance = ping(); //scan to the left
    delay(500);
    servoSonar.write(90); //return to center
    delay(100);
    compareDistance();
  }
  delay(100);
}


void compareDistance()
{
  if (leftDistance>rightDistance) //Room to turn Left?
  {
    turnLeft();
    delay(500); 
  }
  else if (rightDistance>leftDistance) //Room to turn Right?
  {
    turnRight();
    delay(500);
  }
   else //No Path-Backup
  {
    reverse();
    delay(1000);
  }
}

long ping(){ //Mesure la distance en cm
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  cm = pulseIn(echoPin, HIGH)/58; 
  return cm;
}

void forward() { // Routines en avant
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, 100);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 100);

}

void reverse() { // Routines en arrière
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 100);   //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 100);
}

void turnRight() { // Routines tourne à droite

  digitalWrite(dir_a, LOW);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 100);   //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 100);

}
void turnLeft() { // Routines tourne à gauche
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 100);   //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 100);
}

void stopRobot() { // Routines stop 
  digitalWrite(dir_a, LOW); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 0% duty cycle (stopped)
  analogWrite(pwm_b, 0);
}
