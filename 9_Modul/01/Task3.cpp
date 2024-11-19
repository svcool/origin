void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {
  //Желтый
digitalWrite(11, HIGH);
digitalWrite(13, LOW);
digitalWrite(12, LOW);
delay(1000);
//зеленый
digitalWrite(11,LOW);
digitalWrite(13, HIGH);
digitalWrite(12, LOW);
delay(1000);
//красный
digitalWrite(11, LOW);
digitalWrite(13, LOW);
digitalWrite(12, HIGH);
delay(1000);


}
