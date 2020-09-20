#include <carduinotest.h>
#include "can.h"

#define combineUint16(L, H) (H * 256 + L)
#define highUint16(V) (V >> 8)
#define lowUint16(V) (V & 0xFF)


void canCallback(const CAN_message_t &message);
void onCarduinoSerialTimeout();
void onCarduinoSerialEvent(uint8_t type, uint8_t id, BinaryBuffer *payloadBuffer);

Can can(&Serial);
Carduino carduino(&Serial, onCarduinoSerialEvent, onCarduinoSerialTimeout);

CAN_message_t message180;
CAN_message_t message182;
CAN_message_t message551;
//CAN_message_t message215;

CAN_message_t message0216;

CAN_message_t message060D;
CAN_message_t message0215;
CAN_message_t message0233;
CAN_message_t message0551;
CAN_message_t message0351;
CAN_message_t message0625;
CAN_message_t message0385;
CAN_message_t message0421;
CAN_message_t message0580;
CAN_message_t message05C5;
CAN_message_t message0682;
CAN_message_t message0160;
CAN_message_t message0358;
CAN_message_t message0180;
CAN_message_t message035D;
CAN_message_t message0354;

CAN_message_t message0626;

CAN_message_t message02DE;

CAN_message_t message0280;

CAN_message_t message01F9;

CAN_message_t message0245;

CAN_message_t message0002;

CAN_message_t message0355;




void setup() {
  carduino.begin();

  can.setup(500000, 500000);

  // Add all can packets that should be redirected without change
  can.addCanId(0x0002);
  can.addCanId(0x0160);
  //can.addCanId(0x0180);
  can.addCanId(0x0182);
  can.addCanId(0x01F9);
  can.addCanId(0x0215);
  can.addCanId(0x0216);
  //can.addCanId(0x0233);
  //can.addCanId(0x023D);

  can.addCanId(0x0245);
  can.addCanId(0x0280);
  can.addCanId(0x0284);
  can.addCanId(0x0285);
  can.addCanId(0x0292);
  can.addCanId(0x02DE);
  can.addCanId(0x0342);
  can.addCanId(0x0354);
  can.addCanId(0x0355);
  can.addCanId(0x0358);

  //can.addCanId(0x0385);
  can.addCanId(0x0421);
  can.addCanId(0x0512);
  can.addCanId(0x054C);
  can.addCanId(0x0580);

  can.addCanId(0x0625);
  can.addCanId(0x060D);
  can.addCanId(0x0682);
  can.addCanId(0x06E2);

  // initialize composed packets
  message180.id = 0x0180;
  message180.len = 8;

  message551.id = 0x0551;
  message551.len = 8;

  message060D.id = 0x060D;
  message060D.len = 8;

  message0215.id = 0x0215;
  message0215.len = 8;

  message0233.id = 0x0233;
  message0233.len = 8;

  

  message0551.id = 0x0551;
  message0551.len = 8;

  message0351.id = 0x0351;
  message0351.len = 8;

  message0625.id = 0x0625;
  message0625.len = 8;

  message0385.id = 0x0385;
  message0385.len = 8;

  message0421.id = 0x0421;
  message0421.len = 8;

  message0580.id = 0x0580;
  message0580.len = 8;

  message05C5.id = 0x05C5;
  message05C5.len = 8;

  message0682.id = 0x0682;
  message0682.len = 8;

  message0216.id = 0x0217;
  message0216.len = 8;

  message182.id = 0x0182;
  message182.len = 8;

  message0160.id = 0x0160;
  message0160.len = 8;

  message0358.id = 0x0358;
  message0358.len = 8;

  message035D.id = 0x035D;
  message035D.len = 8;

  message0354.id = 0x0354;
  message0354.len = 8;

  message0626.id = 0x0620;
  message0626.len = 8;


  message02DE.id = 0x02DE;
  message02DE.len = 8;

  message0280.id = 0x0280;
  message0280.len = 8;

  message01F9.id = 0x01F9;
  message01F9.len = 8;

  message0245.id = 0x0245;
  message0245.len = 8;

  message0002.id = 0x0160;
  message0002.len = 8;

  message0355.id = 0x0355;
  message0355.len = 8;

  


message0551.buf[5]= B01010000;

}

