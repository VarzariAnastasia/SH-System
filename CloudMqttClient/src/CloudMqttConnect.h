#include "PubSubClient.h"

class CloudMqttConnection{

private:
const char* mqttServer;
int mqttPort;
const char* mqttUser;
const char* mqttPassword;
PubSubClient client;

public:
CloudMqttConnection(PubSubClient client, const char* mqttServer, const int mqttPort, const char* mqttUser, const char* mqttPassword){
    this->mqttServer = mqttServer;
    this->mqttPort = mqttPort;
    this->mqttUser = mqttUser;
    this->mqttPassword = mqttPassword;
    this->client = client;
}
~CloudMqttConnection(){};
 
 PubSubClient connectToMqttServer(); 
 void subscribe();
 void publish(const char *topic, const char *message);

};

