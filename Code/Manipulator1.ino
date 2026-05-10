#include <Servo.h>

// Defining constants in arrays
Servo servo[6];
int servoorigin[] = {0, 0, 0, 0, 0, 0};  // Initial positions for servos
int servopin[] = {5, 6, 7, 8, 9, 10};    // Pins for servos
int servopos[] = {120, 0, 0, 0, 0, 0};   // Tracks the current position of each servo

// Function to validate incoming data
bool Monitor(String data) {
  int servR = data.substring(2).toInt();         // Rotation value
  int servoID = data.substring(1, 2).toInt();    // Servo ID
  
  // Validating data ranges
  if ((servR >= 0 && servR <= 270) && (servoID > 0 && servoID <= 6)) {
    Serial.print("Moving Servo ");
    Serial.print(servoID);
    Serial.print(" to ");
    Serial.println(servR);
    return true;
  } else {
    Serial.print("Invalid data: ");
    Serial.println(data);
    return false;
  }
}

// Function to move the servos smoothly to the target position
void Movement(String data) {
  int servoD = data.substring(1, 2).toInt();  // Extract Servo ID
  int servor = data.substring(2).toInt();     // Extract rotation value
  
  if (servor > servopos[servoD - 1]) {  // If target is greater than current position
    for (int i = servopos[servoD - 1]; i <= servor; i++) {
      servo[servoD - 1].write(i);       // Gradual movement
      delay(20);                        // Adjust delay for smoothness
    }
  } else if (servor < servopos[servoD - 1]) { // If target is less than current position
    for (int i = servopos[servoD - 1]; i >= servor; i--) {
      servo[servoD - 1].write(i);
      delay(20);
    }
  }
  servopos[servoD - 1] = servor;  // Update the servo position
  
  // Debugging information
  Serial.print("Current position of Servo ");
  Serial.print(servoD);
  Serial.print(" is ");
  Serial.println(servopos[servoD - 1]);
}

void setup() {
  Serial.begin(9600);  // Start serial communication
  
  // Attach servos to their respective pins
  for (int i = 0; i < 6; i++) {
    servo[i].attach(servopin[i]);
  }
  
  // Initialize servos to their origin positions
  for (int i = 0; i < 6; i++) {
    servo[i].write(servoorigin[i]);
  }
}