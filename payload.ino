#define LAYOUT_FRENCH
#include "DigiKeyboard.h"

void setup() {
  // Attente pour laisser le PC reconnaître le Digispark
  DigiKeyboard.delay(5000);

  // Ouvrir le navigateur avec le cmd
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // URL du Rick Roll
  DigiKeyboard.println("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
}

void loop() {}
