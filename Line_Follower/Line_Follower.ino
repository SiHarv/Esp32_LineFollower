// Define motor driver pins
#define leftMotor_FORWARD 18
#define leftMotor_REVERSE 19
#define rightMotor_FORWARD 4
#define rightMotor_REVERSE 5

// Define sensor pins
#define leftSensor A33  // Left light sensor on D33
#define rightSensor A32 // Right light sensor on D32

// Define movement parameters
#define forwardSpeed 200
#define turnSpeed 150
#define stopSpeed 0
#define threshold 50  // Adjust based on sensor readings

void setup() {
    pinMode(leftMotor_FORWARD, OUTPUT);
    pinMode(leftMotor_REVERSE, OUTPUT);
    pinMode(rightMotor_FORWARD, OUTPUT);
    pinMode(rightMotor_REVERSE, OUTPUT);

    pinMode(leftSensor, INPUT);
    pinMode(rightSensor, INPUT);
}

// Function to move forward
void moveForward() {
    analogWrite(leftMotor_FORWARD, forwardSpeed);
    analogWrite(rightMotor_FORWARD, forwardSpeed);
    analogWrite(leftMotor_REVERSE, stopSpeed);
    analogWrite(rightMotor_REVERSE, stopSpeed);
}

// Function to turn left
void turnLeft() {
    analogWrite(leftMotor_FORWARD, stopSpeed);
    analogWrite(rightMotor_FORWARD, turnSpeed);
    analogWrite(leftMotor_REVERSE, stopSpeed);
    analogWrite(rightMotor_REVERSE, stopSpeed);
}

// Function to turn right
void turnRight() {
    analogWrite(leftMotor_FORWARD, turnSpeed);
    analogWrite(rightMotor_FORWARD, stopSpeed);
    analogWrite(leftMotor_REVERSE, stopSpeed);
    analogWrite(rightMotor_REVERSE, stopSpeed);
}

// Function to stop motors
void stopMotors() {
    analogWrite(leftMotor_FORWARD, stopSpeed);
    analogWrite(rightMotor_FORWARD, stopSpeed);
    analogWrite(leftMotor_REVERSE, stopSpeed);
    analogWrite(rightMotor_REVERSE, stopSpeed);
}

void loop() {
    int leftValue = analogRead(leftSensor);
    int rightValue = analogRead(rightSensor);

    // Adjust threshold based on real-world sensor values
    if (leftValue > rightValue + threshold) {
        turnLeft();
    } else if (rightValue > leftValue + threshold) {
        turnRight();
    } else {
        moveForward();
    }

    delay(50);  // Small delay for stability
}
