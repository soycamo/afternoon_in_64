#define MIC_L A0
#define MIC_R A5
#define ON_SWITCH 12
#define BOARD_LED 13

void setup()
{
  ADMUX |= (1 << REFS1) | (1 << REFS0);
  analogReference(INTERNAL);
  Serial.begin(9600);
  //Keyboard.begin();
  pinMode(MIC_L, INPUT);
  pinMode(MIC_R, INPUT);
  pinMode(ON_SWITCH, INPUT);
  pinMode(BOARD_LED, OUTPUT);
}

char dpad[] = {'w','a', 's', 'd'};

void loop()
{
  Keyboard.releaseAll();

  if (digitalRead(ON_SWITCH) == 1) {
    digitalWrite(BOARD_LED, HIGH);
    Keyboard.press(dpad[(analogRead(MIC_L) % 4)]);
  }
  else {
    digitalWrite(BOARD_LED, LOW);
  }

  delay(500);
}
