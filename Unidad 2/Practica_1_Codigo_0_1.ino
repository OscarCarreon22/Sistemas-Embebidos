// Configuración de los pines para la comunicación serial con el Bluetooth
#define BT_RX_PIN 0    // RX del Arduino (Pin 0)
#define BT_TX_PIN 1    // TX del Arduino (Pin 1)
#define LED_PIN 13     // Pin del LED (Pin 13 en Arduino Uno)

// Puedes usar Serial Monitor o cualquier aplicación Bluetooth en tu teléfono (por ejemplo, "Bluetooth Terminal")

void setup() {
  // Iniciar la comunicación serial con el puerto USB para depuración
  //Serial.begin(9600);  // Este es el puerto para comunicarte con la PC

  // Iniciar la comunicación serial con el módulo Bluetooth
  Serial.begin(9600); // HC-05 usa generalmente 9600 baudios

  // Configurar el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Esperando conexión Bluetooth...");
}

void loop() {
  // Si el módulo Bluetooth recibe datos, los leemos y tomamos la acción correspondiente
  if (Serial.available()) {
    char data = Serial.read();  // Usamos Serial en lugar de Serial1
    Serial.print("Recibido desde Bluetooth: ");
    Serial.println(data);

    // Si el dato recibido es '1', encendemos el LED
    if (data == '1') {
      digitalWrite(LED_PIN, HIGH);  // Enciende el LED
    }
    // Si el dato recibido es '0', apagamos el LED
    else if (data == '0') {
      digitalWrite(LED_PIN, LOW);   // Apaga el LED
    }
  }

  // Si el monitor serial tiene datos, los enviamos al módulo Bluetooth
  if (Serial.available()) {
    char data = Serial.read();
    Serial.print(data);
  }
}
