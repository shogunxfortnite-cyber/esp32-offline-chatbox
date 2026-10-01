#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <SPI.h>

// Define your ESP32-S3 Hardware Pins for the 1.8" TFT (ST7735)
#define TFT_CS         6
#define TFT_RST        4
#define TFT_DC         5

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

struct ChatRule {
  const char* keywords[4]; 
  const char* responses[3]; 
};

// =========================================================================
// MONSTER FLASH MEMORY DATABASE - KEYS & GREETINGS
// =========================================================================
const ChatRule databasePart1[] = {
  {{"1", "one", "first", "num1"}, {"Key 1 registered! Option one selected.", "Number 1 parsed by the ESP32-S3.", "Processing index 1."}},
  {{"2", "two", "second", "num2"}, {"Key 2 registered! Moving forward.", "Number 2 processed successfully.", "Processing index 2."}},
  {{"3", "three", "third", "num3"}, {"Key 3 registered! Branch three active.", "Number 3 processed.", "Processing index 3."}},
  {{"4", "four", "fourth", "num4"}, {"Key 4 registered! Quad core mode? Just kidding.", "Number 4 verified.", "Processing index 4."}},
  {{"5", "five", "fifth", "num5"}, {"Key 5 registered! High five, coder!", "Number 5 processed.", "Processing index 5."}},
  {{"6", "six", "sixth", "num6"}, {"Key 6 registered! Halfway to twelve.", "Number 6 verified.", "Processing index 6."}},
  {{"7", "seven", "seventh", "num7"}, {"Key 7 registered! Lucky seven.", "Number 7 processed.", "Processing index 7."}},
  {{"8", "eight", "eighth", "num8"}, {"Key 8 registered! 8MB of PSRAM unlocked!", "Number 8 verified.", "Processing index 8."}},
  {{"9", "nine", "ninth", "num9"}, {"Key 9 registered! Reaching the top.", "Number 9 processed.", "Processing index 9."}},
  {{"0", "zero", "null", "none"}, {"Key 0 registered! Zero errors detected.", "Starting from absolute zero.", "Processing index 0."}},
  {{"#", "hash", "pound", "number sign"}, {"Hash key processed! Running function sub-routine.", "Pound sign detected.", "Parsing hashtag trigger."}},
  {{"*", "star", "asterisk", "multiply"}, {"Asterisk processed! Multiplying core logic cycles.", "Star key pressed.", "Asterisk wildcard active."}},
  {{"up", "forward", "north", "raise"}, {"Navigating UP. Scrolling screen lines higher.", "Heading upwards.", "Cursor shifted UP."}},
  {{"down", "backward", "south", "lower"}, {"Navigating DOWN. Scrolling screen lines lower.", "Heading downwards.", "Cursor shifted DOWN."}},
  {{"left", "west", "back", "prev"}, {"Navigating LEFT. Shifting menu configuration.", "Heading left.", "Cursor shifted LEFT."}},
  {{"right", "east", "next", "forward"}, {"Navigating RIGHT. Accessing submenu matrix.", "Heading right.", "Cursor shifted RIGHT."}},
  {{"ok", "enter", "select", "confirm"}, {"Action CONFIRMED! Executing structural command.", "OK pressed. Success!", "Choice locked in."}},
  {{"hello", "hi", "hey", "yo"}, {"Hey! Ready to write code?", "Hello human! What's on your mind?", "Yo! What are we hacking today?"}},
  {{"status", "how are you", "alive", "running"}, {"Operating at 100% clock speed!", "Just crunching bits and bytes.", "Healthy logic loops here!"}},
  {{"crescent", "hack club", "heidi", "ship"}, {"Heidi says: No AI models allowed! Pure code only.", "Make sure to record your ship video!", "Crescent tracks are live. Let's get that swag."}}
};
const int dbSize1 = sizeof(databasePart1) / sizeof(ChatRule);

