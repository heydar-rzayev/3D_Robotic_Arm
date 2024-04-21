

#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

SoftwareSerial Bluetooth(3, 4);  // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)


int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos;                          // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;                    // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50];  // for storing positions/steps
int speedDelay = 20;
int index = 0;
int dataIn;
int m = 0;

void setup() {

  servo01.attach(5);      // waist
  servo02.attach(6);      //shoulder
  servo03.attach(7);      //elbow
  servo04.attach(8);      // wrist roll
  servo05.attach(9);      //wrist pitch
  servo06.attach(10);     // grip
  Bluetooth.begin(9600);  // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(5);
  delay(20);
  Serial.begin(9600);
  // Move robot arm to initial position
  servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 90;
  servo02.write(servo2PPos);
  servo3PPos = 20;
  servo03.write(servo3PPos);
  servo4PPos = 140;
  servo04.write(servo4PPos);
  servo5PPos = 99;
  servo05.write(servo5PPos);
  servo6PPos = 50;
  servo06.write(servo6PPos);
}

void loop() {

  // Check for incoming data
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();  // Read the data
    Serial.println(dataIn);
    if (dataIn == 0) {
      m = 0;
    }
    if (dataIn == 11) {
      m = 11;
    }
    if (dataIn == 12) {
      m = 12;
    }
    if (dataIn == 14) {
      m = 14;
    }
    if (dataIn == 16) {
      m = 16;
    }
    if (dataIn == 17) {
      m = 17;
    }
    if (dataIn == 18) {
      m = 18;
    }
    if (dataIn == 19) {
      m = 19;
    }
    if (dataIn == 20) {
      m = 20;
    }
    if (dataIn == 21) {
      m = 21;
    }
    if (dataIn == 22) {
      m = 22;
    }
    if (dataIn == 23) {
      m = 23;
    }
    if (dataIn == 24) {
      m = 24;
    }
    if (dataIn == 25) {
      m = 25;
    }
    if (dataIn == 26) {
      m = 26;
    }
    if (dataIn == 27) {
      m = 27;
    }



    // Move robot arm
    // Move servo 1 in positive direction
    while (m == 16) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);
      Serial.println(servo1PPos);
    }
    // Move servo 1 in negative direction
    while (m == 17) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);
      Serial.println(servo1PPos);
    }
    // Move servo 2
    while (m == 19) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);
      Serial.println(servo2PPos);
    }
    while (m == 18) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
      Serial.println(servo2PPos);
    }
    // Move servo 3
    while (m == 20) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos++;
      delay(speedDelay);
      Serial.println(servo3PPos);
    }
    while (m == 21) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos--;
      delay(speedDelay);
      Serial.println(servo3PPos);
    }
    // Move servo 4
    while (m == 23) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);
      Serial.println(servo4PPos);
    }
    while (m == 22) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);
      Serial.println(servo4PPos);
    }
    // Move servo 5
    while (m == 25) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);
      Serial.println(servo5PPos);
    }
    while (m == 24) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos--;
      delay(speedDelay);
      Serial.println(servo5PPos);
    }
    // Move servo 6
    while (m == 26) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);
      Serial.println(servo6PPos);
    }
    while (m == 27) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos--;
      delay(speedDelay);
      Serial.println(servo6PPos);
    }

    // If arm speed slider is changed
    if (dataIn > 101 & dataIn < 250) {
      speedDelay = dataIn / 10;
    }

    if (m == 12) {

      servo01SP[index] = servo1PPos;  // save position into the array
      servo02SP[index] = servo2PPos;
      servo03SP[index] = servo3PPos;
      servo04SP[index] = servo4PPos;
      servo05SP[index] = servo5PPos;
      servo06SP[index] = servo6PPos;
      index++;  // Increase the array index
      m = 0;
    }

    if (m == 14) {
      runSteps();

      // If button "RESET" is pressed
      if (dataIn != 14) {
        // stopMoving();

        memset(servo01SP, 0, sizeof(servo01SP));  // Clear the array data to 0
        memset(servo02SP, 0, sizeof(servo02SP));
        memset(servo03SP, 0, sizeof(servo03SP));
        memset(servo04SP, 0, sizeof(servo04SP));
        memset(servo05SP, 0, sizeof(servo05SP));
        memset(servo06SP, 0, sizeof(servo06SP));
        index = 0;  // Index to 0
      }
    }
  }
}

