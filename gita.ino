#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

#ifndef pgm_read_ptr
#define pgm_read_ptr(addr) ((void*)pgm_read_word(addr))
#endif

const char quote0[] PROGMEM = "You have the right to perform your prescribed duties, but you are not entitled to the fruits of your actions.";
const char quote1[] PROGMEM = "Set thy heart upon thy work, but never on its reward.";
const char quote2[] PROGMEM = "For one who has conquered his mind, a mind is best of friends, but for one who has failed to do so, a mind is the greatest enemy.";
const char quote3[] PROGMEM = "Happiness from the senses seems like nectar initially, but it is bitter as poison in the end.";
const char quote4[] PROGMEM = "A person can rise through the efforts of his own mind; or draw himself down in the same manner. Because each person is his own friend or enemy.";
const char quote5[] PROGMEM = "Perform every action with your heart fixed on the Supreme Lord. Renounce attachment to the fruits. Be even-tempered in success and failure.";
const char quote6[] PROGMEM = "You are what you believe in. You become that which you believe you can become.";
const char quote7[] PROGMEM = "Man is made by his belief. As he believes, so he is.";
const char quote8[] PROGMEM = "Action is indeed better than inaction.";
const char quote9[] PROGMEM = "Surrender all your works to Me, with your mind focused on the Self.";
const char quote10[] PROGMEM = "Be steadfast in yoga, O Arjuna. Perform your duty and abandon all attachment to success or failure.";
const char quote11[] PROGMEM = "Yoga is skill in action.";
const char quote12[] PROGMEM = "You have control over your work only, never over its results.";
const char quote13[] PROGMEM = "The man who has no attachments can really love others, for his love is pure and divine.";
const char quote14[] PROGMEM = "Perform your prescribed duties, for action is superior to inaction.";
const char quote15[] PROGMEM = "A person attains purity of mind by performing their duties without attachment.";
const char quote16[] PROGMEM = "No effort is wasted, and no loss occurs.";
const char quote17[] PROGMEM = "By working without attachment, you attain the Supreme.";
const char q0[] PROGMEM = "You have the right to work only, never to its fruits. (2.47)";
const char q1[] PROGMEM = "Be steadfast in yoga, perform your duty, abandon attachment. (2.48)";
const char q2[] PROGMEM = "Perform all work as an offering to Me. (3.9)";
const char q3[] PROGMEM = "Without attachment, work becomes sacrifice. (3.9)";
const char q4[] PROGMEM = "The wise work without desire for the fruits. (5.10)";
const char q5[] PROGMEM = "Abandoning all desires, perform duty with mind fixed on the Self. (3.7)";
const char q6[] PROGMEM = "A person is made by their belief; as they believe, so they are. (17.3)";
const char q7[] PROGMEM = "Yoga is skill in action. (2.50)";
const char q8[] PROGMEM = "A man is elevated by his perseverance, not by his birth. (18.41)";
const char q9[] PROGMEM = "Be even-tempered in success and failure. (2.48)";
const char q10[] PROGMEM = "By selfless action, one attains peace and liberation. (5.12)";
const char q11[] PROGMEM = "Control the mind and senses; be steady and focused. (6.26)";
const char q12[] PROGMEM = "Those who are motivated by desire, craving the fruits, are bound. (3.9)";
const char q13[] PROGMEM = "The mind is the friend of the conditioned soul, and his enemy as well. (6.5)";
const char q14[] PROGMEM = "Act with detachment, be free from craving. (2.49)";
const char q15[] PROGMEM = "Even a little effort in the right direction protects from great fear. (2.40)";
const char q16[] PROGMEM = "Give up attachment to the results of action. (2.47)";
const char q17[] PROGMEM = "Self-control is the path to supreme happiness. (6.16)";
const char q18[] PROGMEM = "Work done as duty without desire is purifying. (3.19)";
const char q19[] PROGMEM = "Those who perform their duty without attachment, surrendering results, attain peace. (5.10)";

const char* const quotes[] PROGMEM = {
  quote0, quote1, quote2, quote3, quote4, quote5, quote6, quote7,
  quote8, quote9, quote10, quote11, quote12, quote13, quote14, quote15, quote16, quote17,
  q0, q1, q2, q3, q4, q5, q6, q7, q8, q9,
  q10, q11, q12, q13, q14, q15, q16, q17, q18, q19,
};

const uint8_t quotesCount = sizeof(quotes) / sizeof(quotes[0]);

void setup() {
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);

  // Better random seed from analog noise on A0
  long seed = 0;
  for (int i = 0; i < 8; i++) {
    seed ^= analogRead(A0) << i;
    DigiKeyboard.delay(5);
  }
  randomSeed(seed);

  uint8_t index = random(quotesCount);

  const char* quotePtr = (const char*) pgm_read_ptr(&(quotes[index]));

  char buffer[150];
  uint8_t i = 0;
  char c;

  do {
    c = pgm_read_byte(&(quotePtr[i]));
    buffer[i] = c;
    i++;
  } while (c != 0 && i < sizeof(buffer));

  buffer[i-1] = 0; // Null-terminate

  DigiKeyboard.print(buffer);
}

void loop() {
  // Nothing here
}
