#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>


const char* ssid = "Galaxy M31D07A";
const char* password = "nqqd5512";
const char* botToken = "6562253597:AAFCc6LuGEgBdqC-UhJuTPZ3MUeUTeWXkCI";
const char* chatId = "668905947";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

const int emgPin = 34; // Analog pin connected to EMG sensor

void setup() {
  Serial.begin(115200);
  //delay(1000);
  
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  Serial.println("Setup complete");
}

void loop() {
  int emgValue = analogRead(emgPin);
  Serial.println(emgValue);
  
  if (emgValue > 2000) {
    sendMessage("EMG sensor detected reading over 2000!");
    delay(5000); // Wait for 5 seconds to avoid sending multiple messages
  }
  
  delay(100); // Delay between readings
}

void sendMessage(String message) {
  if (bot.sendMessage(chatId, message, "")) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Failed to send message");
  }
}
