#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0); // Wake up the host
  DigiKeyboard.delay(1000);

  // Step 1: Open Spotlight (Cmd + Space)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Step 2: Type "terminal"
  DigiKeyboard.print("terminal");
  DigiKeyboard.delay(800);

  // Step 3: Press Enter to open Terminal
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500); // Wait for Terminal to open

  // Step 4: Print ASCII art with echo - single line, properly escaped
  DigiKeyboard.print("echo $' _   _      _ _        __        __         _     _ \\\\n| | | | ___| | | ___   \\\\ \\\\      / /__  _ __| | __| |\\\\n| |_| |/ _ \\\\ | |/ _ \\\\   \\\\ \\\\ /\\\\ / / _ \\\\| \\'__| |/ _` |\\\\n|  _  |  __/ | | (_) |   \\\\ V  V / (_) | |  | | (_| |\\\\n|_| |_|\\\\___|_|_|\\\\___/     \\\\_/\\\\_/ \\\\___/|_|  |_|\\\\__,_|\\\\n\\n-- Digispark HID Activated --'");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // nothing to do here
}
