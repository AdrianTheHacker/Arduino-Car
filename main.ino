//----------------------------------------
// Arduino-Car
//
// Author: Adrian T
// Created:     August 17, 2022
// Updated:     August 17,2022
//----------------------------------------

struct Motor {
    // The motor struct is a readable way for 
    // me to interact with each individual motor.

    int pin1;       // The pins needed to send signals between the Arduino 
    int pin2;       // to the L293D Quadruple Half-H Drivers inputs.

    void move_forward() {
        digitalWrite(pin2, LOW);
        delay(100);
        digitalWrite(pin1, HIGH);
        delay(100);
    }

    void move_backward() {
        digitalWrite(pin1, LOW);
        delay(100);
        digitalWrite(pin2, HIGH);
        delay(100);
    }

    void stop() {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        delay(100);
    }
};

struct Car {
    // The car struct is a readable way for me
    // to control all functionality of the car.

    ////////////////////
    // Car Components //
    ////////////////////

    Motor right_motor;
    Motor left_motor;

    ///////////////////////
    // Car Functionality //
    ///////////////////////

    void move_forward() {
        right_motor.move_forward();
        left_motor.move_forward();
    }

    void move_backward() {
        right_motor.move_backward();
        left_motor.move_backward();
    }

    void turn_left() {
        right_motor.move_forward();
        left_motor.stop();
    }

    void turn_right() {
        right_motor.stop();
        left_motor.move_forward();
    }

    void stop() {
        right_motor.stop();
        left_motor.stop();
    }
};

void setup() {
    for(int pin = 4; pin <= 7; pin++) {
        pinMode(pin, OUTPUT);
    }
}


void loop() {
    Car car = {
        {4, 5},
        {6, 7},
    };
}
