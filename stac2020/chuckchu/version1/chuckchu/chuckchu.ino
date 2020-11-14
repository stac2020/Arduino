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

float acX, acY, acZ, gyX, gyY, gyZ; 

double angle = 0, deg; 

double dgyX; 

void setup() {
  Serial.begin(9600); 

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

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   

    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           
  printWifiStatus();                        
}


void loop() {
  calAngle();

  WiFiClient client = server.available();
  client.println(angleString());
  delay(1);
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

  String stringData = String(angle);

  return stringData;

}
