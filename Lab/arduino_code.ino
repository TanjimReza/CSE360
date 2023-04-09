int LED = 6;
int MAGNETIC_REED = 7; 
int LDR = 8; 
int PIR = 9; 
// Bluetooth Module in TX, RX
int LDR_STATE; 
int PIR_STATE; 
int REED_STATE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MAGNETIC_REED, INPUT);
  pinMode(LDR, INPUT);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  //When to turn on LED->1
      //MAGNETIC REED ENABLE -> 1 ~
      //LDR ENABLE -> 1 ~ Low Light 
      //PIR -> 1 ~ Movement 
      // ----> LED ENABLE ----> Bluetooth Output

  LDR_STATE = digitalRead(LDR);
  PIR_STATE = digitalRead(PIR);
  REED_STATE = digitalRead(MAGNETIC_REED);

  if (REED_STATE > 0) {
    //REED ON
    if (LDR_STATE != 0) {
      //LDR ON
        if (PIR_STATE > 0) {
          //PIR ON
          digitalWrite(LED, HIGH);
          // Bluetooth Notification Send
          Serial.write("1"); //1 for simplicity
          delay(2000);

      } //PIR CLOSE
      digitalWrite(LED,LOW);
      LDR_STATE = 0;
      PIR_STATE = 0;
      REED_STATE = 0;
    } //LDR CLOSE
    digitalWrite(LED,LOW);
    LDR_STATE = 0;
    PIR_STATE = 0;
    REED_STATE = 0;
  } //REED CLOSE
  digitalWrite(LED,LOW);
  LDR_STATE = 0;
  PIR_STATE = 0;
  REED_STATE = 0;
}//main close
