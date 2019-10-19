#define red 2//0
//#define green 3//1
#define r_read A0
void setup() {
Serial.begin(9600);
pinMode(red,1);
pinMode(A0,0);
//pinMode(green,1);
}
String reading = "";
int a = 0;
unsigned char r = 0;
void loop() {
  if(Serial.available()){
   reading = Serial.readStringUntil('\n');
  }
  if(reading == "start"){
      digitalWrite(red,1);
    a = analogRead(A0);
    if(a >= 200){
      Serial.println("1");
    }else{
      Serial.println("0");
    }
    delay(1000); 
    }else if(reading == "EOL"){
      digitalWrite(red,0);
      Serial.println("EOL");
    }
}
