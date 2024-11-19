void setup() {
  // put your setup code here, to run once:
for(int i=0;i<8;i++){
digitalWrite(i, HIGH);
pinMode(i, OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:

for(int i=8; i>=0; i--){
digitalWrite(i, LOW);
delay(500);
}
for(int i=0; i<8; i++){
digitalWrite(i, HIGH);
delay(1000);
}
}
