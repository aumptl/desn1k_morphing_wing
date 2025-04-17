// #include <Arduino.h>
// // #include <Servo.h>
// #include <math.h>


// // /*
// //   AnalogReadSerial

// //   Reads an analog input on pin 0, prints the result to the Serial Monitor.
// //   Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
// //   Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

// //   This example code is in the public domain.

// //   https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
// // */



// // Servo myservo;
// // Servo myservo2;

// // int leds[4] = {11,5,6,3};
// // int fade_ms = 2000;
// // int _delay = 30;
// // int led_state = 0;

// // int set[2] = {9,10};


// // void setup() {
// //   // initialize serial communication at 9600 bits per second:
// //   Serial.begin(9600);// Serial.println((sin(x/2000)+1)*127.5);
//     // Serial.println(x);
// //   // read the input on analog pin 0:
// //   int sensor_value_1 = analogRead(A0);

// //   int sensor_value_2 = analogRead(A1);
// //   // print out the value you read:
// //   int adjusted_val_1 = map(sensor_value_1, 0, 1023, 0, 180);
// //   int adjusted_val_2 = map(sensor_value_2, 0, 1023, 0, 180);

// //   //myservo.write(adjusted_val_1);
// //   //myservo2.write(180-adjusted_val_2);


// //   // for(int i=0; i<5; i++){
// //   //   analogWrite(leds[i], map(sin(((led_state*15)/2000)*2*M_PI+(i*M_PI/5)), -1, 1, 0, 255));
// //   // }
// //   // for(int i=0; i<5; i++){
// //   //     analogWrite(leds[i], 255);
// //   // }
// //   for(int i=0; i<4; i++){
// //       analogWrite(leds[i], map(sensor_value_1, 0,1023, 0,255));
// //   }


// //   led_state++;
// //   delay(_delay);        // delay in between reads for stability
// // }

// int x = 0;
// int leds[4] = {11,5,6,3};
// float y;

// void setup(){
//   Serial.begin(9600);
//   pinMode(11, OUTPUT);
//   pinMode(5, OUTPUT);
//   pinMode(6, OUTPUT);
//   pinMode(3, OUTPUT);
// }
// void loop(){
//   for(int i=0; i<4; i++){
//     y = x%2000;
//     analogWrite(leds[i], (sin((y/2000*2*M_PI)+(i*M_PI_2))+1)*127.5);
//   }
//   x++;
// }