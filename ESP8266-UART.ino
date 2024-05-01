#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "DHT.h"
#include "Uart.h"
#define FIREBASE_HOST "thu4-inv-default-rtdb.firebaseio.com" //Thay bằng địa chỉ firebase của bạn
#define FIREBASE_AUTH "JEOltKjy5JOskcP7jK1JR9LZ6Bv0310Qmqe9ni1c"   //Không dùng xác thực nên không đổi
#define WIFI_SSID "B1 405"   //Thay wifi và mật khẩu
#define WIFI_PASSWORD "LUXShare"
//#define DHT_PIN 5
//DHT dht(DHT_PIN,DHT11);
void setup() {
  Serial.begin(9600); // Khởi tạo cổng nối tiếp cứng với tốc độ baud là 9600
  mySerial.begin(9600); // Khởi tạo cổng nối tiếp mềm với tốc độ baud là 9600
  //Serial.begin(115200);
  //dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  if (mySerial.available()) { // Nếu có dữ liệu từ cổng nối tiếp mềm
    String data = mySerial.readString(); // Đọc chuỗi dữ liệu
    Serial.println(data); // In ra chuỗi dữ liệu
    String Temp = getValue(data, ';', 0); // Tách phần tử thứ 0 theo ký tự phân cách ';'
    String Humid = getValue(data, ';', 1); // Tách phần tử thứ 1 theo ký tự phân cách ';'
    String Gas = getValue(data, ';', 2); // Tách phần tử thứ 1 theo ký tự phân cách ';'
    Serial.println("Temperature:"+Temp); 
    Serial.println("Humidity:"+Humid); 
    Serial.println("Gas:"+ Gas); 
    Serial.println(" ");
    Firebase.setString("nhiet do",Temp);
    Firebase.setString("do am", Humid);
    Firebase.setString("gas", Gas);
    
  }
  Serial.println("Setting successful");
  Serial.println();
  delay(100);

 
}