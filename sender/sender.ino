#define red 2//0
//#define green 3//1
void setup() {
Serial.begin(9600);
pinMode(red,1);
//pinMode(green,1);
}
String reading = "";
void loop() {
  if(Serial.available()){
  reading = Serial.readStringUntil('\n');
  }
  if(reading == "0"){ 
    Serial.println("in red");
    Serial.println(reading);
    digitalWrite(red,1);
//    digitalWrite(green,0);
  delay(1000);

  }
//  else if(reading == "1"){
//    Serial.println("in green");
//    Serial.println(reading);
//    pinMode(red,0);
//    pinMode(green,1);
//      delay(1000);
//
//  }
  digitalWrite(red,0);
//  digitalWrite(green,0);
  reading = "";
  
}
