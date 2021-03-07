#ifndef config.h

#define config.h

#define usuario "EstacionMeteo" //Nuestro usuario de Thinger.io
#define device_Id "Servidor_Meteo" //Poner el device_ID elegido en Thinger.io
#define device_credentials "A+aKTL!K2!Dv" //Poner nuestra device_credencials de Thinger.io

#define WiFi_ssid "RedWifiPRO"  //Nombre de red
#define WiFi_password "KirguisT@N2035"  //Clave de red

IPAddress ip(192, 168, 1, 77);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#endif
