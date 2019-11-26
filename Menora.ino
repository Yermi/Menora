#define Do 262
#define Re 294
#define Me 330
#define Fa 349
#define Sol 392
#define La 440
#define Se_Bemol 466
#define Se 494
#define Do2 523
#define Re2 587
#define Me2 659
#define Fa2 698

int tonePin = 13;

int pins[] = {3,4,5,6,7,9,10,11 };

const int pinButton = 2;
int logicState;
int numElements;

int pinSensor = 1;
int state = LOW;
int val = 0; 

int delaySm = 300;
int duration = 200;

bool bascule = false;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Begin program...");
  numElements = (sizeof(pins) / sizeof(pins[0]));
  Serial.println(numElements);
  
  for(int i = 0; i < numElements; i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  
  pinMode(pinButton, INPUT);
  pinMode(pinSensor, INPUT);
  pinMode(tonePin, OUTPUT);
  initInterrupt();
  PlayHanukaSong();
  //MaozTzurSong();
}

void PlayHanukaSong()
{
  delay(2500);
  part_1();
  part_2(true);
  part_2(false);
  transition();
  part_3(true);
  part_3(false);
}

void part_1()
{
  for(int i = 0; i < 2; i++)
  {
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(Re2, duration, delaySm);
    PlayTone(La, duration, delaySm);
    // -  -
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(Sol, duration/2, delaySm/2);
    PlayTone(Fa, duration/2, delaySm/2);
    PlayTone(Sol, duration, delaySm);
    PlayTone(Fa, duration, delaySm);
  }
}

void part_2(bool first)
{
  PlayTone(Fa, duration/2, delaySm/2);
  PlayTone(Sol, duration/2, delaySm/2);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(Sol, duration/2, delaySm/2);
  PlayTone(Fa, duration, delaySm);
  PlayTone(Fa, duration, delaySm);
  PlayTone(Sol, duration, delaySm);
  PlayTone(Fa, duration/2, delaySm/2);
  if (first)
  {
    PlayTone(Re, duration/2, delaySm/2);
    PlayTone(Fa, duration*2, delaySm*2);
  }
  else
  {
    PlayTone(Me, duration/2, delaySm/2);
    PlayTone(Re, duration*2, delaySm*2);
  }
}

void transition()
{
  for(int i = 0; i < 2; i++)
  {
    PlayTone(Re, duration, delaySm);
    PlayTone(La, duration, delaySm);
    PlayTone(La, duration*2, delaySm*2);
  }
  PlayTone(La, duration, delaySm);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(Se_Bemol, duration, delaySm);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(Sol, duration/2, delaySm/2);
  PlayTone(La, duration*4, delaySm*4);
}

void part_3(bool first)
{
  for(int i = 0; i < 2; i++)
  {
    PlayTone(La, duration, delaySm);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(Se_Bemol, duration, delaySm);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(Sol, duration/2, delaySm/2);
  }
  PlayTone(Fa, duration/2, delaySm/2);
  PlayTone(Fa, duration/2, delaySm/2);
  PlayTone(Fa, duration/2, delaySm/2);
  PlayTone(Fa, duration/2, delaySm/2);
  PlayTone(Sol, duration, delaySm);
  PlayTone(Fa, duration/2, delaySm/2);
  if(first)
  {    
    PlayTone(Sol, duration/2, delaySm/2);
    PlayTone(La, duration*4, delaySm*4);
  }
  else
  {
    PlayTone(Me, duration/2, delaySm/2);
    PlayTone(Re, duration*4, delaySm*4);
  }
}

void MaozTzurSong()
{
  delay(1500);
  int delaySm = 450;
  int duration = 300;
  
  for(int i = 0; i < 2; i++)
  {  
    PlayTone(Fa, duration, delaySm);
    PlayTone(Do, duration, delaySm);
    PlayTone(Fa, duration, delaySm);
    PlayTone(Se_Bemol, duration, delaySm);
    PlayTone(La, duration, delaySm);
    PlayTone(Sol, duration, delaySm);
    PlayTone(Fa, duration*2, delaySm*2);
    PlayTone(Do2, duration, delaySm);
    PlayTone(Re2, duration, delaySm);
    PlayTone(Sol, duration, delaySm);
    PlayTone(La, duration/2, delaySm/2);
    PlayTone(Se_Bemol, duration/2, delaySm/2);
    PlayTone(La, duration, delaySm);
    PlayTone(Sol, duration, delaySm);
    PlayTone(Fa, duration*2, delaySm*2);
  }
  Serial.println("לעת תכין מטבח");
  PlayTone(Do2, duration*1.5, delaySm*1.5);
  PlayTone(Do2, duration/2, delaySm/2);
  PlayTone(Re2, duration, delaySm);
  PlayTone(Me2, duration, delaySm);
  PlayTone(Fa2, duration*2, delaySm*2);
  PlayTone(Do2, duration*2, delaySm*2);
  Serial.println("מצר המנבח");
  PlayTone(Fa2, duration, delaySm);
  PlayTone(Me2, duration, delaySm);
  PlayTone(Re2, duration, delaySm);
  PlayTone(Do2, duration, delaySm);
  PlayTone(Do2, duration/2, delaySm/2);
  PlayTone(Se_Bemol, duration/2, delaySm/2);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(Se_Bemol, duration/2, delaySm/2);
  PlayTone(Sol, duration*2, delaySm*2);
  
  // קץ בבל זרובבל

  MaozTzurSongLastPart(true);
  MaozTzurSongLastPart(false);
}

void MaozTzurSongLastPart(bool first)
{  
  int delaySm = 450;
  int duration = 300;
  Serial.println("אז אגמור");
  PlayTone(La, duration*1.5, delaySm*1.5);
  PlayTone(Se_Bemol, duration/2, delaySm/2);
  PlayTone(Do2, duration*1.5, delaySm*1.5);
  Serial.println("בשיר מזמור");
  PlayTone(Re2, duration/2, delaySm/2);
  PlayTone(Sol, duration*1.5, delaySm*1.5);
  PlayTone(La, duration/2, delaySm/2);
  PlayTone(Se_Bemol, duration*2, delaySm*2);
  
  Serial.println("חנוכת המזבח");
  PlayTone(La, duration, delaySm);
  PlayTone(Fa, duration, delaySm);
  PlayTone(Re2, duration, delaySm);
  PlayTone(Do2, duration/2, delaySm/2);
  PlayTone(Se_Bemol, duration/2, delaySm/2);
  PlayTone(La, duration, delaySm);
  if(first)
  {
    PlayTone(Se_Bemol, duration, delaySm);
    PlayTone(Do2, duration*2, delaySm*2);
  }
  else
  {  
    PlayTone(Sol, duration, delaySm);
    PlayTone(Fa, duration*2, delaySm*2);    
  }
}


void PlayTone(int MusicalNote, int Duration, int Delay)
{
  tone(tonePin,MusicalNote, Duration);
  delay(Delay);
}

void loop()
{
  val = digitalRead(pinSensor);
  Serial.println(val);
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(11, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(11, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}

void initInterrupt()
{
  attachInterrupt(digitalPinToInterrupt(pinButton), myISR, CHANGE);
}

void myISR()
{
  bascule = !bascule;
  if(bascule)
  {    
    for(int i = 0; i < numElements; i++)
    {
      digitalWrite(pins[i], HIGH);
    }
  }
  else
  {
    for(int i = 0; i < numElements; i++)
    {
       digitalWrite(pins[i], LOW);
    }
  }  
}
