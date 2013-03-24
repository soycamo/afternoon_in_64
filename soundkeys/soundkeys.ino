#include <Esplora.h>

void setup()
{
  Keyboard.begin();
}

char dpad[] = {'w','a', 's', 'd'};

void loop()
{
  // Preventing accidental keypresses
  if(Esplora.readSlider() == 0) {
    for(int i = 0; i < sizeof(dpad); i++) {
      Keyboard.press(dpad[i]);
      delay(1000);
      Keyboard.releaseAll();
    }
  }
}
