const int sw1 = 2;
const int sw2 = 3;

const int led1 = 5;
const int led2 = 6;
unsigned char inByte;
unsigned char outByte;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2, OUTPUT);
 
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  Serial1.begin(9600);
  while (!Serial1) {
  } 

}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial1.available() >0) {
     inByte=Serial1.read();
     if((inByte & 0x01)  >0 ) {
      digitalWrite(led1,HIGH);
     } else {
      digitalWrite(led1,LOW);
     } 
     if(  (inByte & 0x02)  >0 ) {
      digitalWrite(led2,HIGH);
     } else {
      digitalWrite(led2,LOW);
     } 
   }
   outByte = 0xa0;
   outByte |= digitalRead(sw1);
   outByte |= digitalRead(sw2) << 1;
   Serial1.write(outByte);
}
