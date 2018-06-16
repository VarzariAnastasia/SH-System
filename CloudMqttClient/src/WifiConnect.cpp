#include <Arduino.h>
#include <WiFi.h>
#include "WifiConnect.h"

void WifiConnection::connectToWifi(){
    WiFi.begin(ssid, password);
    delay(500);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("\nConnecting to WiFi..");
  }
  Serial.print("\nConnected to the WiFi network");
}

