#include "ArduinoHelper.h"

class Bedroom{
private:
    int bedroomLightPotPin;
    int bedroomLightdPin;
    int dutyCycle;
    long potentValue;
    int oldAnalogValue;
    bool potValueChanged;    
    byte b[4];
public:
    Bedroom(int bedroomLightPotPin, int bedroomLightdPin){
        this->bedroomLightPotPin = bedroomLightPotPin;
        this->bedroomLightdPin = bedroomLightdPin;
        dutyCycle = 0;
        potentValue = 0;
        oldAnalogValue = 0;        
        potValueChanged = false;
        
        for(int i=0; i<=3; i++){
            b[i]=0;
        }
    }
    ~Bedroom(){};

    //light
    void dimmingLed();
    void bedroomLightSetup(int dutyCycle);
    //SHT
   

  
};