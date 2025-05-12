# 🦾 Muscle Cramp Detection Wearable Device

This project is a wearable biomedical IoT solution that detects muscle cramps using an EMG sensor and alerts the user via Telegram in real-time. It uses an **ESP32 microcontroller**, **EMG sensor with surface electrodes**, and the **Telegram Bot API** for sending messages when abnormal muscle activity is detected.

---

## 📸 Project Overview

![Project Demo Image or Circuit Diagram – optional]

---

## 🧠 Features

- 📡 Real-time detection of high EMG signals (indicating potential cramps)
- 🔔 Instant alert sent to user via Telegram bot
- 🔋 Compact, low-power wearable setup using ESP32
- 🔧 Threshold-based detection for easy customization

---

## 🔧 Hardware Components

| Component             | Quantity | Description                           |
|----------------------|----------|---------------------------------------|
| ESP32 Development Board | 1        | Wi-Fi microcontroller                 |
| EMG Sensor Module     | 1        | e.g., MyoWare or similar              |
| Surface Electrodes    | 3        | For connecting EMG sensor to skin     |
| Jumper Wires          | As needed | For circuit connections              |
| Power Source (Battery/USB) | 1        | To power ESP32                        |

---

## 🛠️ Software and Libraries

- **Arduino IDE**
- **UniversalTelegramBot.h**
- **WiFiClientSecure.h**
- **WiFi.h**

---

## 🔌 Circuit Connection

| EMG Sensor Pin | ESP32 Pin |
|----------------|-----------|
| Vcc            | 3.3V      |
| GND            | GND       |
| OUT            | GPIO34 (Analog Input) |

> Note: Use a resistor divider if your EMG output is 5V. GPIO34 is an input-only analog pin on ESP32.

---

## 🧾 Code Logic

- Connect to Wi-Fi
- Read EMG analog values from GPIO34
- If value exceeds a threshold (e.g., 2000), send an alert to the Telegram bot
- Delay to prevent message spamming

---

## 🔐 Telegram Bot Setup

1. Search for `@BotFather` on Telegram
2. Create a bot and copy the token
3. Get your chat ID from [@userinfobot](https://t.me/userinfobot)
4. Add your bot token and chat ID to the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
const char* botToken = "YOUR_TELEGRAM_BOT_TOKEN";
const char* chatId = "YOUR_TELEGRAM_CHAT_ID";
