#include "CloudMqttConnect.h"
#include "Arduino.h"
//#include "PubSubClient.h"
#include "Helper.h"

void CloudMqttConnection::subscribe()
{
  // for(int i=0; i<=5; i++)
  // {
  //   client.subscribe(topics[i]);
  // }
  client.subscribe("SD/light/kitchen");
  //client.subscribe("SH/light/bedroom");
}

PubSubClient CloudMqttConnection::connectToMqttServer(){

    Serial.println("\nConnecting to MQTT 1");
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callbackMethod);
  
  while (!client.connected()) {
    Serial.print("\nConnecting to MQTT...");
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.print("\nconnected");
 
    } else {
      Serial.print("\nfailed with state ");
      Serial.print(client.state());
      //delay(1000);
    }
    subscribe();
  }

  return client;
}

void CloudMqttConnection::publish(const char *topic, const char *message){
  if(client.publish(topic, message)){
    Serial.println("Published ok");
  }else{
    Serial.println("Published not ok");
  }
}



