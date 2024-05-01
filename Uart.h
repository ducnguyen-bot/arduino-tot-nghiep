#include <SoftwareSerial.h> // Thư viện cho cổng nối tiếp mềm

#define RX_PIN 4 // Chân RX của cổng nối tiếp mềm
#define TX_PIN 5 // Chân TX của cổng nối tiếp mềm

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Tạo một đối tượng cổng nối tiếp mềm

// Hàm tách chuỗi dữ liệu theo ký tự phân cách và trả về phần tử thứ index
String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = { 0, -1, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
      if (data.charAt(i) == separator || i == maxIndex) {
          found++;
          strIndex[0] = strIndex[1] + 1;
          strIndex[1] = (i == maxIndex) ? i+1 : i;
      }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