void runSteps() {
  while (dataIn != 13) {                    // Run the steps over and over again until "RESET" button is pressed
    for (int i = 0; i <= index - 2; i++) {  // Run through all steps(index)
      if (Bluetooth.available() > 0) {      // Check for incomding data
        dataIn = Bluetooth.read();
        if (dataIn == 15) {       // If button "PAUSE" is pressed
          while (dataIn != 14) {  // Wait until "RUN" is pressed again
            if (Bluetooth.available() > 0) {
              dataIn = Bluetooth.read();
              if (dataIn == 13) {
                break;
              }
            }
          }
        }
        // If speed slider is changed
        if (dataIn > 100 & dataIn < 150) {
          speedDelay = dataIn / 10;  // Change servo speed (delay time)
        }
      }


      // Servo 1
      if (servo01SP[i] == servo01SP[i + 1]) {
      }
      if (servo01SP[i] > servo01SP[i + 1]) {
        for (int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
          Serial.println(j);
        }
      }
      if (servo01SP[i] < servo01SP[i + 1]) {
        for (int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
          servo01.write(j);
          delay(speedDelay);
          Serial.println(j);
        }
      }

      // Servo 2
      if (servo02SP[i] == servo02SP[i + 1]) {
      }
      if (servo02SP[i] > servo02SP[i + 1]) {
        for (int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
          servo02.write(j);
          delay(speedDelay);
          Serial.print("Servo 2 Position: ");
          Serial.println(j);
        }
      }
      if (servo02SP[i] < servo02SP[i + 1]) {
        for (int j = servo02SP[i]; j <= servo02SP[i + 1]; j++) {
          servo02.write(j);
          delay(speedDelay);
          Serial.print("Servo 2 Position: ");
          Serial.println(j);
        }
      }

      // Servo 3
      if (servo03SP[i] == servo03SP[i + 1]) {
      }
      if (servo03SP[i] > servo03SP[i + 1]) {
        for (int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
          servo03.write(j);
          delay(speedDelay);
          Serial.print("Servo 3 Position: ");
          Serial.println(j);
        }
      }
      if (servo03SP[i] < servo03SP[i + 1]) {
        for (int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
          servo03.write(j);
          delay(speedDelay);
          Serial.print("Servo 3 Position: ");
          Serial.println(j);
        }
      }

      // Servo 4
      if (servo04SP[i] == servo04SP[i + 1]) {
      }
      if (servo04SP[i] > servo04SP[i + 1]) {
        for (int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
          servo04.write(j);
          delay(speedDelay);
          Serial.print("Servo 4 Position: ");
          Serial.println(j);
        }
      }
      if (servo04SP[i] < servo04SP[i + 1]) {
        for (int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
          servo04.write(j);
          delay(speedDelay);
          Serial.print("Servo 4 Position: ");
          Serial.println(j);
        }
      }

      // Servo 5
      if (servo05SP[i] == servo05SP[i + 1]) {
      }
      if (servo05SP[i] > servo05SP[i + 1]) {
        for (int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
          servo05.write(j);
          delay(speedDelay);
          Serial.print("Servo 5 Position: ");
          Serial.println(j);
        }
      }
      if (servo05SP[i] < servo05SP[i + 1]) {
        for (int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
          servo05.write(j);
          delay(speedDelay);
          Serial.print("Servo 5 Position: ");
          Serial.println(j);
        }
      }

      // Servo 6
      if (servo06SP[i] == servo06SP[i + 1]) {
      }
      if (servo06SP[i] > servo06SP[i + 1]) {
        for (int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
          servo06.write(j);
          delay(speedDelay);
          Serial.print("Servo 6 Position: ");
          Serial.println(j);
        }
      }
      if (servo06SP[i] < servo06SP[i + 1]) {
        for (int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
          servo06.write(j);
          delay(speedDelay);
          Serial.print("Servo 6 Position: ");
          Serial.println(j);
        }
      }
    }
  }
}