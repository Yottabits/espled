EESchema Schematic File Version 4
LIBS:ESPLED-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP8266:ESP-07v2 U2
U 1 1 5967B927
P 5700 3500
F 0 "U2" H 5700 3400 50  0000 C CNN
F 1 "ESP-07v2" H 5700 3600 50  0000 C CNN
F 2 "RF_Module:ESP-07" H 5700 3500 50  0001 C CNN
F 3 "" H 5700 3500 50  0001 C CNN
	1    5700 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5967BCCF
P 4100 7250
F 0 "#PWR01" H 4100 7000 50  0001 C CNN
F 1 "GND" H 4100 7100 50  0000 C CNN
F 2 "" H 4100 7250 50  0000 C CNN
F 3 "" H 4100 7250 50  0000 C CNN
	1    4100 7250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5967BCF1
P 4500 6800
F 0 "C2" H 4525 6900 50  0000 L CNN
F 1 "1000uF" H 4525 6700 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_10x10.5" H 4538 6650 50  0001 C CNN
F 3 "" H 4500 6800 50  0000 C CNN
	1    4500 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5967BD9E
P 4900 6800
F 0 "C3" H 4925 6900 50  0000 L CNN
F 1 "1uF" H 4925 6700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4938 6650 50  0001 C CNN
F 3 "" H 4900 6800 50  0000 C CNN
	1    4900 6800
	1    0    0    -1  
$EndComp
$Comp
L ESPLED-rescue:BARREL_JACK CON1
U 1 1 5967C03C
P 2450 6650
F 0 "CON1" H 2450 6900 50  0000 C CNN
F 1 "BARREL_JACK" H 2450 6450 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 2450 6650 50  0001 C CNN
F 3 "" H 2450 6650 50  0000 C CNN
	1    2450 6650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5967C79C
P 5700 4400
F 0 "#PWR02" H 5700 4150 50  0001 C CNN
F 1 "GND" H 5700 4250 50  0000 C CNN
F 2 "" H 5700 4400 50  0000 C CNN
F 3 "" H 5700 4400 50  0000 C CNN
	1    5700 4400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 5967C984
P 5400 6550
F 0 "#PWR03" H 5400 6400 50  0001 C CNN
F 1 "+3.3V" H 5400 6690 50  0000 C CNN
F 2 "" H 5400 6550 50  0000 C CNN
F 3 "" H 5400 6550 50  0000 C CNN
	1    5400 6550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR04
U 1 1 5967C9A6
P 5700 2350
F 0 "#PWR04" H 5700 2200 50  0001 C CNN
F 1 "+3.3V" H 5700 2490 50  0000 C CNN
F 2 "" H 5700 2350 50  0000 C CNN
F 3 "" H 5700 2350 50  0000 C CNN
	1    5700 2350
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q1
U 1 1 5967CE85
P 3200 3450
F 0 "Q1" H 3400 3500 50  0000 L CNN
F 1 "IRLZ34N" H 3400 3400 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3400 3550 50  0001 C CNN
F 3 "" H 3200 3450 50  0000 C CNN
	1    3200 3450
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q2
U 1 1 5967CF02
P 2250 3450
F 0 "Q2" H 2450 3500 50  0000 L CNN
F 1 "IRLZ34N" H 2450 3400 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2450 3550 50  0001 C CNN
F 3 "" H 2250 3450 50  0000 C CNN
	1    2250 3450
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q3
U 1 1 5967CF69
P 1350 3450
F 0 "Q3" H 1550 3500 50  0000 L CNN
F 1 "IRLZ34N" H 1550 3400 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 1550 3550 50  0001 C CNN
F 3 "" H 1350 3450 50  0000 C CNN
	1    1350 3450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5967D031
P 1750 3550
F 0 "#PWR05" H 1750 3300 50  0001 C CNN
F 1 "GND" H 1750 3400 50  0000 C CNN
F 2 "" H 1750 3550 50  0000 C CNN
F 3 "" H 1750 3550 50  0000 C CNN
	1    1750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5967D059
