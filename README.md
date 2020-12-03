# Can Data

## ID 0x0351
      
    message0351.buf[5] = B00001000; // NO KEY Detected
    message0351.buf[5] = B00000100; // Steering wheel & Push Button
    message0351.buf[5] = B00000001; // Brake + Push Button
    message0351.buf[5] = B00000011; // Key ID Incorrect
    message0351.buf[5] = B00000111; // Key Batterie LOW
    message0351.buf[5] = B00001111; // Push Brake and Start Button to drive
    message0351.buf[5] = B00011111; // fast beep
    message0351.buf[6] = B10000000; // beep beep
    message0351.buf[7] = B11111111;
      
## ID 0x0358

    message0358.buf[4] = B10000000; // Rear Fog Lamp

## ID 0x0385
      
    message0385.buf[0] = B00000010; // TPMS ERROR
    message0385.buf[1] = B00000001; // Tire Pressure LOW RL
    message0385.buf[1] = B00000010; // Tire Pressure LOW RL 
    message0385.buf[1] = B00000100; // Tire Pressure LOW FL
    message0385.buf[1] = B00001000; // Tire Pressure LOW FR
    message0385.buf[1] = B00010000; // Flat Tire
      
## ID 0x0421

    message0421.buf[0] = B10000000; // 1M Gear
    message0421.buf[0] = B10001000; // 2M Gear
    message0421.buf[0] = B10010000; // 3M Gear
    message0421.buf[0] = B10011000; // 4M Gear
    message0421.buf[0] = B10100000; // 5M Gear
    message0421.buf[0] = B10101000; // 6M Gear
    message0421.buf[0] = B10110000; // 7M Gear
    message0421.buf[0] = B10111000; // 8M Gear
    message0421.buf[0] = B01000000; // 1 Gear
    message0421.buf[0] = B01001000; // 2 Gear
    message0421.buf[0] = B01010000; // 3 Gear
    message0421.buf[0] = B01011000; // 4 Gear
    message0421.buf[0] = B01100000; // 5 Gear
    message0421.buf[0] = B01101000; // 6 Gear
    message0421.buf[0] = B00100000; // D
    message0421.buf[0] = B00101000; // D S
    message0421.buf[0] = B00010000; // R
    message0421.buf[0] = B00001000; // P
    message0421.buf[0] = B00011000; // N
    message0421.buf[0] = B00110000; // L 
    message0421.buf[0] = B00001001; // O/D OFF ---> Sport
     
## ID 0x0551

    message0551.buf[5] = B01010000; // Cruise
    message0551.buf[5] = B01000000; // Cruise SET
    message0551.buf[5] = B10100000; // Cruise Limit
    message0551.buf[1] = B00000111;
    message0551.buf[5] = B00000011;

## ID 0x0580
      
    message0580.buf[3] = B00000001; // Loose Fuel Cap
      
## ID 0x060D

    message060D.buf[0] = B00000110;
    message060D.buf[1] = B10010111;
    message060D.buf[2] = B11101100;
    message060D.buf[3] = B00000000;
    message060D.buf[3] = B00101010; // 4x Beep
