#include <SoftwareSerial.h>
#include "alphabot_drivers.h"
#include "remote_control.h"

// Define the RX and TX pins on the Arduino
#define RX_PIN 7
#define TX_PIN 8

// Create a SoftwareSerial object
SoftwareSerial xbeeSerial(RX_PIN, TX_PIN);

Remote_control__main_out _res;
Remote_control__main_mem _mem;

void setup() {
  init_devices();
  // Initialize serial communication
  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);
  Remote_control__main_reset(&_mem);
  Serial.begin(9600);  // For debugging purposes
  xbeeSerial.begin(9600); // Initialize XBee communication
  // forward();
}

void loop() {
  // Check if data is available from the XBee module
  if (xbeeSerial.available()) {
    // Read the data from the XBee module
    // forward();
    // String receivedData = readFixedLengthData(6); // Read 3 characters
    // String receivedData = xbeeSerial.readStringUntil("\n");
    // char receivedData = xbeeSerial.read();

    // Serial.println("reading done.");
    // forward();
    // sscanf(receivedData.c_str(), "%d,%d,%d", &joystick, &s1, &s2);
    
    // Process the parsed data
    // if (joystick == '0') {
    //   forward();
    // }
   
  //  Serial.println("hi");

    String receivedData = String(xbeeSerial.read());
    int receivedDataInt= receivedData.toInt();
    // Serial.println(receivedDataInt);

// 48 no command, 
// 49 : left 
// 50 : right
// 51 : forward
// 52 : back
// 53 : switch
// 54 : limit switch left
// 55 : limit switch right
 int integerDir= receivedDataInt - 48;
    Serial.println(integerDir);

    if (integerDir > 0)  {
    	Remote_control__main_step(integerDir, &_res, &_mem);
    	
        if (_res.dir == 0) {
                forward();
            }
            else if (_res.dir == 1) {
                left();
            }
            else if (_res.dir == 2) {
                right();
            }
            else {
          backward();   		
            }
          SetSpeed(_res.v_r, _res.v_l);
          }
    else {
	      SetSpeed(0, 0);
    }
  }
}