P 2700 3550
F 0 "#PWR06" H 2700 3300 50  0001 C CNN
F 1 "GND" H 2700 3400 50  0000 C CNN
F 2 "" H 2700 3550 50  0000 C CNN
F 3 "" H 2700 3550 50  0000 C CNN
	1    2700 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5967D081
P 3650 3550
F 0 "#PWR07" H 3650 3300 50  0001 C CNN
F 1 "GND" H 3650 3400 50  0000 C CNN
F 2 "" H 3650 3550 50  0000 C CNN
F 3 "" H 3650 3550 50  0000 C CNN
	1    3650 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5967D7DD
P 3200 3800
F 0 "R1" V 3280 3800 50  0000 C CNN
F 1 "100" V 3200 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3130 3800 50  0001 C CNN
F 3 "" H 3200 3800 50  0000 C CNN
	1    3200 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5967D812
P 2250 3800
F 0 "R2" V 2330 3800 50  0000 C CNN
F 1 "100" V 2250 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2180 3800 50  0001 C CNN
F 3 "" H 2250 3800 50  0000 C CNN
	1    2250 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5967D86A
P 1350 3800
F 0 "R3" V 1430 3800 50  0000 C CNN
F 1 "100" V 1350 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1280 3800 50  0001 C CNN
F 3 "" H 1350 3800 50  0000 C CNN
	1    1350 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5967E72B
P 4350 3200
F 0 "R6" V 4430 3200 50  0000 C CNN
F 1 "10k" V 4350 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4280 3200 50  0001 C CNN
F 3 "" H 4350 3200 50  0000 C CNN
	1    4350 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5967E7A8
P 6800 3950
F 0 "R7" V 6880 3950 50  0000 C CNN
F 1 "10k" V 6800 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6730 3950 50  0001 C CNN
F 3 "" H 6800 3950 50  0000 C CNN
	1    6800 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 59680365
P 6950 4150
F 0 "#PWR09" H 6950 3900 50  0001 C CNN
F 1 "GND" H 6950 4000 50  0000 C CNN
F 2 "" H 6950 4150 50  0000 C CNN
F 3 "" H 6950 4150 50  0000 C CNN
	1    6950 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 59680549
P 4350 3050
F 0 "#PWR010" H 4350 2900 50  0001 C CNN
F 1 "+3.3V" H 4350 3190 50  0000 C CNN
F 2 "" H 4350 3050 50  0000 C CNN
F 3 "" H 4350 3050 50  0000 C CNN
	1    4350 3050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5967D035
P 4650 2900
F 0 "SW1" V 4700 3000 50  0000 L CNN
F 1 "Reset" V 4600 3100 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4650 3100 50  0001 C CNN
F 3 "" H 4650 3100 50  0000 C CNN
	1    4650 2900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5967D1A1
P 4650 2700
F 0 "#PWR011" H 4650 2450 50  0001 C CNN
F 1 "GND" H 4650 2550 50  0000 C CNN
F 2 "" H 4650 2700 50  0000 C CNN
F 3 "" H 4650 2700 50  0000 C CNN
	1    4650 2700
	-1   0    0    1   
$EndComp
$Comp
L ESPLED-rescue:SCREW-TERMINAL-GREEN_2P-3.5_ P3
U 1 1 5A986FD8
P 1500 1000
F 0 "P3" H 1650 1000 45  0000 L BNN
F 1 "LED_CON_SCREW" H 800 1000 45  0000 L BNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 1500 1000 60  0001 C CNN
F 3 "" H 1500 1000 60  0001 C CNN
F 4 "320110028" H 1530 1150 20  0001 C CNN "SKU"
	1    1500 1000
	0    -1   -1   0   
$EndComp
$Comp
L ESPLED-rescue:SCREW-TERMINAL-GREEN_2P-3.5_ P1
U 1 1 5A987158
P 2650 1000
F 0 "P1" H 2800 1000 45  0000 L BNN
F 1 "LED_CON_SCREW" H 1950 1000 45  0000 L BNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 2650 1000 60  0001 C CNN
F 3 "" H 2650 1000 60  0001 C CNN
F 4 "320110028" H 2680 1150 20  0001 C CNN "SKU"
	1    2650 1000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C4
