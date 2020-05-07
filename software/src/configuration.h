#ifndef CONFIGURATION_H
#define CONFIGURATION_H


#include <TypeDefinitions.h>

const unsigned int pwmFreq = 2000;

//default values in configruation interface

char mqtt_server[40];
char mqtt_port[6] = "1883";
char strip_type[8] = "RGB";
char mqtt_ssl[3] = "no";
char mqtt_username[40] = "esp";
char mqtt_password[40] = "supersecurepassword";

char mainTopic[80] = "/ESPLED/";
char debugTopic[80];

//Fingerprint of odroid
const char* fingerprint = "A6 AE 85 65 63 DD D8 7C 70 F7 92 73 DE 8F 18 2B 9F DA 0A 76";
const LogLevel LOGLEVEL = DEBUG;

#endif
