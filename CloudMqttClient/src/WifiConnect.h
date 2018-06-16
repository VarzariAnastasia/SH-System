

class WifiConnection{
  private:
    const char* ssid;
    const char* password;

public:
     //WifiConnection(){};
     WifiConnection(const char* ssid, const char* password){
        this->ssid = ssid;
        this->password = password;
     }
    ~WifiConnection(){};

public:
    void connectToWifi();


};