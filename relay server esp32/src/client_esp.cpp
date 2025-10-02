#include <WiFi.h>
#include "config_secret.h"

const char* ssid = CLIENT_WIFI_SSID;
const char* password = CLIENT_WIFI_PASSWORD;

const char* serverAddress = RELAY_SERVER_IP;
const int serverPort = RELAY_SERVER_PORT;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("Connecting to relay server...");

  if (client.connect(serverAddress, serverPort)) {
    Serial.println("Connected to relay server!");
  } else {
    Serial.println("Connection failed.");
  }
}

void loop() {
  if (client.connected()) {
    // Send a message every 5 seconds
    client.println("Hello from the remote ESP32!");
    Serial.println("Sent message to relay server.");

    // Check for incoming messages from the relay server
    if (client.available()) {
      String received = client.readStringUntil('\n');
      Serial.print("Received from relay: ");
      Serial.println(received);
    }
    delay(5000);
  } else {
    Serial.println("Connection lost. Trying to reconnect...");
    if (client.connect(serverAddress, serverPort)) {
      Serial.println("Reconnected!");
    }
    delay(5000);
  }
}