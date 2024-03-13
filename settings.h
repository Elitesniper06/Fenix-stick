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
#define PIN_433MHZ_G26 26
// -=-=- ALIASES -=-=-
#define DISP M5.Lcd
#define IRLED 19
#define M5_BUTTON_MENU 35
#define M5_BUTTON_HOME 37
#define M5_BUTTON_RST 39
#define M5LED_ON HIGH
#define M5LED_OFF LOW
#endif

