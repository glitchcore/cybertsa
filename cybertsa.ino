const char text_0[]  PROGMEM= "Нужно";
const char text_1[]  PROGMEM= "  подождать";
const char text_2[]  PROGMEM= " немного";
const char text_3[]  PROGMEM= "  для первого";
const char text_4[]  PROGMEM= "   раза";
const char text_5[]  PROGMEM= "может и норм";
const char text_6[]  PROGMEM= "эта история";
const char text_7[]  PROGMEM= "закончилась";
const char text_8[]  PROGMEM= "мы можем начать новую";
const char text_9[]  PROGMEM= "";
const char text_10[] PROGMEM = "стираю твое";
const char text_11[] PROGMEM = "    присутствие";
const char text_12[] PROGMEM = "";
const char text_13[] PROGMEM = "как ты";
const char text_14[] PROGMEM = "получше?";
const char text_15[] PROGMEM = "как же докричаться";
const char text_16[] PROGMEM = "теперь";
const char text_17[] PROGMEM = "до тебя";
const char text_18[] PROGMEM = "выглядишь как";
const char text_19[] PROGMEM = "вполне прорастающая";
const char text_20[] PROGMEM = " фасоль";
const char text_21[] PROGMEM = "я даже ничего";
const char text_22[] PROGMEM = "про твой перфоманс";
const char text_23[] PROGMEM = "не знаю";
const char text_24[] PROGMEM = "меня вот";
const char text_25[] PROGMEM = "в работу засосало";
const char text_26[] PROGMEM = "";
const char text_27[] PROGMEM = "";
const char text_28[] PROGMEM = "*тяжело вздыхаю*";
const char text_29[] PROGMEM = "";
const char text_30[] PROGMEM = "магнитное поле";
const char text_31[] PROGMEM = "изогнутого соленоида";
const char text_32[] PROGMEM = "";
const char text_33[] PROGMEM = "у нас тут";
const char text_34[] PROGMEM = "тоже море";
const char text_35[] PROGMEM = "";
const char text_36[] PROGMEM = "мне важно было бы";
const char text_37[] PROGMEM = "услышать";
const char text_38[] PROGMEM = "что ты ценишь это";
const char text_39[] PROGMEM = "у пятачка";
const char text_40[] PROGMEM = "генерализова.нное";
const char text_41[] PROGMEM = "тре~вож`ное расст#ро*";
const char text_42[] PROGMEM = "потому что";
const char text_43[] PROGMEM = "   люди   ";
const char text_44[] PROGMEM = "стали жить дольше";
const char text_45[] PROGMEM = "мелко-мелко";
const char text_46[] PROGMEM = "надо адаптироваться";
const char text_47[] PROGMEM = "";
const char text_48[] PROGMEM = "    опа";
const char text_49[] PROGMEM = "";
const char text_50[] PROGMEM = "красненькая речка!";
const char text_51[] PROGMEM = "Карина";
const char text_52[] PROGMEM = "   вы куда";
const char text_53[] PROGMEM = "     идете";
const char text_54[] PROGMEM = "Что ж";
const char text_55[] PROGMEM = "моя пентаграмма";
const char text_56[] PROGMEM = "становится получше";
const char text_57[] PROGMEM = "    маленькая";
const char text_58[] PROGMEM = "и очень странная";
const char text_59[] PROGMEM = "   но победа";
const char text_60[] PROGMEM = "искажения интересные";
const char text_61[] PROGMEM = "  но совершенно";
const char text_62[] PROGMEM = "  не подходят";
const char text_63[] PROGMEM = "Поспать";
const char text_64[] PROGMEM = "  и покушать";
const char text_65[] PROGMEM = "     бесценно";
const char text_66[] PROGMEM = "у меня к тебе";
const char text_67[] PROGMEM = "сегодня будет";
const char text_68[] PROGMEM = "очень важный вопрос";
const char text_69[] PROGMEM = "";
const char text_70[] PROGMEM = "Какой план у тебя?";
const char text_71[] PROGMEM = "";
const char text_72[] PROGMEM = "";
const char text_73[] PROGMEM = "наш отрезок времени";
const char text_74[] PROGMEM = "   небольшой";
const char text_75[] PROGMEM = "   ты снова";
const char text_76[] PROGMEM = "  появляешься";
const char text_77[] PROGMEM = "      рядом";
const char text_78[] PROGMEM = "   как-то все";
const char text_79[] PROGMEM = "   я не знаю";
const char text_80[] PROGMEM = "";
const char text_81[] PROGMEM = "не могу";
const char text_82[] PROGMEM = "тебе говорить";
const char text_83[] PROGMEM = "каких-то вещей";
const char text_84[] PROGMEM = "   я попробую";
const char text_85[] PROGMEM = "   это пережить";
const char text_86[] PROGMEM = "";
const char text_87[] PROGMEM = "такие вот";
const char text_88[] PROGMEM = "   странные";
const char text_89[] PROGMEM = "подарки";
const char text_90[] PROGMEM = "33kck(@";
const char text_91[] PROGMEM = "$---2##";
const char text_92[] PROGMEM = "--~~-..5";

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


const size_t TEXT_LEN = 31;
const char *const TEXT[] PROGMEM = {text_0, text_1, text_2, text_3, text_4, text_5, text_6, text_7, text_8, text_9, text_10, text_11, text_12, text_13, text_14, text_15, text_16, text_17, text_18, text_19, text_20, text_21, text_22, text_23, text_24, text_25, text_26, text_27, text_28, text_29, text_30, text_31, text_32, text_33, text_34, text_35, text_36, text_37, text_38, text_39, text_40, text_41, text_42, text_43, text_44, text_45, text_46, text_47, text_48, text_49, text_50, text_51, text_52, text_53, text_54, text_55, text_56, text_57, text_58, text_59, text_60, text_61, text_62, text_63, text_64, text_65, text_66, text_67, text_68, text_69, text_70, text_71, text_72, text_73, text_74, text_75, text_76, text_77, text_78, text_79, text_80, text_81, text_82, text_83, text_84, text_85, text_86, text_87, text_88, text_89, text_90, text_91, text_92};

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