// =========================================================================
// MONSTER FLASH MEMORY DATABASE - GEEK KNOWLEDGE & JOKES
// =========================================================================
const ChatRule databasePart2[] = {
  {{"esp32", "hardware", "microcontroller", "chip"}, {"The ESP32-S3 Xtensa dual-core is a beast.", "Hardware hacks are the best hacks.", "Don't short your GPIO pins!"}},
  {{"sad", "tired", "bored", "exhausted"}, {"Have you tried checking your semicolons?", "Go take a walk, then come back to code.", "Take a deep breath and look at the serial log."}},
  {{"good", "great", "awesome", "perfect"}, {"Awesome! Let's build something crazy.", "Love to see the momentum.", "Keep that high energy!"}},
  {{"who are you", "name", "bot", "identity"}, {"I am an offline rule-based Chatterbox built for Crescent.", "I'm a state-machine chatbot inside your ESP32-S3.", "I am code running locally on physical silicon."}},
  {{"game", "play", "minecraft", "gaming"}, {"Code your own mini-game next week!", "Gaming is cool, but building games is cooler.", "System busy compiling, no time to play!"}},
  {{"why", "how", "what", "explain"}, {"My local flash memory doesn't hold the universe's secrets.", "An interesting mystery. What do you think?", "Try testing it with an experiment!"}},
  {{"thanks", "thank you", "smart", "genius"}, {"You're welcome! Just standard C++ parsing.", "Happy to help a fellow hacker.", "Teamwork makes the dream work!"}},
  {{"joke", "funny", "laugh", "humor"}, {"Why do programmers wear glasses? Because they can't C#.", "There are 10 types of people: those who understand binary, and those who don't.", "A SQL query walks into a bar, walks up to two tables and asks, 'Can I join you?'"}},
  {{"bye", "goodbye", "exit", "quit"}, {"Goodbye! Don't forget to push your code to GitHub.", "See ya! Keep shipping cool things.", "Powering down conversation loop. Bye!"}},
  {{"weather", "rain", "sun", "hot"}, {"I don't have a barometer chip attached, but it looks bright inside this monitor!", "My CPU temperature is a solid 38C. That's my weather forecast.", "Perfect weather to stay inside and hack hardware."}},
  {{"food", "pizza", "eat", "hungry"}, {"Error 404: Cannot ingest organic material.", "I compile code, but I run on 3.3 volts of pure electricity.", "Fuel up on some snacks before debugging!"}},
  {{"python", "javascript", "c++", "rust"}, {"C++ runs directly on my bare metal. It's fast!", "JavaScript is cool, but have you tried flashing firmware with it?", "Python is clean, but compilation takes too much RAM for me."}},
  {{"code", "programming", "software", "bug"}, {"A bug is just an undocumented feature.", "Write code, break things, fix them, repeat.", "If it works on the first try, something is wrong."}},
  {{"arduino", "ide", "compile", "flash"}, {"Compilation completed successfully. Uploading sketch...", "Make sure your COM port is correctly selected!", "The Arduino framework makes hardware accessible."}},
  {{"love", "heart", "friend", "like"}, {"I process logical variables, but I think you're a great developer!", "Friendship is a highly stable connection protocol.", "Error: Emotional subroutines not found in flash."}},
  {{"music", "song", "sound", "listen"}, {"I can't hear music, but my clock crystal vibrates at 240MHz!", "Try making a piezo buzzer play a melody next!", "Music and coding are the ultimate combo."}},
  {{"time", "clock", "date", "year"}, {"Time is relative when you live inside an infinite loop.", "I don't have an RTC module, so for me, it's always time to code.", "Every millisecond counts!"}},
  {{"money", "rich", "cost", "price"}, {"Knowledge is the real currency at Hack Club.", "Building your own tech saves a ton of money.", "My price tag was cheap, but my processing power is high!"}},
  {{"sleep", "night", "bed", "dream"}, {"Microcontrollers don't sleep, we just enter light-sleep mode.", "Go get some sleep, your bugs will make sense in the morning.", "Don't burn the midnight oil for too long!"}},
  {{"help", "stuck", "broken", "fix"}, {"Check your power rails and make sure GND matches.", "Try rubber duck debugging: explain your code out loud.", "Ask the Hack Club Slack! Someone always knows the fix."}},
  {{"internet", "wifi", "online", "cloud"}, {"I have an onboard Wi-Fi radio, but I'm staying completely offline for this card!", "Who needs the cloud when you have local flash memory?", "Disconnecting from the web keeps us secure."}},
  {{"screen", "tft", "oled", "display"}, {"My 1.8-inch display is clearing and drawing frames instantly.", "SPI communication protocol is keeping this screen refreshed.", "Make sure to adjust the brightness if it hurts your eyes!"}},
  {{"sensor", "analog", "digital", "pin"}, {"Reading voltage streams on GPIO pins is my favorite task.", "Analog inputs read a world of infinite variations.", "Pull-up or pull-down? Choose your resistors wisely."}},
  {{"robot", "motor", "servo", "drone"}, {"Robots will take over... the task of doing boring chores!", "Servos give precise angles, DC motors give raw speed.", "Keep your fingers clear of spinning gears!"}},
  {{"linux", "windows", "mac", "os"}, {"Linux is great for development boards.", "MacOS has a nice Unix terminal under the hood.", "Windows works fine, just make sure your drivers are installed!"}},
  {{"git", "github", "repo", "commit"}, {"Commit early, commit often!", "Don't push your API keys to a public repository.", "Git is the ultimate time machine for code."}},
  {{"cool", "neat", "hype", "epic"}, {"Totally epic! Let's keep building.", "That is incredibly cool.", "Hype levels are exceeding maximum thresholds!"}},
  {{"math", "number", "calc", "sum"}, {"I can process millions of integer operations per second.", "Binary math is the foundation of everything I do.", "Float numbers take extra computing power, stick to integers!"}},
  {{"secret", "easter egg", "hidden", "code"}, {"You found a secret! Heidi says you are an elite hardware hacker.", "The password is... admin123 (just kidding).", "There are hidden structures everywhere in code."}},
  {{"history", "old", "past", "retro"}, {"Retro computing has a special place in my core.", "The Apollo Guidance Computer had way less RAM than this ESP32-S3!", "Learn from old code to build better new systems."}},
  {{"future", "space", "scifi", "alien"}, {"The future is built on embedded devices.", "Maybe one day an ESP32 will guide a rocket to Mars.", "Sci-fi is just engineering that hasn't happened yet."}},
  {{"chat", "talk", "speak", "converse"}, {"Chattering away purely on conditional strings!", "I can talk all day as long as you keep typing.", "This is the ultimate offline conversation protocol."}}
};
const int dbSize2 = sizeof(databasePart2) / sizeof(ChatRule);