U 1 1 5A98853F
P 5850 2500
F 0 "C4" H 5875 2600 50  0000 L CNN
F 1 "100nF" H 5550 2600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5888 2350 50  0001 C CNN
F 3 "" H 5850 2500 50  0000 C CNN
	1    5850 2500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5A9889A8
P 6000 2500
F 0 "#PWR012" H 6000 2250 50  0001 C CNN
F 1 "GND" H 6000 2350 50  0000 C CNN
F 2 "" H 6000 2500 50  0001 C CNN
F 3 "" H 6000 2500 50  0001 C CNN
	1    6000 2500
	0    -1   -1   0   
$EndComp
$Comp
L Interface_USB:CH340G U3
U 1 1 5BF8FEBF
P 9600 1750
F 0 "U3" H 9300 1150 45  0000 L BNN
F 1 "INTERFACE-CH340G" H 9750 1150 45  0000 L BNN
F 2 "Package_SO:SOP-16_4.4x10.4mm_P1.27mm" H 9600 1750 60  0001 C CNN
F 3 "" H 9600 1750 60  0001 C CNN
F 4 "CH340T" H 9630 1900 20  0001 C CNN "MPN"
F 5 "310070026" H 9630 1900 20  0001 C CNN "SKU"
	1    9600 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5BF90B72
P 7500 1650
F 0 "J1" H 7300 2100 50  0000 L CNN
F 1 "USB_B_Micro" H 7300 2000 50  0000 L CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 7650 1600 50  0001 C CNN
F 3 "" H 7650 1600 50  0001 C CNN
	1    7500 1650
	1    0    0    -1  
$EndComp
Text GLabel 6900 3150 2    60   Output ~ 0
TXD
Text GLabel 6900 3350 2    60   Input ~ 0
RXD
Text GLabel 10500 1450 2    60   Output ~ 0
TXD
Text GLabel 10200 1350 2    60   Input ~ 0
RXD
$Comp
L power:GND #PWR013
U 1 1 5BF93C01
P 7500 2150
F 0 "#PWR013" H 7500 1900 50  0001 C CNN
F 1 "GND" H 7500 2000 50  0000 C CNN
F 2 "" H 7500 2150 50  0001 C CNN
F 3 "" H 7500 2150 50  0001 C CNN
	1    7500 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5BF93CC5
P 8850 1950
F 0 "Y1" H 8850 2100 50  0000 C CNN
F 1 "Crystal" H 8850 1800 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_0603-2Pin_6.0x3.5mm_HandSoldering" H 8850 1950 50  0001 C CNN
F 3 "" H 8850 1950 50  0001 C CNN
	1    8850 1950
	-1   0    0    1   
$EndComp
Text GLabel 7850 1450 2    60   Input ~ 0
VUSB
Text GLabel 2400 6000 0    60   Output ~ 0
VUSB
$Comp
L power:+3.3V #PWR014
U 1 1 5BF96A06
P 9600 1050
F 0 "#PWR014" H 9600 900 50  0001 C CNN
F 1 "+3.3V" H 9600 1190 50  0000 C CNN
F 2 "" H 9600 1050 50  0001 C CNN
F 3 "" H 9600 1050 50  0001 C CNN
	1    9600 1050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5BF9C7E1
P 7150 3900
F 0 "SW3" V 7200 4000 50  0000 L CNN
F 1 "Mode" V 7150 3800 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7150 4100 50  0001 C CNN
F 3 "" H 7150 4100 50  0001 C CNN
	1    7150 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5BF9944F
P 9600 2450
F 0 "#PWR016" H 9600 2200 50  0001 C CNN
F 1 "GND" H 9600 2300 50  0000 C CNN
F 2 "" H 9600 2450 50  0001 C CNN
F 3 "" H 9600 2450 50  0001 C CNN
	1    9600 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5BFBCF59
P 8700 2500
F 0 "C5" H 8725 2600 50  0000 L CNN
F 1 "22p" H 8725 2400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8738 2350 50  0001 C CNN
F 3 "" H 8700 2500 50  0001 C CNN
	1    8700 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5BFBD323
