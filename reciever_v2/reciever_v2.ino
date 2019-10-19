#define red A0 //0
#define green A1 //1
String data ;
String reading = "";
int rred = 0;
int rgreen = 0;
void setup() {
  Serial.begin(9600);
  pinMode(red,0);
  pinMode(green,0);
}
void ser(){
  rred = digitalRead(red);
  rgreen = digitalRead(green);
  if(rred == 0){
    data += '0';
    Serial.println("0");
    delay(300);
    }
   if(rgreen == 0){
    data += '1';
    Serial.println("1");
    delay(300);
    }
  if(Serial.available() > 0){
   reading = Serial.readStringUntil('\n');
 }
 if(reading == "g"){
  Serial.println(data+"e");
  reading = "";
  }
}

void loop() {
 ser(); 
}
