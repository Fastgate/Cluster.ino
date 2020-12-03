#ifndef BCM_H
#define BCM_H

#include <Arduino.h>
#include <arduinoIO.h>

class Bcm {
  public:
    Bcm() {}
    
  //////////////////////////////////////////////
 ///////////////// DOOR SWITCH ////////////////
//////////////////////////////////////////////    
    boolean isFLDoorOpen() {
      return this->FLDoorSensor->getState();
    }
    boolean isFRDoorOpen() {
      return this->FRDoorSensor->getState();
    }
    boolean isRLDoorOpen() {
      return this->RLDoorSensor->getState();
    }
    boolean isRRDoorOpen() {
      return this->RRDoorSensor->getState();
    }
    boolean isBackDoorOpen() {
      return this->backDoorSensor->getState();
    }
    boolean isAnyDoorOpen() {
      return this->isFLDoorOpen() || this->isFRDoorOpen() || this->isRLDoorOpen() || this->isRRDoorOpen() || this->isBackDoorOpen();
    }
  //////////////////////////////////////////////////////  
 ////////////////// REAR FOG //////////////////////////
////////////////////////////////////////////////////// 
    
    void toggleRearFogLight() {
      this->RearFogRelay->toggle(!this->RearFogRelay->getState());
    }
    boolean isRearFogLightActive() {
      return this->RearFogRelay->getState() == HIGH;
      //message0358.buf[4] = B10000000; // Rear Fog Lamp
      //can.write(message0358);
    }
  //////////////////////////////////////////////////   
 ////////// KEYLESS ENTRY ///////////////////////// 
/////////////////////////////////////////////////

    boolean isBluetoothConnected() {
      return this->BluetoothConnected->getState() ==HIGH;
    }
    boolean isClutchSwitchActive() {
      return this->ClutchSwitch->getState();
    }
    boolean isstatusLEDActive() {
      return this->statusLED->getState() == HIGH;
    }
    void setstatusLED(boolean newState) {
      this->statusLED->toggle(newState);
    }
    boolean isNatsRlyActive() {
      return this->NatsRLY->getState() == HIGH;
    }
    void setNatsRLY(boolean newState) {
      this->NatsRLY->toggle(newState);
    }
    boolean isStartFreeRelayActive(){
      return this->StartFreeRelay->getState() == HIGH;
    }
    void setStartFreeRelay(boolean newState) {
      this->StartFreeRelay->toggle(newState);
    }
  /////////////////////////////////////////////////////////////////    
 ////////// Door Switch for Keyless Entry //////////////////////// 
///////////////////////////////////////////////////////////////// 
    boolean isDoorswitchActive(){
      return this->DoorSwitch->getState() == HIGH;
    }
    void setDoorSwitch(boolean newState) {
      this->DoorSwitch->toggle(newState);
    }
    
    
    void washHeadlights(unsigned int duration) {
      this->headlightWasherRelay->set(HIGH, duration);
    }

    void updateCan(CAN_message_t canMessage) {
      this->FLDoorSensor->updateCan(canMessage);
      this->FRDoorSensor->updateCan(canMessage);
      this->RLDoorSensor->updateCan(canMessage);
      this->RRDoorSensor->updateCan(canMessage);
           
    }
    
    void update(void (*bcmCallback)(Button *headlightWasherButton, Bcm *bcm)) {
           
      this->headlightWasherButton->update();
      this->headlightWasherRelay->update();
      this->BluetoothConnected->getState();

      
      bcmCallback(this->headlightWasherButton, this);
    }
  private:
    
    CanInput *FLDoorSensor              = new CanInput(0x060D, 0, B00001000);
    CanInput *FRDoorSensor              = new CanInput(0x060D, 0, B00010000);
    CanInput *RLDoorSensor              = new CanInput(0x060D, 0, B00100000);
    CanInput *RRDoorSensor              = new CanInput(0x060D, 0, B01000000);
    CanInput *backDoorSensor            = new CanInput(0x0358, 2, B00000001);

    DigitalInput  *BluetoothConnected   = new DigitalInput(4, 20, HIGH, INPUT);
    DigitalInput  *StartButtonStatus    = new DigitalInput(20, 20, HIGH, INPUT);
    DigitalInput  *ClutchSwitch         = new DigitalInput(17, 20, HIGH, INPUT);
    DigitalOutput *StartFreeRelay       = new DigitalOutput(2, HIGH);  // If Smartphone connected->switch RLY
    DigitalOutput *WindowDown           = new DigitalOutput(5, HIGH);
    DigitalOutput *WindowUp             = new DigitalOutput(6, HIGH);
    DigitalOutput *NatsRLY              = new DigitalOutput(9, HIGH);  // If Smartphone connected->switch RLY
    DigitalOutput *DoorSwitch           = new DigitalOutput(10, HIGH); // its for the Keyless Entry Modul
    Button *headlightWasherButton       = new Button(new DigitalInput(12, 20, HIGH, INPUT_PULLUP));
    TimedOutput *headlightWasherRelay   = new TimedOutput(new DigitalOutput(11));
    DigitalOutput *RearFogRelay         = new DigitalOutput(18, HIGH);
    DigitalOutput *statusLED            = new DigitalOutput(13, HIGH);
    
};

#endif
