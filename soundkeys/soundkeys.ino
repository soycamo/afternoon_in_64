#define MIC_L A0
#define MIC_R A5
#define ON_SWITCH 12
#define BOARD_LED 13

void setup()
{
  ADMUX |= (1 << REFS1) | (1 << REFS0);
  analogReference(INTERNAL);
  //Keyboard.begin();
  pinMode(MIC_L, INPUT);
  pinMode(MIC_R, INPUT);
  pinMode(ON_SWITCH, INPUT);
  pinMode(BOARD_LED, OUTPUT);
}

char dpad[] = {'w','a', 's', 'd'};
char select_btn = 'z';
char b_btn = 'x';
char a_btn = 'c';
int micLread, micRread;

void loop()
{

  if (digitalRead(ON_SWITCH) == 1) {
    digitalWrite(BOARD_LED, HIGH);
    for(int i = 0; i < sizeof(dpad); i++) {
      Keyboard.release(dpad[i]);
    }

    int micLread = analogRead(MIC_L);
    int micRread = analogRead(MIC_R); 

    Keyboard.press(dpad[micLread + micRread % 4]);
    press_mod_btn(micLread);
    press_ab_btn(micRread);
  }
  else {
    digitalWrite(BOARD_LED, LOW);
    Keyboard.releaseAll();
  }

  delay(500);
}


void press_mod_btn(int mic){ 
  if (mic > 100) {
    Keyboard.press(select_btn);
  }
  else {
    Keyboard.release(select_btn);
  }
}

void press_ab_btn(int mic){
  if (mic % 2) {
    Keyboard.release(b_btn);
    Keyboard.press(a_btn);
  }
  else {
    Keyboard.release(a_btn);
    Keyboard.press(b_btn);
  }

}
