#ifndef BCM_H
#define BCM_H

#include <Arduino.h>
#include <arduinoIO.h>

class Bcm {
  public:
    Bcm() {}
    
    void toggleRearFogLight() {
      this->RearFogRelay->toggle(!this->RearFogRelay->getState());
    }
    boolean isRearFogLightActive() {
      return this->RearFogRelay->getState() == HIGH;
      //message0358.buf[4] = B10000000; // Rear Fog Lamp
      //can.write(message0358);
    }
    
    void washHeadlights(unsigned int duration) {
      this->headlightWasherRelay->set(HIGH, duration);
    }
    
    void update(void (*bcmCallback)(Button *headlightWasherButton, Bcm *bcm)) {
           
      this->headlightWasherButton->update();
      this->headlightWasherRelay->update();

      
      bcmCallback(this->headlightWasherButton, this);
    }
  private:
    
    Button *headlightWasherButton     = new Button(new DigitalInput(12, 20, LOW, INPUT));
    TimedOutput *headlightWasherRelay = new TimedOutput(new DigitalOutput(11));
    DigitalOutput *RearFogRelay       = new DigitalOutput(18, HIGH);
};

#endif