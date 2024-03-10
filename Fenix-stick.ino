// #define STICK_C_PLUS
#define STICK_C_PLUS2

#if defined(STICK_C_PLUS)
#include <M5StickCPlus.h>
// -=-=- Display -=-=-
String platformName = "StickC+";
#define BIG_TEXT 4
#define MEDIUM_TEXT 3
#define SMALL_TEXT 2
#define TINY_TEXT 1
// -=-=- FEATURES -=-=-
#define M5LED 10
#define RTC
#define AXP
#define ACTIVE_LOW_IR
#define ROTATION
#define USE_EEPROM
// -=-=- ALIASES -=-=-
#define DISP M5.Lcd
#define IRLED 9
#define SPEAKER M5.Beep
//  #define BITMAP M5.Lcd.drawBitmap(0, 0, 320, 240, NEMOMatrix) // This doesn't work, generates static.
#define M5LED_ON LOW
#define M5LED_OFF HIGH
#endif

#if defined(STICK_C_PLUS2)
#include <M5StickCPlus2.h>
// -=-=- Display -=-=-
String platformName = "StickC+2";
#define BIG_TEXT 4
#define MEDIUM_TEXT 3
#define SMALL_TEXT 2
#define TINY_TEXT 1
// -=-=- FEATURES -=-=-
#define ACTIVE_LOW_IR
#define M5LED 19
#define ROTATION
#define USE_EEPROM
#define RTC
#define PWRMGMT
#define SPEAKER M5.Speaker
#define SONG
// -=-=- ALIASES -=-=-
#define DISP M5.Lcd
#define IRLED 19
#define M5_BUTTON_MENU 35
#define M5_BUTTON_HOME 37
#define M5_BUTTON_RST 39
#define BACKLIGHT 27
#define MINBRIGHT 190
#define M5LED_ON HIGH
#define M5LED_OFF LOW
#endif

// CLOCK //

#if defined(RTC)
    void clock_loop() {
        DISP.setCursor(10, 10, 1);
    #if defined(STICK_C_PLUS2)
        auto dt = StickCP2.Rtc.getDateTime();
        DISP.printf("%02d:%02d:%02d\n", dt.time.hours, dt.time.minutes, dt.time.seconds);
    #else
        M5.Rtc.GetBm8563Time();
        DISP.printf("%02d:%02d:%02d\n", M5.Rtc.Hour, M5.Rtc.Minute, M5.Rtc.Second);
    #endif
        delay(250);
    }
#endif


// BATTERY //
#if defined(PWRMGMT)
  int old_battery = 0;

  void battery_drawmenu(int battery) {
    DISP.setTextSize(TINY_TEXT);
    DISP.setCursor(210, 10, 1);
    DISP.fillScreen(TFT_BLACK); 
    DISP.print(battery);
    DISP.print("%");

  }

  int get_battery_voltage() {
    return M5.Power.getBatteryLevel();
  }

  void battery_setup() {
    int battery = get_battery_voltage();
    battery_drawmenu(battery);
    delay(500);
  }

  void battery_loop() {
    delay(300);
    int battery = get_battery_voltage();

    if (battery != old_battery){
      battery_drawmenu(battery);
    }
    old_battery = battery;
  }
#endif

void setup() {
    M5.begin();
    M5.Lcd.setRotation(1);
    battery_setup();
}

void loop() {
    clock_loop();
    battery_loop();
}