#include <Wire.h>
#include <Adafruit_MCP9808.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_MCP9808 MCP9808 = Adafruit_MCP9808();
Adafruit_SSD1306 SSD = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(9600);

    SSD.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    SSD.clearDisplay(); 
    
    MCP9808.begin(0x18);
    MCP9808.setResolution(3);
}

void loop() {
    MCP9808.wake();
  
    float celsius = MCP9808.readTempC();
    Serial.println(celsius);
    MCP9808.shutdown_wake(1);
    delay(200);

    SSD.setFont(&FreeSans9pt7b);
    SSD.clearDisplay();
    SSD.setTextSize(1);
    SSD.setTextColor(WHITE);
    SSD.setCursor(5, 25);
    SSD.println(String(celsius));
    SSD.display();
}
