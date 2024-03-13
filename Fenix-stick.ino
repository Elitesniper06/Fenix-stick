// #define STICK_C_PLUS
#define STICK_C_PLUS2

#include "settings.h"

struct MenuItem {
  String name;
  int command;
};

MenuItem mmenu[] = {
  { "TV-B-Gone", 1}, 
  { "Bluetooth", 2},
  { "WiFi", 3},
  { "433 Mhz", 4},
  { "Settings", 5},
};

const int mmenu_size = sizeof(mmenu) / sizeof(MenuItem);
int selectedOption = 0;

void drawMenu() {
  DISP.fillScreen(TFT_BLACK);
  DISP.setRotation(3);

  for (int i = 0; i < mmenu_size; i++) {
    if (i == selectedOption) {
      DISP.setTextSize(TINY_TEXT);
      DISP.setTextColor(TFT_CYAN);
      DISP.setCursor(10, 20 + i * 20, 2);
      DISP.print("> ");
    } else {
      DISP.setTextColor(TFT_WHITE);
      DISP.setCursor(10, 20 + i * 20, 2);
      DISP.print("  ");
    }
    DISP.print(mmenu[i].name);
  }
}

void navigateMenu() {
  if (digitalRead(M5_BUTTON_MENU) == LOW && selectedOption > 0) {
    selectedOption--;
    drawMenu();
    delay(200);
  } else if (digitalRead(M5_BUTTON_RST) == LOW && selectedOption < mmenu_size - 1) {
    selectedOption++;
    drawMenu();
    delay(200);
  } else if (digitalRead(M5_BUTTON_HOME) == LOW) { // Verifica si se ha presionado el botón HOME
    // Ejecutar la acción correspondiente a la opción seleccionada
    int selectedCommand = mmenu[selectedOption].command;
    switch (selectedCommand) {
      case 1: // TV-B-Gone
        // Ejecutar acción para la opción TV-B-Gone
        Serial.println("Acción para TV-B-Gone");
        break;
      case 2: // Bluetooth
        // Ejecutar acción para la opción Bluetooth
        Serial.println("Acción para Bluetooth");
        break;
      case 3: // WiFi
        // Ejecutar acción para la opción WiFi
        Serial.println("Acción para WiFi");
        break;
      case 4: // 433 Mhz
        DISP.clearDisplay();
        DISP.setTextSize(MEDIUM_TEXT);
        DISP.setTextColor(TFT_GREEN);
        DISP.setCursor(0, 0);
        DISP.println("433 Mhz");
        DISP.setTextSize(SMALL_TEXT);
        Serial.println("Acción para 433 Mhz");
        
        break;
      case 5: // Settings
        // Ejecutar acción para la opción Settings
        Serial.println("Acción para Settings");
        break;
      default:
        // Si no hay una acción definida para la opción seleccionada
        Serial.println("Opción no reconocida");
        break;
    }
    delay(200); // Retardo para evitar pulsaciones múltiples
  }
}

void setup() {
  M5.begin();
  DISP.setRotation(1);
  pinMode(PIN_433MHZ_G26, OUTPUT);
  drawMenu();
}

void loop() {
  navigateMenu();
}