P 9050 2500
F 0 "C6" H 9075 2600 50  0000 L CNN
F 1 "22p" H 9075 2400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9088 2350 50  0001 C CNN
F 3 "" H 9050 2500 50  0001 C CNN
	1    9050 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5BFBD9E2
P 8900 2700
F 0 "#PWR017" H 8900 2450 50  0001 C CNN
F 1 "GND" H 8900 2550 50  0000 C CNN
F 2 "" H 8900 2700 50  0001 C CNN
F 3 "" H 8900 2700 50  0001 C CNN
	1    8900 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5BFBF47A
P 9750 1100
F 0 "C7" V 9800 1250 50  0000 L CNN
F 1 "100n" V 9700 1200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9788 950 50  0001 C CNN
F 3 "" H 9750 1100 50  0001 C CNN
	1    9750 1100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5BFBF503
P 10100 1150
F 0 "#PWR018" H 10100 900 50  0001 C CNN
F 1 "GND" H 10100 1000 50  0000 C CNN
F 2 "" H 10100 1150 50  0001 C CNN
F 3 "" H 10100 1150 50  0001 C CNN
	1    10100 1150
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N5817 D1
U 1 1 5BFBFFBA
P 3550 6000
F 0 "D1" H 3550 6100 50  0000 C CNN
F 1 "1N5817" H 3550 5900 50  0000 C CNN
F 2 "Diode_SMD:D_SMA_Handsoldering" H 3550 5825 50  0001 C CNN
F 3 "" H 3550 6000 50  0001 C CNN
	1    3550 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5BFC22DC
P 4600 2050
F 0 "#PWR019" H 4600 1800 50  0001 C CNN
F 1 "GND" H 4600 1900 50  0000 C CNN
F 2 "" H 4600 2050 50  0001 C CNN
F 3 "" H 4600 2050 50  0001 C CNN
	1    4600 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR020
U 1 1 5BFC23B5
P 4700 2200
F 0 "#PWR020" H 4700 2050 50  0001 C CNN
F 1 "+3.3V" H 4700 2340 50  0000 C CNN
F 2 "" H 4700 2200 50  0001 C CNN
F 3 "" H 4700 2200 50  0001 C CNN
	1    4700 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5BFC3DA9
P 4600 1850
F 0 "J4" H 4600 2050 50  0000 C CNN
F 1 "MIC" V 4750 1850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4600 1850 50  0001 C CNN
F 3 "" H 4600 1850 50  0001 C CNN
	1    4600 1850
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5BFC851E
P 850 2650
F 0 "J2" H 1000 2600 50  0000 C CNN
F 1 "LED_CON_RGB" H 850 2350 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 850 2650 50  0001 C CNN
F 3 "" H 850 2650 50  0001 C CNN
	1    850  2650
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q4
U 1 1 5BFC8C8B
P 2100 4600
F 0 "Q4" H 2300 4650 50  0000 L CNN
F 1 "IRLZ34N" H 2300 4550 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2300 4700 50  0001 C CNN
F 3 "" H 2100 4600 50  0000 C CNN
	1    2100 4600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5BFC8C91
P 2500 4700
F 0 "#PWR021" H 2500 4450 50  0001 C CNN
F 1 "GND" H 2500 4550 50  0000 C CNN
F 2 "" H 2500 4700 50  0000 C CNN
F 3 "" H 2500 4700 50  0000 C CNN
	1    2500 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5BFC8C99
P 2100 4950
F 0 "R4" V 2180 4950 50  0000 C CNN
F 1 "100" V 2100 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2030 4950 50  0001 C CNN
F 3 "" H 2100 4950 50  0000 C CNN
	1    2100 4950
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q5
U 1 1 5BFC8ED3
P 3300 4600
F 0 "Q5" H 3500 4650 50  0000 L CNN
F 1 "IRLZ34N" H 3500 4550 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3500 4700 50  0001 C CNN
F 3 "" H 3300 4600 50  0000 C CNN
	1    3300 4600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5BFC8ED9
P 3700 4700
F 0 "#PWR022" H 3700 4450 50  0001 C CNN
F 1 "GND" H 3700 4550 50  0000 C CNN
F 2 "" H 3700 4700 50  0000 C CNN
F 3 "" H 3700 4700 50  0000 C CNN
	1    3700 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5BFC8EE1
