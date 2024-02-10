 /*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
 
//Сервер (Получает данные)

#include <esp_now.h>
#include <WiFi.h>
#include <GyverMotor2.h>

GMotor2<DRIVER2WIRE> motor(23,22);
GMotor2<DRIVER2WIRE> motor1(25,26);
GMotor2<DRIVER2WIRE> motor2(27,13); 


// Структура должна совпадать со структурой
// на плате-отправителе
typedef struct test_struct {
    int x;
    int y;
} test_struct;
 
// Создаем myData
test_struct myData;
 
// Обратная функция при получении
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("x: ");
  Serial.println(myData.x);
  Serial.print("y: ");
Serial.println(myData.y);
  Serial.println();
}
 
void setup() {
  // Запускаем монитор порта
  Serial.begin(115200);
  
  // Выставляем режим работы WiFi
  WiFi.mode(WIFI_STA);

  // Запускаем протокол ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  motor.setMinDuty(70);   // мин. ШИМ
  motor.reverse(1);     // реверс
  motor.setDeadtime(5); // deadtime
}
void loop() {
  esp_now_register_recv_cb(OnDataRecv);  //Получаем состояние отправки

  motor.setSpeed(myData.x);
  motor1.setSpeed(myData.y);
  motor2.setSpeed(255);


}