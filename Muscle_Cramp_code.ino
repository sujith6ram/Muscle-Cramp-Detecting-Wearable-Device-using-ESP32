#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>


const char* ssid = "<WIFI-NAME>";
const char* password = "<WIFI-PASSWORD>";
const char* botToken = "<TELEGRAM-BOT-TOKEN>";
const char* chatId = "<TELEGRAM-ACCOUNT-CHATID>";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

// EMG SENSOR PIN
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
  
  // CHOSE A APT THRESHOLD VALUE ACCORDING TO THE BODY CONDITIONS(eg: 2000)
  if (emgValue > 2000) {
    sendMessage("EMG sensor detected reading over 2000!");
    delay(5000); // Wait for 5 seconds to avoid sending multiple messages
  }
  
  delay(100); // Delay between readings
}

// SENDS MESSAGE TO THE TELEGRAM-BOT
void sendMessage(String message) {
  if (bot.sendMessage(chatId, message, "")) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Failed to send message");
  }
}