P 3300 4950
F 0 "R5" V 3380 4950 50  0000 C CNN
F 1 "100" V 3300 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3230 4950 50  0001 C CNN
F 3 "" H 3300 4950 50  0000 C CNN
	1    3300 4950
	1    0    0    -1  
$EndComp
$Comp
L ESPLED-rescue:SCREW-TERMINAL-GREEN_2P-3.5_ P2
U 1 1 5BFCAF2C
P 2100 1000
F 0 "P2" H 2250 1000 45  0000 L BNN
F 1 "LED_CON_SCREW" H 1400 1000 45  0000 L BNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 2100 1000 60  0001 C CNN
F 3 "" H 2100 1000 60  0001 C CNN
F 4 "320110028" H 2130 1150 20  0001 C CNN "SKU"
	1    2100 1000
	0    -1   -1   0   
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5BFD35EA
P 4100 6550
F 0 "U1" H 3950 6675 50  0000 C CNN
F 1 "AMS1117-3.3" H 4100 6675 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 4100 6750 50  0001 C CNN
F 3 "" H 4200 6300 50  0001 C CNN
	1    4100 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 5BFD3912
P 3050 6000
F 0 "F1" V 2950 6000 50  0000 C CNN
F 1 "Polyfuse" V 3150 6000 50  0000 C CNN
F 2 "Fuse:Fuse_1812_4532Metric_Pad1.30x3.40mm_HandSolder" H 3100 5800 50  0001 L CNN
F 3 "" H 3050 6000 50  0001 C CNN
	1    3050 6000
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5BFD5B1D
P 2950 3500
F 0 "JP1" H 2950 3580 50  0000 C CNN
F 1 "GPIO LINK" H 2950 3400 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 2950 3500 50  0001 C CNN
F 3 "" H 2950 3500 50  0001 C CNN
	1    2950 3500
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5BFD5BE2
P 2000 3500
F 0 "JP2" H 2000 3580 50  0000 C CNN
F 1 "GPIO LINK" H 2000 3400 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 2000 3500 50  0001 C CNN
F 3 "" H 2000 3500 50  0001 C CNN
	1    2000 3500
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP3
U 1 1 5BFD5C80
P 1100 3500
F 0 "JP3" H 1100 3580 50  0000 C CNN
F 1 "GPIO LINK" H 1100 3400 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 1100 3500 50  0001 C CNN
F 3 "" H 1100 3500 50  0001 C CNN
	1    1100 3500
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP4
U 1 1 5BFD609D
P 1850 4700
F 0 "JP4" H 1850 4780 50  0000 C CNN
F 1 "GPIO LINK" H 1850 4600 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 1850 4700 50  0001 C CNN
F 3 "" H 1850 4700 50  0001 C CNN
	1    1850 4700
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP5
U 1 1 5BFD707F
P 3050 4700
F 0 "JP5" H 3050 4800 50  0000 C CNN
F 1 "GPIO LINK" H 3050 4600 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 3050 4700 50  0001 C CNN
F 3 "" H 3050 4700 50  0001 C CNN
	1    3050 4700
	0    1    1    0   
$EndComp
$Comp
L ESPLED-rescue:DS18B20 U4
U 1 1 5BFDDF4E
P 8550 3500
F 0 "U4" H 8400 3750 50  0000 C CNN
F 1 "DS18B20" H 8550 3250 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_HandSolder" H 8400 3750 50  0001 C CNN
F 3 "" H 8400 3750 50  0001 C CNN
	1    8550 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR024
U 1 1 5BFDE1DA
P 8200 3150
F 0 "#PWR024" H 8200 3000 50  0001 C CNN
F 1 "+3.3V" H 8200 3290 50  0000 C CNN
F 2 "" H 8200 3150 50  0001 C CNN
F 3 "" H 8200 3150 50  0001 C CNN
	1    8200 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5BFDE240
P 8200 3700
F 0 "#PWR025" H 8200 3450 50  0001 C CNN
F 1 "GND" H 8200 3550 50  0000 C CNN
F 2 "" H 8200 3700 50  0001 C CNN
F 3 "" H 8200 3700 50  0001 C CNN
	1    8200 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5BFDE492
