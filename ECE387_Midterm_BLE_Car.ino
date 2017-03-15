// Adafruit Motor shield library is used in this code
// All other coding done by Carter Jones

#include <AFMotor.h>

// Declaring which motors to power on the motor shield
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

void setup() {
  // Declaring which RX and TX ports to use and sets 
  // the rate of data transfer from Bluetooth 
  Serial3.begin(9600);
  

  // Set motor speeds(max is 255)
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void loop() {
  
// Checks for a serial value input from the bluetooth module
 if(Serial3.available()>0) {

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
    }
  }
}

 

 

