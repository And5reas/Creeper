#include <ESP8266.h>
#include <arduino.h>

const char* ssid = "Vinicius";        // Nome da rede Wi-Fi
const char* password = "101202303";  // Senha da rede Wi-Fi

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  
  // Conecta à rede Wi-Fi
  WiFi.begin(ssid, password);
  
  // Aguarda até o ESP8266 se conectar à rede
  Serial.print("Conectando-se à rede Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Quando conectado
  Serial.println();
  Serial.println("Conectado com sucesso!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  while(1);
}

void loop(){

}
