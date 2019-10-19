#define green 3//1
#define red 2//0
String reading = "";
void setup() {
pinMode(green,1);
pinMode(red,1);
Serial.begin(9600);
digitalWrite(green,1);
}
void greenout(){
  digitalWrite(green,0);
  digitalWrite(red,0);
  }
void redout(){
  digitalWrite(green,1);
  digitalWrite(red,1);
  }
void kill(){
  reading = "";
    digitalWrite(red,0);
      digitalWrite(green,1);
  }
void loop() {
  if(Serial.available() > 0){
  reading = Serial.readStringUntil('\n');
  }
  if(reading == "1"){
    greenout();
    }
  if(reading == "0"){
    redout();
    }
    delay(250);
    kill();
}
