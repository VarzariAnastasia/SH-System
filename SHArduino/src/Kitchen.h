
class Kitchen{
private:
    int kitchenLightState;
    int kitchenLightPin;
    int kitchenButtonLightPin;
  
    int prevLightState;
    int currLightState;
    int nextLightState;

public:
    bool kitchenLightESP;
    bool buttonPressed;
    Kitchen(int kitchenLightPin, int kitchenButtonLightPin){
        this->kitchenLightPin = kitchenLightPin; 
        this->kitchenButtonLightPin = kitchenButtonLightPin;
        buttonPressed= 0;
        prevLightState = 0;
        currLightState = 0;
        kitchenLightState = 0;
        nextLightState = 0;
        kitchenLightESP = false;
    }
    ~Kitchen(){};

    int debounce(int lightState);
    //void kitchenLightButtonPressed();
    void setKitchenLightState();
    void sendKitchenLightState();
    
    
};