void loop() {
  if (carduino.update()) {
     
      

    }

    can.update(canCallback);


/*
      message060D.buf[0] = B00000110;
      message060D.buf[1] = B10010111;
      message060D.buf[2] = B11101100;
      message060D.buf[3] = B00000000;
      
      //message060D.buf[3] = B00101010; // 4x Beep
      //message060D.buf[5] = B11111111;
      message0354.buf[4] = B11100000;
      message0354.buf[5] = B11000000;
      //delay(3000);


      message0215.buf[3] = B11111111;
      message0216.buf[0] = B11111111;
      
      message0216.buf[1] = B11111000;
      

      //message0551.buf[5] = B01010000; // Cruise
      message0551.buf[5] = B01000000; // Cruise SET
      //message0551.buf[5] = B10100000; // Cruise Limit
      message0551.buf[0] = B00111100; // Engine Coolant
      message0551.buf[1] = B00000111;
      message0551.buf[5] = B00000011;
      
      
      //message0351.buf[5] = B00001000; //  NO KEY Detected
      //message0351.buf[5] = B00000100; // Steering wheel & Push Button
      //message0351.buf[5] = B00000001; // Brake + Push Button
      //message0351.buf[5] = B00000011; // Key ID Incorrect
      //message0351.buf[5] = B00000111; // Key Batterie LOW
      //message0351.buf[5] = B00001111; //Push Brake and Start Button to drive
      //message0351.buf[5] = B00011111; //fast beep
      //message0351.buf[6] = B10000000;  // beep beep
      //message0351.buf[7] = B11111111;
      ************************************************************************
      //message0385.buf[0] = B00000010;  // TPMS ERROR
      //message0385.buf[1] = B00000001;  // Tire Pressure LOW RL
      //message0385.buf[1] = B00000010;  // Tire Pressure LOW RL 
      //message0385.buf[1] = B00000100;  // Tire Pressure LOW FL
      //message0385.buf[1] = B00001000;  // Tire Pressure LOW FR
      //message0385.buf[1] = B00010000;  // Flat Tire
      ************************************************************************
      //message0421.buf[0] = B10000000; // 1M Gear
      //message0421.buf[0] = B10001000; // 2M Gear
      //message0421.buf[0] = B10010000; // 3M Gear
      //message0421.buf[0] = B10011000; // 4M Gear
      //message0421.buf[0] = B10100000; // 5M Gear
      //message0421.buf[0] = B10101000; // 6M Gear
      //message0421.buf[0] = B10110000; // 7M Gear
      //message0421.buf[0] = B10111000; // 8M Gear
      //message0421.buf[0] = B01000000; // 1 Gear
      //message0421.buf[0] = B01001000; // 2 Gear
      //message0421.buf[0] = B01010000; // 3 Gear
      //message0421.buf[0] = B01011000; // 4 Gear
      //message0421.buf[0] = B01100000; // 5 Gear
      //message0421.buf[0] = B01101000; // 6 Gear
      //message0421.buf[0] = B00100000; // D
      //message0421.buf[0] = B00101000; // D S
      //message0421.buf[0] = B00010000; // R
      message0421.buf[0] = B00001000; // P
      //message0421.buf[0] = B00011000; // N
      //message0421.buf[0] = B00110000; // L 
      message0421.buf[0] = B00001001; // O/D OFF ---> Sport
      **************************************************
      //message0580.buf[3] = B00000001; // Loose Fuel Cap
      //uint16_t rpm = 800;
      //uint16_t rpm1 = 700;
      //message180.buf[0] = highUint16(rpm);
      //message180.buf[1] = lowUint16(rpm1);
      

      message035D.buf[0] = B10000000;
      message035D.buf[1] = B00000001;
      message035D.buf[4] = B00111111;
      message0215.buf[7] = B11111111;
      

      message0358.buf[1] = B00011000;
      message0358.buf[0] = B00000001;
     
      message0358.buf[3] = B00100000;
      message0358.buf[4] = B10000000; // Rear Fog Lamp

      //message0625.buf[1] = B11111111;
      message0625.buf[3] = B10011101;
      message0625.buf[4] = B00100000;

      message0682.buf[0] = B00000000;


      //message0245.buf[0] = B11111111;
      //message0245.buf[1] = B11111111;
      //message0245.buf[2] = B11111111;
      //message0245.buf[3] = B11111111;
      //message0245.buf[4] = B11111111;
      //message0245.buf[5] = B11111111;
      //message0245.buf[6] = B11111111;
      //message0245.buf[7] = B11111111; 

      //message02DE.buf[1] = B11111111;

      //message0280.buf[1] = B11111111;

     
      message05C5.buf[0] = B00000100;
      

      //message0002.buf[7] = B11111111;

      //message0355.buf[5] = B11111111;

      
      
      
        

      
      can.write(message060D);
      can.write(message0354);
      can.write(message0421);
      //can.write(message0182);
      can.write(message0551);
      
      //can.write(message0351);
      can.write(message0215);
      can.write(message0216);
      can.write(message0385);
      can.write(message0358);
     // can.write(message01F9);
      can.write(message035D);
      can.write(message0625);
      can.write(message0682);
      can.write(message05C5);

      can.write(message0002);


      
      can.write(message05C5);

      can.write(message02DE);

      can.write(message0280);

      can.write(message0245);

      can.write(message0355);

      delay(100);
  

  */
}