P 8000 3350
F 0 "R8" V 8080 3350 50  0000 C CNN
F 1 "4.7K" V 8000 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7930 3350 50  0001 C CNN
F 3 "" H 8000 3350 50  0001 C CNN
	1    8000 3350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5BFE1746
P 7450 3900
F 0 "SW2" V 7500 4000 50  0000 L CNN
F 1 "Program" V 7300 4100 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7450 4100 50  0001 C CNN
F 3 "" H 7450 4100 50  0001 C CNN
	1    7450 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 7150 4500 6950
Wire Wire Line
	4500 6550 4500 6650
Wire Wire Line
	4400 6550 4500 6550
Wire Wire Line
	4900 6550 4900 6650
Connection ~ 4500 7150
Wire Wire Line
	3700 6000 3700 6550
Wire Wire Line
	3700 7150 3700 6950
Connection ~ 3700 7150
Wire Wire Line
	2750 6650 2750 6750
Connection ~ 4900 6550
Wire Wire Line
	5700 2350 5700 2500
Wire Wire Line
	2000 4050 2250 4050
Wire Wire Line
	1100 4100 1350 4100
Wire Wire Line
	1550 3350 1750 3350
Wire Wire Line
	1750 3350 1750 3550
Wire Wire Line
	2450 3350 2700 3350
Wire Wire Line
	2700 3350 2700 3550
Wire Wire Line
	3400 3350 3650 3350
Wire Wire Line
	3650 3350 3650 3550
Wire Wire Line
	3200 4000 3200 3950
Wire Wire Line
	2250 4050 2250 3950
Wire Wire Line
	1350 4100 1350 3950
Connection ~ 4100 7150
Connection ~ 4500 6550
Connection ~ 3700 6550
Wire Wire Line
	4800 3400 4350 3400
Wire Wire Line
	4350 3400 4350 3350
Wire Wire Line
	6800 3800 6600 3800
Wire Wire Line
	4650 3100 4650 3200
Wire Wire Line
	4650 3200 4800 3200
Wire Wire Line
	4900 7150 4900 6950
Connection ~ 5700 2500
Wire Wire Line
	4100 6850 4100 7150
Wire Wire Line
	7800 1650 9200 1650
Wire Wire Line
	7800 1750 9200 1750
Wire Wire Line
	6600 3200 6800 3200
Wire Wire Line
	6800 3200 6800 3150
Wire Wire Line
	6800 3150 6900 3150
Wire Wire Line
	6900 3350 6800 3350
Wire Wire Line
	6800 3350 6800 3300
Wire Wire Line
	6800 3300 6600 3300
Wire Wire Line
	7500 2050 7500 2100
Connection ~ 7500 2100
Wire Wire Line
	7850 1450 7800 1450
Wire Wire Line
	7400 2050 7400 2100
Wire Wire Line
	6800 4100 6950 4100
Wire Wire Line
	6950 4100 6950 4150
Connection ~ 6950 4100
Wire Wire Line
	6600 3600 7450 3600
Wire Wire Line
	9600 1050 9600 1100
Wire Wire Line
	9500 1150 9500 1100
Wire Wire Line
	9500 1100 9600 1100
Connection ~ 9600 1100
Wire Wire Line
	7400 2100 7500 2100
Wire Wire Line
	10000 1350 10200 1350
Wire Wire Line
	10000 1450 10500 1450
Wire Wire Line
	9600 2350 9600 2450
Wire Wire Line
	9050 1950 9050 2350
Wire Wire Line
	9000 1950 9050 1950
Wire Wire Line
	8700 1950 8550 1950
Wire Wire Line
	8550 1950 8550 2150
Wire Wire Line
	8550 2150 8700 2150
Connection ~ 9050 1950
Wire Wire Line
	8700 2350 8700 2150
Connection ~ 8700 2150
Wire Wire Line
	9900 1100 10100 1100
Wire Wire Line
	10100 1100 10100 1150
Wire Wire Line
	4800 3300 4500 3300
