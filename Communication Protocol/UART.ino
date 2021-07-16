const int START_BYTE = 0x59;

void getTFminiData(int* distance, int* strength) {
  static char i = 0;
  char j = 0;
  int checksum = 0; 
  static int rx[9];
  if (Serial.available()) {  
    rx[i] = Serial.read();
    if (rx[0] != START_BYTE) {
      i = 0;
    } else if (i == 1 && rx[1] != START_BYTE) {
      i = 0;
    } else if (i == 8) {
      for(j = 0; j < 8; j++) {
        checksum += rx[j];
      }
      if (rx[8] == (checksum & 0xFF)) {
        *distance = rx[2] + rx[3] << 8;
        *strength = rx[4] + rx[5] << 8;
      }
      i = 0;
    } else {
      i++;
    } 
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
    int distance = 0;
    int strength = 0;

    getTFminiData(&distance, &strength);
    if (distance) {
        Serial.print(distance);
        Serial.print("cm\t");
        Serial.print("strength: ");
        Serial.println(strength);
    }
}
