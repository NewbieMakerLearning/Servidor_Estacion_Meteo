void ConnectWiFi_STA(bool useStaticIP = false)
{
	Serial.println("");
	WiFi.mode(WIFI_STA);
	WiFi.begin(WiFi_ssid, WiFi_password);
	if(useStaticIP) WiFi.config(ip, gateway, subnet);
	while (WiFi.status() != WL_CONNECTED) 
	{ 
		delay(100);  
		Serial.print('.'); 
	}

	Serial.println("");
	Serial.print("Iniciado STA:\t");
	Serial.println(WiFi_ssid);
	Serial.print("IP address:\t");
	Serial.println(WiFi.localIP());
}

void ConnectWiFi_AP(bool useStaticIP = false)
{ 
	Serial.println("");
	WiFi.mode(WIFI_AP);
	while(!WiFi.softAP(WiFi_ssid, WiFi_password))
	{
		Serial.println(".");
		delay(100);
	}
	if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

	Serial.println("");
	Serial.print("Iniciado AP:\t");
	Serial.println(WiFi_ssid);
	Serial.print("IP address:\t");
	Serial.println(WiFi.softAPIP());
}