Wire Wire Line
	4500 3300 4500 2050
Wire Wire Line
	4700 2200 4700 2050
Wire Wire Line
	2300 4500 2500 4500
Wire Wire Line
	2500 4500 2500 4700
Wire Wire Line
	2950 4000 3200 4000
Wire Wire Line
	6750 3450 7850 3450
Wire Wire Line
	6750 3450 6750 3400
Wire Wire Line
	6750 3400 6600 3400
Wire Wire Line
	2100 5100 2100 5150
Wire Wire Line
	1850 5150 2100 5150
Wire Wire Line
	4450 5150 4450 3800
Wire Wire Line
	4300 4000 4300 3500
Wire Wire Line
	4300 3500 4800 3500
Wire Wire Line
	4800 3600 4350 3600
Wire Wire Line
	4350 3600 4350 4050
Wire Wire Line
	4400 4100 4400 3700
Wire Wire Line
	4400 3700 4800 3700
Wire Wire Line
	4450 3800 4800 3800
Wire Wire Line
	4500 4650 4500 5200
Wire Wire Line
	4500 5200 3300 5200
Wire Wire Line
	3050 5200 3050 4850
Wire Wire Line
	4500 4650 7850 4650
Wire Wire Line
	7850 4650 7850 3450
Connection ~ 2750 6750
Wire Wire Line
	2750 6550 3000 6550
Wire Wire Line
	2750 7150 3700 7150
Wire Wire Line
	3200 6000 3400 6000
Wire Wire Line
	2900 6000 2400 6000
Wire Wire Line
	2800 4500 3050 4500
Wire Wire Line
	3050 4550 3050 4500
Connection ~ 3050 4500
Wire Wire Line
	3300 5100 3300 5200
Connection ~ 3300 5200
Wire Wire Line
	1850 4850 1850 5150
Connection ~ 2100 5150
Wire Wire Line
	1900 4500 1850 4500
Wire Wire Line
	1100 3350 1150 3350
Wire Wire Line
	1100 3650 1100 4100
Connection ~ 1350 4100
Wire Wire Line
	2000 3650 2000 4050
Connection ~ 2250 4050
Wire Wire Line
	2950 3650 2950 4000
Connection ~ 3200 4000
Wire Wire Line
	2950 3350 3000 3350
Wire Wire Line
	2000 3350 2050 3350
Wire Wire Line
	3500 4500 3700 4500
Wire Wire Line
	3700 4500 3700 4700
Wire Wire Line
	8200 3150 8200 3200
Wire Wire Line
	8200 3400 8250 3400
Wire Wire Line
	8200 3700 8200 3600
Wire Wire Line
	8200 3600 8250 3600
Wire Wire Line
	6600 3500 8000 3500
Connection ~ 8000 3500
Wire Wire Line
	8000 3200 8200 3200
Connection ~ 8200 3200
Wire Wire Line
	8700 2650 8700 2700
Wire Wire Line
	8700 2700 8900 2700
Wire Wire Line
	9050 2700 9050 2650
Connection ~ 8900 2700
Wire Wire Line
	7450 3600 7450 3700
Connection ~ 7150 4100
Wire Wire Line
	6600 3700 7150 3700
$Comp
L power:+12V #PWR026
U 1 1 5BFE6E81
P 3000 6500
F 0 "#PWR026" H 3000 6350 50  0001 C CNN
F 1 "+12V" H 3000 6640 50  0000 C CNN
F 2 "" H 3000 6500 50  0001 C CNN
F 3 "" H 3000 6500 50  0001 C CNN
	1    3000 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 6500 3000 6550
Connection ~ 3000 6550
$Comp
L Device:C C1
U 1 1 5967BEE6
P 3700 6800
F 0 "C1" H 3725 6900 50  0000 L CNN
F 1 "1uF" H 3725 6700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3738 6650 50  0001 C CNN
F 3 "" H 3700 6800 50  0000 C CNN
	1    3700 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 7150 4900 7150
Wire Wire Line
	3700 7150 4100 7150
Wire Wire Line
	4900 6550 5400 6550
Wire Wire Line
	4100 7150 4100 7250
Wire Wire Line
	4100 7150 4500 7150
