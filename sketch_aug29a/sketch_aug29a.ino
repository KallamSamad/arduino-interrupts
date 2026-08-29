#define BUTTON_PIN 2

unsigned long lastTimeButtonPressed=millis();
unsigned long debounceDelay=50;

volatile int counter=0;
volatile bool flag=false;


void buttonPressedToInterrupt(){
  unsigned long endTime=millis();
  if(endTime-lastTimeButtonPressed>debounceDelay){
      lastTimeButtonPressed=endTime;
      flag=true;
  }

}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                                       buttonPressedToInterrupt,
                                         RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag){
    flag=false;
    counter++;
    Serial.print("Counter is: ");
    Serial.println(counter);
  }

}
