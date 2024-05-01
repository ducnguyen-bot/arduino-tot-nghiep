#include <DHT.h> // Thư viện cho cảm biến DHT11
#include <SoftwareSerial.h> // Thư viện cho EspSoftwareSerial

#define DHTPIN 2 // Chân kết nối với cảm biến
#define RX_PIN 10 // Chân RX của EspSoftwareSerial nối với D1
#define TX_PIN 11 // Chân TX của EspSoftwareSerial nối với D2

DHT dht(DHTPIN,DHT11); // Tạo một đối tượng DHT
SoftwareSerial mySerial(RX_PIN, TX_PIN); // Tạo một đối tượng EspSoftwareSerial

void setup() {
  Serial.begin(9600); // Khởi tạo cổng nối tiếp cứng với tốc độ baud là 9600
  mySerial.begin(9600); // Khởi tạo cổng nối tiếp mềm với tốc độ baud là 9600
  dht.begin(); // Khởi tạo cảm biến
}

void loop() {
  delay(1000); // Đợi 2 giây
  float Gas = analogRead(A0);
  float Temp = dht.readTemperature(); // Đọc độ ẩm và nhiệt độ
  float Humid = dht.readHumidity();
  Serial.print("Temp ");
  Serial.println(Temp);
  Serial.print("Humid ");
  Serial.println(Humid);
  Serial.print("Gas ");
  Serial.println(Gas);
  //Thiết lập Data gửi đi dạng: "35.6;71.2" 2 giá trị phân cách bởi ';'
  String Data = String(Temp,1) + ";" + String(Humid,1) + ";" + String(Gas,1) + ";";
  mySerial.println(Data); //Gửi giá trị nhiệt độ và độ ẩm qua Software serial
  Serial.println(Data); //In ra Serial Monitor chuỗi gửi đi
}
