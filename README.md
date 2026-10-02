# 📟 ESP32-S3 Offline Chatterbox

An AI-free, hardware-driven conversational terminal built for the **Hack Club Crescent Track**. 

This project bypasses heavy neural networks entirely, running 100% locally on the bare silicon of an **ESP32-S3 (N16R8)**. It uses a deterministic keyword-matrix routing system to instantly print responses to a computer terminal and a physical 1.8" SPI TFT display simultaneously. It works out-of-the-box over a standard USB-C cable, making it fully compatible with laptops and the **iPad 10th Gen**.

---

### 📺 Video Demo
Check out the system parsing inputs and driving the dual-display hardware in real time:

[![ESP32-S3 Chatterbox Demo](https://youtube.com)](https://youtu.be/DUuMElx43R8?si=kXrE2kzNuWOhgRdj "")

*(Click the image above or use [this link](https://youtu.be/DUuMElx43R8?si=kXrE2kzNuWOhgRdj "") to watch the video demonstration)*

---

### 🛠️ Hardware Requirements & Cost
The total package costs roughly **\$25 USD** (\$20 – \$31 depending on your supplier):
* **1x** ESP32-S3 Dev Board (N16R8 variant, 16MB Flash / 8MB PSRAM)
* **1x** 1.8" SPI TFT Display (ST7735 Driver, 128x160 resolution)
* **1x** USB-C to USB-C Data Cable
* **1x** Solderless Breadboard
* **1x** Pack of Male-to-Female Jumper Wires

---

### 🔌 Wiring Guide
Connect the 1.8" TFT screen to your ESP32-S3 using this pin configuration:

| TFT Screen Pin | ESP32-S3 Pin | Purpose |
| :--- | :--- | :--- |
| **GND** | GND | Common Ground |
| **VCC / VDD** | 3V3 | Logic Power (3.3V) |
| **SCL / SCK** | GPIO 12 | SPI Clock |
| **SDA / MOSI** | GPIO 11 | SPI Data Line |
| **RES / RESET** | GPIO 4 | Screen Reset |
| **DC / RS / A0** | GPIO 5 | Data / Command Control |
| **CS** | GPIO 6 | Chip Select |
| **LEDA / BL** | 3V3 | Display Backlight (Must be powered) |

---

### 💻 Software Setup & Dependencies
Before compilation, install these libraries inside the **Arduino IDE Library Manager** (or via `platformio.ini`):
* **Adafruit GFX Library**
* **Adafruit ST7735 and ST7789 Library**

---

### 🚀 Flashing & Build Steps
1. **Open the Project:** Launch Arduino IDE and load your `.ino` sketch file.
2. **Configure Board Settings:** 
   * Go to **Tools > Board** and select `ESP32S3 Dev Module`.
   * Set **Flash Size** to `16MB (128Mb)`.
   * Set **Partition Scheme** to `16M Flash (3MB APP/9.9MB FATFS)` or any scheme maximizing your `PROGMEM` capacity.
   * Enable **USB CDC On Boot** (`Enabled`) so serial outputs pass directly through the native USB-C port.
3. **Compile & Upload:** Plug your ESP32-S3 into your device using a USB-C cable and click the **Upload** arrow.

---

### 💬 How to Use It
1. Leave the ESP32-S3 plugged into your computer or iPad 10.
2. Open any standard serial terminal app (like the Arduino Serial Monitor or Serial Pro on iOS).
3. Set the baud rate to **115200**.
4. Type a message or keyword phrase into the entry bar and hit **Send**.
5. Watch the Chatterbox parse your text, print the automated response instantly back to your terminal, and dynamically wrap the text to display it on the physical 1.8" screen.

---

### 📜 License
Developed for Hack Club Crescent. Built by a teenage hacker, running on physical hardware, shipped to the global slack network ecosystem. 

*"You ship, we ship."* 🚀
