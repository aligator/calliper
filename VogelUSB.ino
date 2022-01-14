#define CLK D5
#define DAT D6

bool isFirst = true;
int result = 0;
int lastResult = 0;

bool prevClk = false;
bool clk = false;

int dat = 0;

int pos = 0;

#define STEP_BEGIN 0
#define STEP_WAIT 1
#define STEP_BEGIN 2
#define STEP_RUNNING 3

int step = STEP_BEGIN;
unsigned long waitStart = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(CLK, INPUT);
  pinMode(DAT, INPUT);
}

void loop() {
  clk = digitalRead(CLK);
  dat = digitalRead(DAT);

  if (step == STEP_BEGIN && clk && dat) {
    waitStart = millis();
    step = STEP_WAIT;
  }
  
  if (step == STEP_WAIT && (millis() - waitStart) > 20) {
    step = STEP_RUNNING;
  }
  
  if (step == STEP_RUNNING) {    
    if (!prevClk && clk) {
      dat = dat << pos;
      result = dat | result;
      pos++;
    }
  
    if (pos >= 24) {
      if (lastResult != result || isFirst) {
        isFirst = false;
        bool isInch = (result & 0b100000000000000000000000) >> 23;
        int number = result & 0b011111111111111111111;
        bool isNegative= (result & 0b100000000000000000000) >> 20;
  
        if (isNegative) {
          number = -number;
        }
    
        String text = "";
        if (isInch) {
          text = String((double)number / 2000, 4);
          text = text + " inch";
        } else {
          text = String((float)number / 100, 2);
          text = text + " mm";
        }
        Serial.println(text);
      }

      lastResult = result;
      pos = 0;
      result = 0;
      step = STEP_BEGIN;
    }
  }
  
  prevClk = clk;
}
