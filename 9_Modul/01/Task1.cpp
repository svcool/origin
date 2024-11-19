void setup() {
  // put your setup code here, to run once:
for(int i=0;i<8;i++){
pinMode(i, OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:

for(int j=1; j<=4; j++)
for(int i=0; i<8; i++){
digitalWrite(i, HIGH);
delay(1000/j);
digitalWrite(i, LOW);
}
}