Wire Wire Line
	4500 6550 4900 6550
Wire Wire Line
	3700 6550 3700 6650
Wire Wire Line
	3700 6550 3800 6550
Wire Wire Line
	5700 2500 5700 2600
Wire Wire Line
	7500 2100 7500 2150
Wire Wire Line
	6950 4100 7150 4100
Wire Wire Line
	9600 1100 9600 1150
Wire Wire Line
	9050 1950 9200 1950
Wire Wire Line
	8700 2150 9200 2150
Wire Wire Line
	2750 6750 2750 7150
Wire Wire Line
	3050 4500 3100 4500
Wire Wire Line
	3300 5200 3050 5200
Wire Wire Line
	2100 5150 4450 5150
Wire Wire Line
	1350 4100 4400 4100
Wire Wire Line
	2250 4050 4350 4050
Wire Wire Line
	3200 4000 4300 4000
Wire Wire Line
	1850 4500 1850 4550
Wire Wire Line
	8000 3500 8250 3500
Wire Wire Line
	8200 3200 8200 3400
Wire Wire Line
	8900 2700 9050 2700
Wire Wire Line
	7150 4100 7450 4100
Wire Wire Line
	3000 6550 3700 6550
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5C346E88
P 850 2950
F 0 "J3" H 1000 2900 50  0000 C CNN
F 1 "LED_CON_WW" H 850 3050 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 850 2950 50  0001 C CNN
F 3 "~" H 850 2950 50  0001 C CNN
	1    850  2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	1050 2450 1100 2450
$Comp
L power:+12V #PWR0101
U 1 1 5C362ECD
P 3000 2750
F 0 "#PWR0101" H 3000 2600 50  0001 C CNN
F 1 "+12V" V 3015 2878 50  0000 L CNN
F 2 "" H 3000 2750 50  0001 C CNN
F 3 "" H 3000 2750 50  0001 C CNN
	1    3000 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 2750 1400 2750
Wire Wire Line
	1050 2550 2000 2550
Wire Wire Line
	1050 2650 1600 2650
Wire Wire Line
	1050 2850 2750 2850
Wire Wire Line
	1050 2950 1850 2950
Wire Wire Line
	2950 3350 2950 2650
Connection ~ 2950 3350
Connection ~ 2950 2650
Wire Wire Line
	2950 2650 3000 2650
Wire Wire Line
	1400 1200 1400 2750
Connection ~ 1400 2750
Wire Wire Line
	1400 2750 3000 2750
Wire Wire Line
	1600 1200 1600 2650
Connection ~ 1600 2650
Wire Wire Line
	1600 2650 2950 2650
Wire Wire Line
	2000 1200 2000 2550
Connection ~ 2000 2550
Wire Wire Line
	2000 2550 3000 2550
Wire Wire Line
	2200 1200 2200 2450
Connection ~ 2200 2450
Wire Wire Line
	2200 2450 3000 2450
Wire Wire Line
	2550 1200 2550 2950
Connection ~ 2550 2950
Wire Wire Line
	2550 2950 3000 2950
Wire Wire Line
	2750 1200 2750 2850
Connection ~ 2750 2850
Wire Wire Line
	2750 2850 2800 2850
Wire Wire Line
	2000 3350 2000 2550
Connection ~ 2000 3350
Wire Wire Line
	1100 3350 1100 2450
Connection ~ 1100 3350
Connection ~ 1100 2450
Wire Wire Line
	1100 2450 2200 2450
Wire Wire Line
	1850 4500 1850 2950
Connection ~ 1850 4500
Connection ~ 1850 2950
Wire Wire Line
	1850 2950 2550 2950
Wire Wire Line
	2800 4500 2800 2850
Connection ~ 2800 2850
Wire Wire Line
	2800 2850 3000 2850
Text Label 3000 2650 0    60   ~ 0
CH1
Text Label 3000 2550 0    60   ~ 0
CH2
Text Label 3000 2450 0    60   ~ 0
CH3
Text Label 3000 2950 0    60   ~ 0
CH4
Text Label 3000 2850 0    60   ~ 0
CH5
$EndSCHEMATC
