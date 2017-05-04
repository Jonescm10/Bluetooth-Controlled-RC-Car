#include <AFMotor.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12,10);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

void setup() {
  Serial.begin(9600);
  
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void loop() {
  int i=ultrasonic.Ranging(INC);
  motor2.run(RELEASE);
  
  if ( i>12 ) {
    motor2.run(FORWARD);
    //Serial.print(ultrasonic.Ranging(INC));
    
  }
  else {
    motor2.run(RELEASE);
    delay(50);
    
    motor2.run(BACKWARD);
    delay(1000);
    
    motor3.run(BACKWARD);
    delay(1000);
    
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    delay(1000);
    
    motor3.run(RELEASE);
    Serial.print(ultrasonic.Ranging(INC));
  }
    
}
  

