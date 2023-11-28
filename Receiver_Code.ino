#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RH_ASK.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
RH_ASK rf_driver;

void setup() {
  Serial.begin(9600);
  rf_driver.init();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("SYSTEM");
  lcd.setCursor(3, 2);
  lcd.print("INITIALIZATION");
  delay(2000);
}

void loop() {
  uint8_t buf[20];
  uint8_t buflen = sizeof(buf);
  
  if (rf_driver.recv(buf, &buflen)) {
    // Check if the received message is "Am Ok"
    if (checkStringMatch(buf, buflen, "Am Ok")) {
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("MESSAGE CONVEYOR");
      lcd.setCursor(0, 1);
      lcd.print("Decoding Message...");
      lcd.setCursor(6,2);
      lcd.print("MESSAGE");
      lcd.setCursor(0,3);
      lcd.print("Am Ok");
      delay(1000);
    }else if(checkStringMatch(buf, buflen, "Hello There!")){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("MESSAGE CONVEYOR");
      lcd.setCursor(0, 1);
      lcd.print("Decoding Message...");
      lcd.setCursor(6,2);
      lcd.print("MESSAGE");
      lcd.setCursor(0,3);
      lcd.print("Hello There!");
      delay(1000);
    }else if(checkStringMatch(buf, buflen, "Move to the Right")){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("MESSAGE CONVEYOR");
      lcd.setCursor(0, 1);
      lcd.print("Decoding Message...");
      lcd.setCursor(6,2);
      lcd.print("MESSAGE");
      lcd.setCursor(0,3);
      lcd.print("Move to the Right");
      delay(1000);
    }else if(checkStringMatch(buf, buflen, "Move to the Left")){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("MESSAGE CONVEYOR");
      lcd.setCursor(0, 1);
      lcd.print("Decoding Message...");
      lcd.setCursor(6,2);
      lcd.print("MESSAGE");
      lcd.setCursor(0,3);
      lcd.print("Move to the Left");
      delay(1000);
    }else if(checkStringMatch(buf, buflen, "Am Done")){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("MESSAGE CONVEYOR");
      lcd.setCursor(0, 1);
      lcd.print("Decoding Message...");
      lcd.setCursor(6,2);
      lcd.print("MESSAGE");
      lcd.setCursor(0,3);
      lcd.print("Am Done");
      delay(1000);
    }
  }
}

// Function to check if the received message matches the expected string
bool checkStringMatch(uint8_t* received, uint8_t length, const char* expected) {
  if (length != strlen(expected)) {
    return false; // If lengths are different, strings cannot match
  }

  for (int i = 0; i < length; i++) {
    if (received[i] != expected[i]) {
      return false; // If any character doesn't match, strings are different
    }
  }

  return true; // All characters match
}
