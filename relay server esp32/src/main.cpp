#include <Arduino.h>
#include <WiFi.h>
#include "config_secret.h"

const char* ssid = RELAY_WIFI_SSID;
const char* password = RELAY_WIFI_PASSWORD;

WiFiServer server(51341); // Listen on port 51341

WiFiClient client1;
WiFiClient client2;

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(WiFi.macAddress());
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("Local IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started. Awaiting client connections...");
}

void loop() {
  // Check for new clients
  if (!client1 || !client2) {
    WiFiClient newClient = server.available();
    if (newClient) {
      if (!client1) {
        client1 = newClient;
        Serial.println("Client 1 connected.");
      } else if (!client2) {
        client2 = newClient;
        Serial.println("Client 2 connected.");
      }
    }
  }

  // Handle communication
  if (client1 && client1.connected()) {
    if (client1.available()) {
      String data = client1.readStringUntil('\n');
      Serial.print("Received from Client 1: ");
      Serial.println(data);
      if (client2 && client2.connected()) {
        client2.print(data);
      }
    }
  }

  if (client2 && client2.connected()) {
    if (client2.available()) {
      String data = client2.readStringUntil('\n');
      Serial.print("Received from Client 2: ");
      Serial.println(data);
      if (client1 && client1.connected()) {
        client1.print(data);
      }
    }
  }
}