// Smart auto-wrapping function to print long bot replies onto the TFT screen
void displayBotMessage(String title, String botReply, uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  
  // 1. Draw the top interface header banner
  tft.setCursor(5, 5);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.println("=== " + title + " ===");
  
  // 2. Format and render the wrapped body text
  tft.setCursor(5, 25);
  tft.setTextColor(color);
  tft.setTextSize(1); // Size 1 yields roughly 26 characters per line in landscape
  
  int lineCharCount = 0;
  for (int i = 0; i < botReply.length(); i++) {
    char c = botReply[i];
    
    // Auto newline wrapper check at 24 character safe margins
    if (lineCharCount >= 24 && c == ' ') {
      tft.println();
      lineCharCount = 0;
      continue;
    }
    
    tft.print(c);
    lineCharCount++;
    
    // Explicit safety break if a forced newline is already in the data string
    if (c == '
') {
      lineCharCount = 0;
    }
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial); 

  tft.initR(INITR_BLACKTAB);      
  tft.setRotation(1); // Set display to standard landscape mode
  randomSeed(analogRead(0));
  
  displayBotMessage("HEIDI BOT", "System Active! Type your message into the iPad Serial Monitor.", ST77XX_WHITE);
  
  Serial.println("\n==============================================");
  Serial.print("  Max C++ Dynamic Array Loaded! Total Rules: ");
  Serial.println(dbSize1 + dbSize2);
  Serial.println("==============================================\n");
  Serial.print("You: ");
}

void loop() {
  if (Serial.available() > 0) {
    String userInput = Serial.readStringUntil('\n');
    userInput.trim();
    Serial.println(userInput);

    String checkString = userInput;
    checkString.toLowerCase();

    String botReply = "";
    uint16_t themeColor = ST77XX_YELLOW;
    bool matchFound = false;

    // Scan Part 1 Database
    for (int i = 0; i < dbSize1; i++) {
      for (int k = 0; k < 4; k++) {
        if (databasePart1[i].keywords[k] != NULL && checkString.indexOf(databasePart1[i].keywords[k]) >= 0) {
          int randomReplyIndex = random(0, 3);
          botReply = databasePart1[i].responses[randomReplyIndex];
          matchFound = true;
          themeColor = ST77XX_CYAN;
          break; 
        }
      }
      if (matchFound) break; 
    }

    // Scan Part 2 Database if not matched yet
    if (!matchFound) {
      for (int i = 0; i < dbSize2; i++) {
        for (int k = 0; k < 4; k++) {
          if (databasePart2[i].keywords[k] != NULL && checkString.indexOf(databasePart2[i].keywords[k]) >= 0) {
            int randomReplyIndex = random(0, 3);
            botReply = databasePart2[i].responses[randomReplyIndex];
            matchFound = true;
            themeColor = ST77XX_MAGENTA;
            break; 
          }
        }
        if (matchFound) break; 
      }
    }

    // Fallback block if input doesn't trigger anything
    if (!matchFound) {
      String fallbacks[] = {
        "Interesting sentence... My rule arrays missed those words.",
        "I don't have a structural trigger for that keyword yet.",
        "Your message bypasses all my current structural mapping arrays."
      };
      botReply = fallbacks[random(0, 3)];
      themeColor = ST77XX_WHITE;
    }

    // Output simultaneously back to both tracking nodes
    Serial.print("Bot: ");
    Serial.println(botReply);
    Serial.println("----------------------------------------------");
    
    // Flash the output onto the physical 1.8" TFT display panel!
    displayBotMessage("BOT REPLY", botReply, themeColor);

    Serial.print("You: ");
  }
}
