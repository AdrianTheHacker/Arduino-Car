//----------------------------------------
// Arduino-Car
//
// Author: Adrian T
// Created:     August 17, 2022
// Updated:     August 17,2022
//
// Description: One at a time, this program will test
//              all the functionality of the car.
//
//----------------------------------------

#include <Servo.h>      // If using VScode with the Arduino Extension, Ignore this error message.

#define DELAY 400
Servo servo;

struct Motor {
    // The motor struct is a readable way for 
    // me to interact with each individual motor.

    int pin1;       // The pins needed to send signals between the Arduino 
    int pin2;       // to the L293D Quadruple Half-H Drivers inputs.

    void stop() {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        delay(100);
    }

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
};

struct RearWheelServo {
    // The servo has a wheel attached to it.
    // The servo is used for steering.

    Servo servo;

    void straight() {
        // Centers the servo.
        // Which makes the car move straight.

        servo.write(90);
    }

    void turn_left() {
        // Turns the servo counter clockwise
        // until it's at a 135 degree angle. 

        servo.write(135);
    }

    void turn_right() {
        // Turns the servo clockwise
        // until it's at a 45 degree angle.

        servo.write(45);
    }

    void sharp_turn_left() {
        // Turns the servo counter clockwise
        // until it's at a 180 degree angle.

        servo.write(180);
    }

    void sharp_turn_right() {
        // Turns the servo clockwise
        // until it's at a 0 degree angle.

        servo.write(0);
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
    RearWheelServo rear_wheel;

    ///////////////////////
    // Car Functionality //
    ///////////////////////

    void stop() {
        rear_wheel.straight();
        right_motor.stop();
        left_motor.stop();
    }

    void move_forward() {
        right_motor.move_forward();
        left_motor.move_forward();
    }

    void move_backward() {
        right_motor.move_backward();
        left_motor.move_backward();
    }

    void turn_straight() {
        rear_wheel.straight();
    }

    void turn_left() {
        rear_wheel.turn_left();
    }

    void turn_right() {
        rear_wheel.turn_right();
    }

    void sharp_turn_left() {
        rear_wheel.sharp_turn_left();
        right_motor.move_forward();
        left_motor.move_backward();
    }

    void sharp_turn_right() {
        rear_wheel.sharp_turn_right();
        right_motor.move_backward();
        left_motor.move_forward();
    }
};

void setup() {
    for(int pin = 4; pin <= 13; pin++) {
        pinMode(pin, OUTPUT);
    }

    servo.attach(10);
}

void loop() {
    Car car = {
        {3, 5}, 
        {9, 6},
    };

    car.move_forward();
    delay(DELAY);
    car.move_backward();
    delay(DELAY);
    car.turn_left();
    delay(DELAY);
    car.turn_right();
    delay(DELAY);
    car.sharp_turn_left();
    delay(DELAY);
    car.sharp_turn_right();
    delay(DELAY);
}
