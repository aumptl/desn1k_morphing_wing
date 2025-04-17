#include <Arduino.h>
#include <Servo.h>


Servo myservo;
Servo myservo2;
int x = 0;
int leds[4] = {11,5,6,3};
float y;
int sensor_value_1;
int sensor_value_2;
int adjusted_val_1;
int adjusted_val_2;

void setup(){
  Serial.begin(9600);

  myservo.attach(9);
  myservo2.attach(10);

  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
}


void loop(){
  sensor_value_1 = map(analogRead(A0), 0, 1023, 0, 1000);
  sensor_value_2 = analogRead(A1);

  if ((sensor_value_1%100)<10){
    adjusted_val_1 = map(sensor_value_1 - (sensor_value_1%100), 0, 1000, 0, 180);
  } else if ((sensor_value_1%100)>90){
    adjusted_val_1 = map(sensor_value_1 + (100-(sensor_value_1%100)), 0, 1000, 0, 180); ;
  }
  // int adjusted_val_1 = map(sensor_value_1, 0, 1020, 0, 9)*20;
  adjusted_val_2 = map(sensor_value_2, 0, 1023, -45, 45);

  myservo.write(adjusted_val_1-adjusted_val_2);
  myservo2.write(180-adjusted_val_1-adjusted_val_2);

  y = x%2000;
  for(int i=0; i<4; i++){
    analogWrite(leds[i], (sin((y/2000*2*M_PI)+(i*M_PI_2))+1)*127.5);
  }

  Serial.print("Servo 1: ");Serial.print(adjusted_val_1-adjusted_val_2);
  Serial.print(" Servo 2: ");Serial.println(180-adjusted_val_1-adjusted_val_2);



  x+=15;
  delay(15);
}