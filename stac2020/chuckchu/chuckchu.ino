#include <Arduino_LSM6DS3.h>
#include <SPI.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);


float acX, acY, acZ, gyX, gyY, gyZ; //가속도, 각속도 값을 저장하는 변수

double angle = 0, deg; //각도, deg data

double dgyX; //accData

void setup() {
  Serial.begin(9600);      // initialize serial communication

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }
  
  if (!IMU.begin()) { //LSM6DS3센서 시작
    Serial.println("LSM6DS3센서 오류!");
    while (1);
  }
  
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(20000);
  }
  server.begin();                           // start the web server on port 80
  printWifiStatus();                        // you're connected now, so print out the status
}


void loop() {
  calAngle();

  WiFiClient client = server.available();
   if (client && client.connected()) {
     String request = client.readStringUntil('\n');
     Serial.println(request);
     client.println(angleString());
     client.stop();
   }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}


void calAngle() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(acX, acY, acZ);
    IMU.readGyroscope(gyX, gyY, gyZ);

    //각도 계산
    deg = atan2(acX, acZ) * 180 / PI;
    dgyX = gyY / 131. ;
    angle = (0.95 * (angle + (dgyX * 0.001))) + (0.05 * deg);
  }
 
}

String angleString(){

  String stringData = "{" + String("\"data\"") + String(": ") + String(angle) + String("}");

  return stringData;

}
