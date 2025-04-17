#include <Arduino.h>
#include <Servo.h>

const int LEDS[4] = {11, 5, 6, 3};

Servo servos[2];

void setup(){
    Serial.begin(9600);

    servos[0].attach(9);
    servos[1].attach(10);

    pinMode(11, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(3, OUTPUT);
}


void loop(){    
    int sensor_val_1 = map(analogRead(A0), 0, 1023, 0, 1000);
    int sensor_val_2 = analogRead(A1);

    int adjusted_val_1, adjusted_val_2;

    // Fractional part of sensor val 1 (to nearest 100)
    int frac_sensor_val_1 = sensor_val_1 % 100;
    int floor_sensor_val_1 = sensor_val_1 - frac_sensor_val_1;

    if (frac_sensor_val_1 < 10) {
        adjusted_val_1 = map(floor_sensor_val_1, 0, 1000, 0, 180);
    } else if ((sensor_val_1 % 100)>90){
        adjusted_val_1 = map(100 + floor_sensor_val_1, 0, 1000, 0, 180);
    }

    // int adjusted_val_1 = map(sensor_val_1, 0, 1020, 0, 9)*20;
    adjusted_val_2 = map(sensor_val_2, 0, 1023, -45, 45);

    servos[0].write(adjusted_val_1-adjusted_val_2);
    servos[1].write(180-adjusted_val_1-adjusted_val_2);

    for(int i = 0; i < 4; ++i) {
        float n = 2.f*M_PI*(1.f/2000.f);
        float phase_shift = i*M_PI_2;

        analogWrite(LEDS[i], (sin(millis()*n+phase_shift)+1.f)*127.5f);
    }

    Serial.print("Servo 1: ");Serial.print(adjusted_val_1-adjusted_val_2);
    Serial.print(" Servo 2: ");Serial.println(180-adjusted_val_1-adjusted_val_2);
    
    delay(15)
}
