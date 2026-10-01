# 📟 ESP32-S3 Offline Chatterbox (Hack Club Crescent Track)

A high-capacity, rule-based offline conversational chatterbox built for the **Hack Club Crescent** program. This project is engineered strictly under the **"No AI Models"** constraint, running completely locally on the bare silicon of an **ESP32-S3 (N16R8)** microcontroller and outputting responses simultaneously to a computer terminal and a **1.8" SPI TFT Display**.

---

## 🚀 Project Features
* **100% AI-Free Architecture:** Uses deterministic multi-keyword matrix parsing and string routing instead of resource-heavy neural networks.
* **Dual-Output Interface:** Sends conversations back to your Serial Monitor while dynamically rendering text onto a physical 1.8" TFT screen.
* **Smart Text Wrapping:** Automatically calculates characters per line to ensure text doesn't cut off the edges of the narrow display.
* **N16R8 Optimized Array:** Stores hundreds of trigger keyword variations and randomized responses directly inside the 16MB program flash partition.
* **iPad 10th Gen Compatible:** Designed to be wired, compiled, and flashed directly from a mobile USB-C environment.

---

## 🔌 Hardware Wiring Guide

Connect your **1.8" TFT (ST7735 Driver)** to the **ESP32-S3** dev board using the following pin map:

| TFT Screen Pin | ESP32-S3 Pin | Purpose |
| :--- | :--- | :--- |
| **GND** | **GND** | Ground Common Rail |
| **VCC / VDD** | **3V3** | Logic Power (3.3 Volts) |
| **SCL / SCK / CLK**| **GPIO 12** | SPI Clock |
| **SDA / MOSI / SDI**| **GPIO 11** | SPI Data Line |
| **RES / RESET** | **GPIO 4** | Screen Reset Trigger |
| **DC / RS / A0** | **GPIO 5** | Data / Command Line |
| **CS** | **GPIO 6** | Chip Select |
| **LEDA / BL / LITE**| **3V3** | Display Backlight Power |

*Note: The Backlight pin (`LEDA`/`BL`) must be tied to a power source, or the screen panel will remain black.*

---

## 🛠️ Software & Library Requirements

Before compiling the code, ensure the following core libraries are installed via the Arduino Library Manager or your project configuration file:
* **Adafruit GFX Library**
* **Adafruit ST7735 and ST7789 Library**

---

## 📱 Flashing and Running via iPad (10th Gen)

You don't need a traditional computer to compile or interact with this script! Follow these instructions:

### 1. Connect the Hardware
* Use a standard **USB-C to USB-C cable** to connect your iPad 10 directly into the **UART / COM port** of your ESP32-S3 board.
* The onboard power light should activate immediately.

### 2. Flash the Firmware
* Open **Google Chrome** or a Web-Serial compatible environment on your iPad.
* Head to the **[Adafruit Web Serial ESPTool](https://github.io)**.
* Set your target Baud Rate to **115200**, tap **Connect**, select your ESP32-S3 from the device pop-up window, and load your compiled binary.

### 3. Operate the Chatterbox
* Open a Serial Console terminal window (e.g., using the Adafruit tool or the **Blink Shell** app on iOS).
* Ensure your connection line ending is configured to send a newline character (`\n`).
* Type phrases like `hello`, `hack club`, `error`, `up`, or numbers like `8` and hit enter. Watch the response trigger on both the text console and your desktop screen assembly.

---

## 📜 Code License & Submission
Developed for **Hack Club Crescent**. Built by a teenage hacker, running on physical hardware, shipped to the global slack network ecosystem. 

**"You ship, we ship."** 🚀