void canCallback(const CAN_message_t &message) {
  switch (message.id) {
    case (0x023D):{
      uint16_t rpm = combineUint16(message.buf[3], message.buf[4]) * 2.3 * 10;
      message180.buf[0] = highUint16(rpm);
      message180.buf[1] = lowUint16(rpm);

      message551.buf[0] = message.buf[7];
      //message551.buf[5] = message.buf[7];
      //message551.buf[3] = message.buf[4];
      //message060D.buf[4] = message.buf[7];
      //uint16_t test = testMessage16(message.buf[0]);
      //message060D.buf[0] = B01111111;
      //message060D.buf[1] = B01111111;
      //message0215.buf[0] = B00000001;

      //can.write(message180);
      //can.write(message551);
      //can.write(message060D);
      //can.write(message0215);
      // ID 551 [5] = Cruise Set
       }
      break;
   /* case (0x060D):

      if (message060D.buf[0] = B00001000){
      message0358.buf[4] = B10000000; // Rear Fog Lamp
      message0358.buf[1] = B00011000;
      message0358.buf[0] = B00000001;
     
      message0358.buf[3] = B00100000;
      message0385.buf[0] = B00000010;  // TPMS ERROR
      
      can.write(message0358);
      can.write(message0385);
      Serial.println("geht nicht");
      }else{
         message0358.buf[4] = B00000000;
      
      can.write(message0358);
        }
      break;
      */
      case (0x060D):

       message0551.buf[5] = transferFlag(message.buf[1], B00000110, message0551.buf[5], B01000000);

       can.write(message0551);
      Serial.println(message0551.buf[5]);
      
     break;
     
  }
}

void onCarduinoSerialTimeout() {
  carduino.end();
  delay(1000);
  carduino.begin();
}

void onCarduinoSerialEvent(uint8_t type, uint8_t id, BinaryBuffer *payloadBuffer) {
  if (type == 0x61) {
    if (id == 0x0a) {
      // start sniffer
      can.startSniffer();
    } else if (id == 0x0b) {
      // stop sniffer
      can.stopSniffer();
    }
  }
}

uint8_t transferFlag(uint8_t sourceValue, uint8_t sourceMask, uint8_t targetValue, uint8_t targetMask) {
  return readFlag(sourceValue, sourceMask) ? setFlag(targetValue, targetMask) : clearFlag(targetValue, targetMask);
}

bool readFlag(uint8_t value, uint8_t mask) {
  return mask ==(value & mask);
}

uint8_t setFlag(uint8_t value, uint8_t mask) {
  return value | mask;
}

uint8_t clearFlag(uint8_t value, uint8_t mask) {
  return value ^ ~ mask;
}
