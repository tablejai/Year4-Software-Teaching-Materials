const int START_BYTE = 0x59;

void getTFminiData(int* distance, int* strength, int* temperature) {
  static int i = 0;
  static int rx[9];
  if (Serial.available()) {  
    rx[i] = Serial.read();
    if (rx[0] != START_BYTE) {
      i = 0;
    } else if (i == 1 && rx[1] != START_BYTE) {
      i = 0;
    } else if (i == 8) {
      int checksum = 0; 
      for (int j = 0; j < 8; j++) {
        checksum += rx[j];
      }
      if (rx[8] == (checksum & 0xFF)) {
        *distance = (rx[3] << 8) + rx[2];
        *strength = (rx[5] << 8) + rx[4];
        *temperature = (rx[7] << 8) + rx[6];
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
    int temperature = 0;

    getTFminiData(&distance, &strength, &temperature);
    if (distance) {
        Serial.print(distance);
        Serial.print("cm");
        Serial.print("\tstrength: ");
        Serial.print(strength);
        Serial.print("\ttemperature: ");
        Serial.println(temperature);
    }
}
