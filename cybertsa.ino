const char text_0[]  PROGMEM= "";

// #include <U8x8lib.h>
// #include <MUIU8g2.h>
#include <U8g2lib.h>

#include <TimerOne.h>
#include <GyverPower.h>
#include <powerConstants.h>
#include <EEPROM.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

const uint32_t CHRG = A2;
const uint32_t STDBY = A3;

size_t id = 0;

void setup() {
  power.autoCalibrate();
  power.hardwareDisable(PWR_ADC | PWR_TIMER1);
  power.setSystemPrescaler(PRESCALER_2);
  power.setSleepMode(STANDBY_SLEEP);
  
  pinMode(CHRG, INPUT_PULLUP);
  pinMode(STDBY, INPUT_PULLUP);
  
  u8g2.begin();
  u8g2.enableUTF8Print();

  // low brightness
  u8x8_cad_StartTransfer(u8g2.getU8x8());
  u8x8_cad_SendCmd(u8g2.getU8x8(), 0x0db);
  u8x8_cad_SendArg(u8g2.getU8x8(), 1 << 4);
  u8x8_cad_EndTransfer(u8g2.getU8x8());

  // u8g2.setFont(u8g2_font_5x7_tf);
  u8g2.setFont(u8g2_font_6x12_t_cyrillic);

  randomSeed(analogRead(0));
  // EEPROM.write(0, 0);

  id = EEPROM.read(0);
}

uint16_t counter = 0;
const uint16_t SHOW_COUNT = 3005; // 4 = 115s
const uint16_t MAX_DELAY = 64;


const size_t TEXT_LEN = 1;
const char *const TEXT[] PROGMEM = {text_0};

uint16_t show_counter = 0;

char buffer[30];

void loop() {
  u8g2.setPowerSave(0);
  u8g2.setDrawColor(1);
  while(digitalRead(STDBY) == 1 && digitalRead(CHRG) == 0) {
    u8g2.clearBuffer();
    u8g2.drawPixel(random(128), random(32));
    u8g2.sendBuffer();
    delay(50);
  }

  while(digitalRead(STDBY) == 0 && digitalRead(CHRG) == 1) {
    u8g2.clearBuffer();
    for(uint16_t i = 0; i < 500; i++) {
      u8g2.drawPixel(random(128), random(32));
    }
    u8g2.sendBuffer();
    delay(50);
  }

  u8g2.setDrawColor(1);
  if(show_counter < SHOW_COUNT * 0.33) {
    u8g2.drawTriangle(
      random(0, 64), random(0, 16),
      random(0, 64), random(8, 24),
      random(0, 64), random(16, 32)
    );
    u8g2.sendBuffer();
  }

  delay(10);

  u8g2.setDrawColor(1);
  if(show_counter < SHOW_COUNT * 0.5) {
    u8g2.drawTriangle(
      random(63, 128), random(0, 16),
      random(63, 128), random(8, 24),
      random(63, 128), random(16, 32)
    );
    u8g2.sendBuffer();
  }

  delay(12);

  int I = random(0, 20);
  for(uint16_t i = 0; i < I; i++) {
    u8g2.drawPixel(random(128), random(32));
    u8g2.sendBuffer();
    delay(2);
  }
  
  
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 10);
  if(id < TEXT_LEN - 1) {
    strcpy_P(buffer, (char *)pgm_read_word(&(TEXT[id * 3 + 0])));
    u8g2.print(buffer);
    u8g2.setCursor(0, 20);
    strcpy_P(buffer, (char *)pgm_read_word(&(TEXT[id * 3 + 1])));
    u8g2.print(buffer);
    u8g2.setCursor(0, 30);
    strcpy_P(buffer, (char *)pgm_read_word(&(TEXT[id * 3 + 2])));
    u8g2.print(buffer);
  } else {
    u8g2.drawTriangle(
      random(128), random(32),
      random(128), random(32),
      random(128), random(32)
    );
  }
  u8g2.drawTriangle(
    0,0,
    0,0,
    0,0
  );
  
  u8g2.setDrawColor(0);
  if(show_counter < SHOW_COUNT * 0.75) {
    u8g2.drawTriangle(
      random(0, 64), random(0, 16),
      random(0, 64), random(8, 24),
      random(0, 64), random(16, 32)
    );
  }

  u8g2.setDrawColor(0);
  if(show_counter < SHOW_COUNT * 0.9) {
    u8g2.drawTriangle(
      random(63, 128), random(0, 16),
      random(63, 128), random(8, 24),
      random(63, 128), random(16, 32)
    );
  }
  
  u8g2.sendBuffer();
  
  power.sleep(SLEEP_1024MS);
  
  u8g2.setDrawColor(0);
  uint32_t c = 0;
  uint32_t r = random(98, 110);
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 1000; j++) {
      u8g2.drawPixel((c / 32) % 128, c % 32);
      c += r - j/10;
    }
    u8g2.sendBuffer();
  }
  
  u8g2.setPowerSave(1);

  if(!(digitalRead(STDBY) == 1 && digitalRead(CHRG) == 0)) {
    for(int i = 0; i < MAX_DELAY; i++) {
      if(random(128) > 64) {
        power.sleep(SLEEP_512MS);
      }
      if(random(128) > 64) {
        u8g2.setPowerSave(0);
        delay(1);
        u8g2.clearBuffer();
        u8g2.setDrawColor(1);
        int I = random(0, 20);
        for(uint16_t i = 0; i < I; i++) {
          u8g2.drawPixel(random(128), random(32));
        }
        u8g2.sendBuffer();
        delay(25);
        u8g2.setPowerSave(1);
      }
    }
  }

  show_counter++;
  if(show_counter > SHOW_COUNT) {
    show_counter = 0;
    if(id < TEXT_LEN - 1) {
      id++;
    }
    EEPROM.write(0, id);
  }
}
