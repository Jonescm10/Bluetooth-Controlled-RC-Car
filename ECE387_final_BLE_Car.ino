// Adafruit Motor shield library is used in this code
// All other coding done by Carter Jones

#include <AFMotor.h>
#include <Ultrasonic.h>

// Declaring which motors to power on the motor shield
Ultrasonic ultrasonic(12, 10);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

void setup() {
  // Declaring which RX and TX ports to use and sets
  // the rate of data transfer from Bluetooth
  Serial3.begin(9600);
  Serial.begin(9600);

  // Set motor speeds(max is 255)
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void loop() {

  // Checks for a serial value input from the bluetooth module
  if (Serial3.available() > 0) {

    int inByte = Serial3.read();
    motor2.run(RELEASE);

    // Command from phone to Arduino
    switch (inByte) {

      // Forward
      case 'f':
        motor2.run(FORWARD);
        break;

      // Backward
      case 'b':
        motor2.run(BACKWARD);
        break;

      // Stop
      case 's':
        motor2.run(RELEASE);
        break;

      // Turn left while going forward
      case 'l':
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        delay(2000);
        motor3.run(FORWARD);
        delay(5);
        motor3.run(RELEASE);
        break;

      // Turn right while going forward
      case 'r':
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        delay(2000);
        motor3.run(BACKWARD);
        delay(5);
        motor3.run(RELEASE);
        break;

      // Turn left while going backward
      case 'L':
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        delay(2000);
        motor3.run(FORWARD);
        delay(5);
        motor3.run(RELEASE);
        break;

      // Turn right while going backward
      case 'R':
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        delay(2000);
        motor3.run(BACKWARD);
        delay(5);
        motor3.run(RELEASE);
        break;
      // Turn on Autonomous Mode
      case 'a':

        //The only thing that will stop this mode is the s command
        while (Serial3.read() != 's') {

          int i = ultrasonic.Ranging(INC);
          motor2.run(RELEASE);
        //If the sensor reads nothing within 12 inches from it, it will
        // continue moving forward
          if ( i > 12 ) {
            motor2.run(FORWARD);
            
          }
          else if (i == 0) {
            motor2.run(FORWARD);
          }
          // Once object is detected it commands the car to back up and turn
          else {
            motor2.run(RELEASE);

            motor2.run(BACKWARD);
            delay(1500);

            motor3.run(BACKWARD);
            delay(1000);

            motor2.run(FORWARD);
            motor3.run(FORWARD);
            delay(1000);

            motor3.run(RELEASE);
            Serial.print(ultrasonic.Ranging(INC));
          }
        }
        motor2.run(RELEASE);
        break;
    }
  }
}





