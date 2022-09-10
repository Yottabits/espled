EESchema Schematic File Version 4
EELAYER 30 0
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
L ESPLED-rescue:ESP-07v2-ESP8266 U2
U 1 1 5967B927
P 8750 4400
F 0 "U2" H 8750 4300 50  0000 C CNN
F 1 "ESP-07v2" H 8750 4500 50  0000 C CNN
F 2 "RF_Module:ESP-07" H 8750 4400 50  0001 C CNN
F 3 "" H 8750 4400 50  0001 C CNN
	1    8750 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5967BCCF
P 3800 7550
F 0 "#PWR01" H 3800 7300 50  0001 C CNN
F 1 "GND" H 3800 7400 50  0000 C CNN
F 2 "" H 3800 7550 50  0000 C CNN
F 3 "" H 3800 7550 50  0000 C CNN
	1    3800 7550
	1    0    0    -1  
$EndComp
$Comp
L ESPLED-rescue:BARREL_JACK CON1
U 1 1 5967C03C
P 2150 6950
F 0 "CON1" H 2150 7200 50  0000 C CNN
F 1 "BARREL_JACK" H 2150 6750 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 2150 6950 50  0001 C CNN
F 3 "" H 2150 6950 50  0000 C CNN
	1    2150 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5967C79C
P 8750 5300
F 0 "#PWR02" H 8750 5050 50  0001 C CNN
F 1 "GND" H 8750 5150 50  0000 C CNN
F 2 "" H 8750 5300 50  0000 C CNN
F 3 "" H 8750 5300 50  0000 C CNN
	1    8750 5300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 5967C984
P 6250 6850
F 0 "#PWR03" H 6250 6700 50  0001 C CNN
F 1 "+3.3V" H 6250 6990 50  0000 C CNN
F 2 "" H 6250 6850 50  0000 C CNN
F 3 "" H 6250 6850 50  0000 C CNN
	1    6250 6850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR04
U 1 1 5967C9A6
P 8750 3250
F 0 "#PWR04" H 8750 3100 50  0001 C CNN
F 1 "+3.3V" H 8750 3390 50  0000 C CNN
F 2 "" H 8750 3250 50  0000 C CNN
F 3 "" H 8750 3250 50  0000 C CNN
	1    8750 3250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q1
U 1 1 5967CE85
P 3250 3900
F 0 "Q1" H 3450 3950 50  0000 L CNN
F 1 "IRLZ34N" H 3450 3850 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3450 4000 50  0001 C CNN
F 3 "" H 3250 3900 50  0000 C CNN
	1    3250 3900
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q2
U 1 1 5967CF02
P 2300 3900
F 0 "Q2" H 2500 3950 50  0000 L CNN
F 1 "IRLZ34N" H 2500 3850 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2500 4000 50  0001 C CNN
F 3 "" H 2300 3900 50  0000 C CNN
	1    2300 3900
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q3
U 1 1 5967CF69
P 1400 3900
F 0 "Q3" H 1600 3950 50  0000 L CNN
F 1 "IRLZ34N" H 1600 3850 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 1600 4000 50  0001 C CNN
F 3 "" H 1400 3900 50  0000 C CNN
	1    1400 3900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5967D031
P 1800 4000
F 0 "#PWR05" H 1800 3750 50  0001 C CNN
F 1 "GND" H 1800 3850 50  0000 C CNN
F 2 "" H 1800 4000 50  0000 C CNN
F 3 "" H 1800 4000 50  0000 C CNN
	1    1800 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5967D059
P 2750 4000
F 0 "#PWR06" H 2750 3750 50  0001 C CNN
F 1 "GND" H 2750 3850 50  0000 C CNN
F 2 "" H 2750 4000 50  0000 C CNN
F 3 "" H 2750 4000 50  0000 C CNN
	1    2750 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5967D081
P 3700 4000
F 0 "#PWR07" H 3700 3750 50  0001 C CNN
F 1 "GND" H 3700 3850 50  0000 C CNN
F 2 "" H 3700 4000 50  0000 C CNN
F 3 "" H 3700 4000 50  0000 C CNN
	1    3700 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5967D7DD
P 3250 4250
F 0 "R1" V 3330 4250 50  0000 C CNN
F 1 "100" V 3250 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3180 4250 50  0001 C CNN
F 3 "" H 3250 4250 50  0000 C CNN
	1    3250 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5967D812
P 2300 4250
F 0 "R2" V 2380 4250 50  0000 C CNN
F 1 "100" V 2300 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2230 4250 50  0001 C CNN
F 3 "" H 2300 4250 50  0000 C CNN
	1    2300 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5967D86A
P 1400 4250
F 0 "R3" V 1480 4250 50  0000 C CNN
F 1 "100" V 1400 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1330 4250 50  0001 C CNN
F 3 "" H 1400 4250 50  0000 C CNN
	1    1400 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5967E72B
P 7500 4100
F 0 "R6" V 7580 4100 50  0000 C CNN
F 1 "10k" V 7500 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7430 4100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/2110260030_UNI-ROYAL-Uniroyal-Elec-0603WAF1002T5E_C25804.pdf" H 7500 4100 50  0001 C CNN
F 4 "C25804" V 7500 4100 50  0001 C CNN "JLCPCB"
	1    7500 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5967E7A8
P 9850 4850
F 0 "R7" V 9930 4850 50  0000 C CNN
F 1 "10k" V 9850 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9780 4850 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/2110260030_UNI-ROYAL-Uniroyal-Elec-0603WAF1002T5E_C25804.pdf" H 9850 4850 50  0001 C CNN
F 4 "C25804" V 9850 4850 50  0001 C CNN "JLCPCB"
	1    9850 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 59680365
P 10000 5050
F 0 "#PWR09" H 10000 4800 50  0001 C CNN
F 1 "GND" H 10000 4900 50  0000 C CNN
F 2 "" H 10000 5050 50  0000 C CNN
F 3 "" H 10000 5050 50  0000 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 59680549
P 7500 3950
F 0 "#PWR010" H 7500 3800 50  0001 C CNN
F 1 "+3.3V" H 7500 4090 50  0000 C CNN
F 2 "" H 7500 3950 50  0000 C CNN
F 3 "" H 7500 3950 50  0000 C CNN
	1    7500 3950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5967D035
P 7800 3800
F 0 "SW1" V 7850 3900 50  0000 L CNN
F 1 "Reset" V 7750 4000 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7800 4000 50  0001 C CNN
F 3 "" H 7800 4000 50  0000 C CNN
	1    7800 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5967D1A1
P 7800 3600
F 0 "#PWR011" H 7800 3350 50  0001 C CNN
F 1 "GND" H 7800 3450 50  0000 C CNN
F 2 "" H 7800 3600 50  0000 C CNN
F 3 "" H 7800 3600 50  0000 C CNN
	1    7800 3600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C4
U 1 1 5A98853F
P 8900 3400
F 0 "C4" H 8925 3500 50  0000 L CNN
F 1 "100nF" H 8600 3500 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8938 3250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1809301912_YAGEO-CC0603KRX7R9BB104_C14663.pdf" H 8900 3400 50  0001 C CNN
F 4 "C14663" H 8900 3400 50  0001 C CNN "JLCPCB"
	1    8900 3400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5A9889A8
P 9050 3400
F 0 "#PWR012" H 9050 3150 50  0001 C CNN
F 1 "GND" H 9050 3250 50  0000 C CNN
F 2 "" H 9050 3400 50  0001 C CNN
F 3 "" H 9050 3400 50  0001 C CNN
	1    9050 3400
	0    -1   -1   0   
$EndComp
$Comp
L Interface_USB:CH340G U3
U 1 1 5BF8FEBF
P 9850 1500
F 0 "U3" H 9550 900 45  0000 L BNN
F 1 "INTERFACE-CH340G" H 10000 900 45  0000 L BNN
F 2 "Package_SO:SOP-16_4.4x10.4mm_P1.27mm" H 9850 1500 60  0001 C CNN
F 3 "" H 9850 1500 60  0001 C CNN
F 4 "CH340T" H 9880 1650 20  0001 C CNN "MPN"
F 5 "310070026" H 9880 1650 20  0001 C CNN "SKU"
F 6 "C14267" H 9850 1500 50  0001 C CNN "JLCPCB"
	1    9850 1500
	1    0    0    -1  
$EndComp
$Comp
L ESPLED-rescue:USB_B_Micro-Connector J1
U 1 1 5BF90B72
P 7750 1400
F 0 "J1" H 7550 1850 50  0000 L CNN
F 1 "USB_B_Micro" H 7550 1750 50  0000 L CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 7900 1350 50  0001 C CNN
F 3 "" H 7900 1350 50  0001 C CNN
	1    7750 1400
	1    0    0    -1  
$EndComp
Text GLabel 9750 4100 2    60   Output ~ 0
TXD
Text GLabel 9950 4200 2    60   Input ~ 0
RXD
Text GLabel 10750 1200 2    60   Output ~ 0
TXD
Text GLabel 10450 1100 2    60   Input ~ 0
RXD
$Comp
L power:GND #PWR013
U 1 1 5BF93C01
P 7750 1900
F 0 "#PWR013" H 7750 1650 50  0001 C CNN
F 1 "GND" H 7750 1750 50  0000 C CNN
F 2 "" H 7750 1900 50  0001 C CNN
F 3 "" H 7750 1900 50  0001 C CNN
	1    7750 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5BF93CC5
P 9100 1700
F 0 "Y1" H 9100 1850 50  0000 C CNN
F 1 "12MHz" H 9100 1550 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 9100 1700 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/2103291203_Yangxing-Tech-X322512MSB4SI_C9002.pdf" H 9100 1700 50  0001 C CNN
F 4 "C9002" H 9100 1700 50  0001 C CNN "JLCPCB"
	1    9100 1700
	-1   0    0    1   
$EndComp
Text GLabel 8100 1200 2    60   Input ~ 0
VUSB
Text GLabel 2100 6300 0    60   Output ~ 0
VUSB
$Comp
L power:+3.3V #PWR014
U 1 1 5BF96A06
P 9850 800
F 0 "#PWR014" H 9850 650 50  0001 C CNN
F 1 "+3.3V" H 9850 940 50  0000 C CNN
F 2 "" H 9850 800 50  0001 C CNN
F 3 "" H 9850 800 50  0001 C CNN
	1    9850 800 
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5BF9C7E1
P 10200 4800
F 0 "SW3" V 10250 4900 50  0000 L CNN
F 1 "Mode" V 10200 4700 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 10200 5000 50  0001 C CNN
F 3 "" H 10200 5000 50  0001 C CNN
	1    10200 4800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5BF9944F
P 9850 2200
F 0 "#PWR016" H 9850 1950 50  0001 C CNN
F 1 "GND" H 9850 2050 50  0000 C CNN
F 2 "" H 9850 2200 50  0001 C CNN
F 3 "" H 9850 2200 50  0001 C CNN
	1    9850 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5BFBCF59
P 8950 2250
F 0 "C5" H 8975 2350 50  0000 L CNN
F 1 "22p" H 8975 2150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8988 2100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810121815_Samsung-Electro-Mechanics-CL10C220JB8NNNC_C1653.pdf" H 8950 2250 50  0001 C CNN
F 4 "C1653" H 8950 2250 50  0001 C CNN "JLCPCB"
	1    8950 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5BFBD323
P 9300 2250
F 0 "C6" H 9325 2350 50  0000 L CNN
F 1 "22p" H 9325 2150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9338 2100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1810121815_Samsung-Electro-Mechanics-CL10C220JB8NNNC_C1653.pdf" H 9300 2250 50  0001 C CNN
F 4 "C1653" H 9300 2250 50  0001 C CNN "JLCPCB"
	1    9300 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5BFBD9E2
P 9150 2450
F 0 "#PWR017" H 9150 2200 50  0001 C CNN
F 1 "GND" H 9150 2300 50  0000 C CNN
F 2 "" H 9150 2450 50  0001 C CNN
F 3 "" H 9150 2450 50  0001 C CNN
	1    9150 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5BFBF47A
P 10000 850
F 0 "C7" V 10050 1000 50  0000 L CNN
F 1 "100n" V 9950 950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 10038 700 50  0001 C CNN
F 3 "" H 10000 850 50  0001 C CNN
	1    10000 850 
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5BFBF503
P 10350 900
F 0 "#PWR018" H 10350 650 50  0001 C CNN
F 1 "GND" H 10350 750 50  0000 C CNN
F 2 "" H 10350 900 50  0001 C CNN
F 3 "" H 10350 900 50  0001 C CNN
	1    10350 900 
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N5817 D1
U 1 1 5BFBFFBA
P 3250 6300
F 0 "D1" H 3250 6400 50  0000 C CNN
F 1 "1N5817" H 3250 6200 50  0000 C CNN
F 2 "Diode_SMD:D_SMA_Handsoldering" H 3250 6125 50  0001 C CNN
F 3 "" H 3250 6300 50  0001 C CNN
	1    3250 6300
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5BFC22DC
P 7750 2950
F 0 "#PWR019" H 7750 2700 50  0001 C CNN
F 1 "GND" H 7750 2800 50  0000 C CNN
F 2 "" H 7750 2950 50  0001 C CNN
F 3 "" H 7750 2950 50  0001 C CNN
	1    7750 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR020
U 1 1 5BFC23B5
P 7850 3100
F 0 "#PWR020" H 7850 2950 50  0001 C CNN
F 1 "+3.3V" H 7850 3240 50  0000 C CNN
F 2 "" H 7850 3100 50  0001 C CNN
F 3 "" H 7850 3100 50  0001 C CNN
	1    7850 3100
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5BFC3DA9
P 7750 2750
F 0 "J4" H 7750 2950 50  0000 C CNN
F 1 "MIC" V 7900 2750 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7750 2750 50  0001 C CNN
F 3 "" H 7750 2750 50  0001 C CNN
	1    7750 2750
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5BFC851E
P 900 3100
F 0 "J2" H 1050 3050 50  0000 C CNN
F 1 "LED_CON_RGB" H 900 2800 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 900 3100 50  0001 C CNN
F 3 "" H 900 3100 50  0001 C CNN
	1    900  3100
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q4
U 1 1 5BFC8C8B
P 2150 5050
F 0 "Q4" H 2350 5100 50  0000 L CNN
F 1 "IRLZ34N" H 2350 5000 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2350 5150 50  0001 C CNN
F 3 "" H 2150 5050 50  0000 C CNN
	1    2150 5050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5BFC8C91
P 2550 5150
F 0 "#PWR021" H 2550 4900 50  0001 C CNN
F 1 "GND" H 2550 5000 50  0000 C CNN
F 2 "" H 2550 5150 50  0000 C CNN
F 3 "" H 2550 5150 50  0000 C CNN
	1    2550 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5BFC8C99
P 2150 5400
F 0 "R4" V 2230 5400 50  0000 C CNN
F 1 "100" V 2150 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2080 5400 50  0001 C CNN
F 3 "" H 2150 5400 50  0000 C CNN
	1    2150 5400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q5
U 1 1 5BFC8ED3
P 3350 5050
F 0 "Q5" H 3550 5100 50  0000 L CNN
F 1 "IRLZ34N" H 3550 5000 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 3550 5150 50  0001 C CNN
F 3 "" H 3350 5050 50  0000 C CNN
	1    3350 5050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5BFC8ED9
P 3750 5150
F 0 "#PWR022" H 3750 4900 50  0001 C CNN
F 1 "GND" H 3750 5000 50  0000 C CNN
F 2 "" H 3750 5150 50  0000 C CNN
F 3 "" H 3750 5150 50  0000 C CNN
	1    3750 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5BFC8EE1
P 3350 5400
F 0 "R5" V 3430 5400 50  0000 C CNN
F 1 "100" V 3350 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 5400 50  0001 C CNN
F 3 "" H 3350 5400 50  0000 C CNN
	1    3350 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 5BFD3912
P 2750 6300
F 0 "F1" V 2650 6300 50  0000 C CNN
F 1 "Polyfuse" V 2850 6300 50  0000 C CNN
F 2 "Fuse:Fuse_1812_4532Metric_Pad1.30x3.40mm_HandSolder" H 2800 6100 50  0001 L CNN
F 3 "" H 2750 6300 50  0001 C CNN
	1    2750 6300
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5BFD5B1D
P 3000 3950
F 0 "JP1" H 3000 4030 50  0000 C CNN
F 1 "GPIO LINK" H 3000 3850 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 3000 3950 50  0001 C CNN
F 3 "" H 3000 3950 50  0001 C CNN
	1    3000 3950
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5BFD5BE2
P 2050 3950
F 0 "JP2" H 2050 4030 50  0000 C CNN
F 1 "GPIO LINK" H 2050 3850 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 2050 3950 50  0001 C CNN
F 3 "" H 2050 3950 50  0001 C CNN
	1    2050 3950
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP3
U 1 1 5BFD5C80
P 1150 3950
F 0 "JP3" H 1150 4030 50  0000 C CNN
F 1 "GPIO LINK" H 1150 3850 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 1150 3950 50  0001 C CNN
F 3 "" H 1150 3950 50  0001 C CNN
	1    1150 3950
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP4
U 1 1 5BFD609D
P 1900 5150
F 0 "JP4" H 1900 5230 50  0000 C CNN
F 1 "GPIO LINK" H 1900 5050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 1900 5150 50  0001 C CNN
F 3 "" H 1900 5150 50  0001 C CNN
	1    1900 5150
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP5
U 1 1 5BFD707F
P 3100 5150
F 0 "JP5" H 3100 5250 50  0000 C CNN
F 1 "GPIO LINK" H 3100 5050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 3100 5150 50  0001 C CNN
F 3 "" H 3100 5150 50  0001 C CNN
	1    3100 5150
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5BFE1746
P 10500 4800
F 0 "SW2" V 10550 4900 50  0000 L CNN
F 1 "Program" V 10350 5000 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 10500 5000 50  0001 C CNN
F 3 "" H 10500 5000 50  0001 C CNN
	1    10500 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 6950 2450 7050
Wire Wire Line
	8750 3250 8750 3400
Wire Wire Line
	1600 3800 1800 3800
Wire Wire Line
	1800 3800 1800 4000
Wire Wire Line
	2500 3800 2750 3800
Wire Wire Line
	2750 3800 2750 4000
Wire Wire Line
	3450 3800 3700 3800
Wire Wire Line
	3700 3800 3700 4000
Connection ~ 3800 7450
Wire Wire Line
	7500 4300 7500 4250
Wire Wire Line
	9850 4700 9650 4700
Wire Wire Line
	7800 4000 7800 4100
Connection ~ 8750 3400
Wire Wire Line
	8050 1400 9450 1400
Wire Wire Line
	8050 1500 9450 1500
Wire Wire Line
	7750 1800 7750 1850
Connection ~ 7750 1850
Wire Wire Line
	8100 1200 8050 1200
Wire Wire Line
	7650 1800 7650 1850
Wire Wire Line
	9850 5000 10000 5000
Wire Wire Line
	10000 5000 10000 5050
Connection ~ 10000 5000
Wire Wire Line
	9650 4500 10500 4500
Wire Wire Line
	9850 800  9850 850 
Wire Wire Line
	9750 900  9750 850 
Wire Wire Line
	9750 850  9850 850 
Connection ~ 9850 850 
Wire Wire Line
	7650 1850 7750 1850
Wire Wire Line
	10250 1100 10450 1100
Wire Wire Line
	10250 1200 10750 1200
Wire Wire Line
	9850 2100 9850 2200
Wire Wire Line
	9300 1700 9300 2100
Wire Wire Line
	9250 1700 9300 1700
Wire Wire Line
	8950 1700 8800 1700
Wire Wire Line
	8800 1700 8800 1900
Wire Wire Line
	8800 1900 8950 1900
Connection ~ 9300 1700
Wire Wire Line
	8950 2100 8950 1900
Connection ~ 8950 1900
Wire Wire Line
	10150 850  10350 850 
Wire Wire Line
	10350 850  10350 900 
Wire Wire Line
	7650 4200 7650 2950
Wire Wire Line
	7850 3100 7850 2950
Wire Wire Line
	2350 4950 2550 4950
Wire Wire Line
	2550 4950 2550 5150
Wire Wire Line
	2150 5550 2150 5600
Wire Wire Line
	1900 5600 2150 5600
Wire Wire Line
	7350 4400 7850 4400
Wire Wire Line
	7850 4500 7400 4500
Wire Wire Line
	7450 4600 7850 4600
Wire Wire Line
	7500 4700 7850 4700
Connection ~ 2450 7050
Wire Wire Line
	2450 6850 2700 6850
Wire Wire Line
	2900 6300 3100 6300
Wire Wire Line
	2600 6300 2100 6300
Wire Wire Line
	2850 4950 3100 4950
Wire Wire Line
	3100 5000 3100 4950
Connection ~ 3100 4950
Wire Wire Line
	1900 5300 1900 5600
Wire Wire Line
	1950 4950 1900 4950
Wire Wire Line
	1150 3800 1200 3800
Wire Wire Line
	3000 3800 3050 3800
Wire Wire Line
	2050 3800 2100 3800
Wire Wire Line
	3550 4950 3750 4950
Wire Wire Line
	3750 4950 3750 5150
Wire Wire Line
	8950 2400 8950 2450
Wire Wire Line
	8950 2450 9150 2450
Wire Wire Line
	9300 2450 9300 2400
Connection ~ 9150 2450
Wire Wire Line
	10500 4500 10500 4600
Connection ~ 10200 5000
Wire Wire Line
	9650 4600 10200 4600
$Comp
L power:+12V #PWR026
U 1 1 5BFE6E81
P 2700 6800
F 0 "#PWR026" H 2700 6650 50  0001 C CNN
F 1 "+12V" H 2700 6940 50  0000 C CNN
F 2 "" H 2700 6800 50  0001 C CNN
F 3 "" H 2700 6800 50  0001 C CNN
	1    2700 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 6800 2700 6850
Connection ~ 2700 6850
Wire Wire Line
	3800 7450 3800 7550
Wire Wire Line
	8750 3400 8750 3500
Wire Wire Line
	7750 1850 7750 1900
Wire Wire Line
	10000 5000 10200 5000
Wire Wire Line
	9850 850  9850 900 
Wire Wire Line
	9300 1700 9450 1700
Wire Wire Line
	8950 1900 9450 1900
Wire Wire Line
	2450 7050 2450 7450
Wire Wire Line
	3100 4950 3150 4950
Wire Wire Line
	1900 4950 1900 5000
Wire Wire Line
	9150 2450 9300 2450
Wire Wire Line
	10200 5000 10500 5000
Wire Wire Line
	2700 6850 3400 6850
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5C346E88
P 900 3400
F 0 "J3" H 1050 3350 50  0000 C CNN
F 1 "LED_CON_WW" H 900 3500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 900 3400 50  0001 C CNN
F 3 "~" H 900 3400 50  0001 C CNN
	1    900  3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	1100 2900 1150 2900
$Comp
L power:+12V #PWR0101
U 1 1 5C362ECD
P 3050 3200
F 0 "#PWR0101" H 3050 3050 50  0001 C CNN
F 1 "+12V" V 3000 3300 50  0000 L CNN
F 2 "" H 3050 3200 50  0001 C CNN
F 3 "" H 3050 3200 50  0001 C CNN
	1    3050 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	1100 3000 1950 3000
Wire Wire Line
	1100 3300 2250 3300
Wire Wire Line
	1100 3400 1900 3400
Wire Wire Line
	3000 3800 3000 3100
Connection ~ 3000 3800
Connection ~ 3000 3100
Wire Wire Line
	3000 3100 3050 3100
Connection ~ 2050 3000
Wire Wire Line
	2050 3000 3050 3000
Wire Wire Line
	2050 3800 2050 3000
Connection ~ 2050 3800
Wire Wire Line
	1150 3800 1150 2900
Connection ~ 1150 3800
Connection ~ 1150 2900
Wire Wire Line
	1900 4950 1900 3400
Connection ~ 1900 4950
Connection ~ 1900 3400
Wire Wire Line
	1900 3400 2150 3400
Wire Wire Line
	2850 4950 2850 3300
Connection ~ 2850 3300
Wire Wire Line
	2850 3300 3050 3300
Text Label 3050 3100 0    60   ~ 0
CH1
Text Label 3050 3000 0    60   ~ 0
CH2
Text Label 3050 2900 0    60   ~ 0
CH3
Text Label 3050 3400 0    60   ~ 0
CH4
Text Label 3050 3300 0    60   ~ 0
CH5
$Comp
L Logic_LevelTranslator:TXS0108EPW U5
U 1 1 5C3E7605
P 5750 3950
F 0 "U5" H 5750 5050 50  0000 C CNN
F 1 "TXS0108EPW" H 5750 4950 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 5750 3200 50  0001 C CNN
F 3 "www.ti.com/lit/ds/symlink/txs0108e.pdf" H 5750 3850 50  0001 C CNN
F 4 "C17206" H 5750 3950 50  0001 C CNN "JLCPCB"
	1    5750 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	5350 3750 5200 3750
Wire Wire Line
	5350 3850 5100 3850
Wire Wire Line
	5350 3950 5000 3950
Wire Wire Line
	5350 4050 4900 4050
Wire Wire Line
	6300 3750 6300 2750
Wire Wire Line
	6300 2750 5900 2750
Wire Wire Line
	5200 2750 5200 3750
Wire Wire Line
	6300 3750 6150 3750
Wire Wire Line
	6400 3850 6400 2650
Wire Wire Line
	6400 2650 5900 2650
Wire Wire Line
	5100 2650 5100 3850
Wire Wire Line
	6400 3850 6150 3850
Wire Wire Line
	6500 3950 6500 2550
Wire Wire Line
	6500 2550 5900 2550
Wire Wire Line
	5000 2550 5000 3950
Wire Wire Line
	6500 3950 6150 3950
Wire Wire Line
	6600 4050 6600 2450
Wire Wire Line
	4900 2450 4900 4050
Wire Wire Line
	6600 4050 6150 4050
Wire Wire Line
	6700 4150 6700 2350
Wire Wire Line
	6700 4150 6150 4150
Wire Wire Line
	6600 2450 5900 2450
Wire Wire Line
	6700 2350 5900 2350
Wire Wire Line
	4800 2350 4800 4150
Wire Wire Line
	5350 4150 4800 4150
$Comp
L Jumper:SolderJumper_2_Open JP6
U 1 1 5C4A3527
P 5750 2350
F 0 "JP6" H 6200 2900 50  0000 C CNN
F 1 "GPIO LINK" H 5200 2900 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5750 2350 50  0001 C CNN
F 3 "~" H 5750 2350 50  0001 C CNN
	1    5750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2350 4800 2350
$Comp
L Jumper:SolderJumper_2_Open JP7
U 1 1 5C4A375E
P 5750 2450
F 0 "JP7" H 6200 3000 50  0000 C CNN
F 1 "GPIO LINK" H 5200 3000 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5750 2450 50  0001 C CNN
F 3 "~" H 5750 2450 50  0001 C CNN
	1    5750 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2450 4900 2450
$Comp
L Jumper:SolderJumper_2_Open JP8
U 1 1 5C4A3848
P 5750 2550
F 0 "JP8" H 6200 3100 50  0000 C CNN
F 1 "GPIO LINK" H 5200 3100 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5750 2550 50  0001 C CNN
F 3 "~" H 5750 2550 50  0001 C CNN
	1    5750 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2550 5000 2550
$Comp
L Jumper:SolderJumper_2_Open JP9
U 1 1 5C4A3913
P 5750 2650
F 0 "JP9" H 6200 3200 50  0000 C CNN
F 1 "GPIO LINK" H 5200 3200 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5750 2650 50  0001 C CNN
F 3 "~" H 5750 2650 50  0001 C CNN
	1    5750 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2650 5100 2650
$Comp
L Jumper:SolderJumper_2_Open JP10
U 1 1 5C4A39F1
P 5750 2750
F 0 "JP10" H 6200 3300 50  0000 C CNN
F 1 "GPIO LINK" H 5200 3300 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5750 2750 50  0001 C CNN
F 3 "~" H 5750 2750 50  0001 C CNN
	1    5750 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2750 5200 2750
$Comp
L power:GND #PWR0102
U 1 1 5C4A4F05
P 5750 3250
F 0 "#PWR0102" H 5750 3000 50  0001 C CNN
F 1 "GND" H 5750 3100 50  0000 C CNN
F 2 "" H 5750 3250 50  0000 C CNN
F 3 "" H 5750 3250 50  0000 C CNN
	1    5750 3250
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 5C4E12E2
P 5850 4650
F 0 "#PWR0103" H 5850 4500 50  0001 C CNN
F 1 "+3.3V" H 5750 4800 50  0000 C CNN
F 2 "" H 5850 4650 50  0001 C CNN
F 3 "" H 5850 4650 50  0001 C CNN
	1    5850 4650
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR0104
U 1 1 5C4F957B
P 5650 4650
F 0 "#PWR0104" H 5650 4500 50  0001 C CNN
F 1 "+12V" H 5750 4800 50  0000 C CNN
F 2 "" H 5650 4650 50  0001 C CNN
F 3 "" H 5650 4650 50  0001 C CNN
	1    5650 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	6150 4650 6150 4350
Connection ~ 5850 4650
$Comp
L Device:C C9
U 1 1 5C538000
P 6250 4850
F 0 "C9" V 5998 4850 50  0000 C CNN
F 1 "100nF" V 6089 4850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6288 4700 50  0001 C CNN
F 3 "~" H 6250 4850 50  0001 C CNN
F 4 "C14663" V 6250 4850 50  0001 C CNN "JLCPCB"
	1    6250 4850
	-1   0    0    1   
$EndComp
$Comp
L Device:C C8
U 1 1 5C5383F8
P 5200 4650
F 0 "C8" V 4948 4650 50  0000 C CNN
F 1 "100nF" V 5039 4650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5238 4500 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1809301912_YAGEO-CC0603KRX7R9BB104_C14663.pdf" H 5200 4650 50  0001 C CNN
F 4 "C14663" V 5200 4650 50  0001 C CNN "JLCPCB"
	1    5200 4650
	0    1    1    0   
$EndComp
Connection ~ 5650 4650
$Comp
L power:GND #PWR08
U 1 1 5C550F8E
P 5750 5150
F 0 "#PWR08" H 5750 4900 50  0001 C CNN
F 1 "GND" H 5755 4977 50  0000 C CNN
F 2 "" H 5750 5150 50  0001 C CNN
F 3 "" H 5750 5150 50  0001 C CNN
	1    5750 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4650 5650 4650
Wire Wire Line
	5750 5150 5050 5150
Wire Wire Line
	5050 5150 5050 4650
Connection ~ 5750 5150
Wire Wire Line
	10900 5550 7950 5550
Wire Wire Line
	7950 5550 7950 4800
Wire Wire Line
	7950 4800 7550 4800
Text GLabel 6850 3750 2    60   Output ~ 0
SIG5
Text GLabel 6900 3850 2    60   Output ~ 0
SIG4
Text GLabel 6950 3950 2    60   Output ~ 0
SIG3
Text GLabel 7000 4050 2    60   Output ~ 0
SIG2
Text GLabel 7050 4150 2    60   Output ~ 0
SIG1
Text GLabel 7350 4400 0    60   Input ~ 0
SIG2
Text GLabel 7400 4500 0    60   Input ~ 0
SIG3
Text GLabel 7450 4600 0    60   Input ~ 0
SIG4
Text GLabel 7500 4700 0    60   Input ~ 0
SIG5
Text GLabel 7550 4800 0    60   Input ~ 0
SIG1
Wire Wire Line
	6850 3750 6300 3750
Connection ~ 6300 3750
Wire Wire Line
	6900 3850 6400 3850
Connection ~ 6400 3850
Wire Wire Line
	6950 3950 6500 3950
Connection ~ 6500 3950
Wire Wire Line
	7000 4050 6600 4050
Connection ~ 6600 4050
Wire Wire Line
	7050 4150 6700 4150
Connection ~ 6700 4150
Wire Wire Line
	5200 3750 4650 3750
Connection ~ 5200 3750
Wire Wire Line
	5100 3850 4600 3850
Connection ~ 5100 3850
Wire Wire Line
	5000 3950 4550 3950
Connection ~ 5000 3950
Wire Wire Line
	4900 4050 4500 4050
Connection ~ 4900 4050
Wire Wire Line
	4800 4150 4450 4150
Connection ~ 4800 4150
Text GLabel 4650 3750 0    60   Output ~ 0
HSIG5
Text GLabel 4600 3850 0    60   Output ~ 0
HSIG4
Text GLabel 4550 3950 0    60   Output ~ 0
HSIG3
Text GLabel 4500 4050 0    60   Output ~ 0
HSIG2
Text GLabel 4450 4150 0    60   Output ~ 0
HSIG1
Wire Wire Line
	3250 4400 3000 4400
Wire Wire Line
	3000 4400 3000 4100
Wire Wire Line
	2300 4400 2300 4500
Wire Wire Line
	2300 4500 2050 4500
Wire Wire Line
	2050 4500 2050 4100
Wire Wire Line
	1400 4400 1400 4600
Wire Wire Line
	1400 4600 1150 4600
Wire Wire Line
	1150 4600 1150 4100
Wire Wire Line
	3250 4400 4100 4400
Connection ~ 3250 4400
Wire Wire Line
	2300 4500 4050 4500
Connection ~ 2300 4500
Wire Wire Line
	1400 4600 4000 4600
Connection ~ 1400 4600
Wire Wire Line
	3350 5550 3850 5550
Wire Wire Line
	3850 5550 3850 4800
Wire Wire Line
	3850 4800 3900 4800
Wire Wire Line
	2150 5600 2750 5600
Wire Wire Line
	2750 5600 2750 4700
Wire Wire Line
	2750 4700 3950 4700
Connection ~ 2150 5600
Text GLabel 4100 4400 2    60   Input ~ 0
HSIG1
Text GLabel 4050 4500 2    60   Input ~ 0
HSIG2
Text GLabel 4000 4600 2    60   Input ~ 0
HSIG3
Text GLabel 3950 4700 2    60   Input ~ 0
HSIG4
Text GLabel 3900 4800 2    60   Input ~ 0
HSIG5
Wire Wire Line
	9650 4300 10900 4300
Wire Wire Line
	10900 4300 10900 5550
Wire Wire Line
	9650 4200 9950 4200
Wire Wire Line
	9650 4100 9750 4100
Wire Wire Line
	7500 4300 7850 4300
Wire Wire Line
	7650 4200 7850 4200
Wire Wire Line
	7800 4100 7850 4100
Wire Wire Line
	3100 5300 3100 5550
Wire Wire Line
	3100 5550 3350 5550
Connection ~ 3350 5550
$Comp
L Regulator_Switching:LM2596T-3.3 U1
U 1 1 62083106
P 4300 6800
F 0 "U1" H 4300 7167 50  0000 C CNN
F 1 "LM2596T-3.3" H 4300 7076 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-5_TabPin3" H 4300 7075 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 4300 6800 50  0001 C CNN
	1    4300 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 62085705
P 5600 6900
F 0 "L1" V 5419 6900 50  0000 C CNN
F 1 "33uH" V 5510 6900 50  0000 C CNN
F 2 "Inductor_SMD:L_12x12mm_H8mm" H 5600 6900 50  0001 C CNN
F 3 "~" H 5600 6900 50  0001 C CNN
	1    5600 6900
	0    1    1    0   
$EndComp
$Comp
L Diode:1N5820 D2
U 1 1 620871B8
P 5150 7150
F 0 "D2" V 5104 7230 50  0000 L CNN
F 1 "1N5819" V 5195 7230 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 5150 6975 50  0001 C CNN
F 3 "C117948" H 5150 7150 50  0001 C CNN
F 4 "1N5825 ist laut LM2596 Datenblatt vorgeschrieben" V 5150 7150 50  0001 C CNN "Notes"
F 5 "C117948" V 5150 7150 50  0001 C CNN "JLCPCB"
	1    5150 7150
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 7450 4300 7450
Wire Wire Line
	2450 7450 3500 7450
Wire Wire Line
	3800 6700 3400 6700
Wire Wire Line
	3400 6300 3400 6700
Connection ~ 3400 6700
Wire Wire Line
	3400 6700 3400 6850
Wire Wire Line
	3400 6850 3500 6850
Wire Wire Line
	3500 6850 3500 7000
Connection ~ 3400 6850
Wire Wire Line
	3500 7300 3500 7450
Connection ~ 3500 7450
Wire Wire Line
	3500 7450 3800 7450
Wire Wire Line
	3800 6900 3800 7450
Wire Wire Line
	4300 7100 4300 7450
Connection ~ 4300 7450
Wire Wire Line
	4800 6900 5150 6900
Wire Wire Line
	5150 6900 5150 7000
Wire Wire Line
	5150 6900 5450 6900
Connection ~ 5150 6900
Wire Wire Line
	5750 6900 6000 6900
Wire Wire Line
	6000 6900 6000 6950
Wire Wire Line
	6000 6900 6250 6900
Wire Wire Line
	6250 6900 6250 6850
Connection ~ 6000 6900
Wire Wire Line
	5150 7300 5150 7450
Wire Wire Line
	4300 7450 5150 7450
Wire Wire Line
	6000 7450 5150 7450
Connection ~ 5150 7450
Wire Wire Line
	6000 6900 6000 6500
Wire Wire Line
	6000 6500 5150 6500
Wire Wire Line
	5150 6500 5150 6700
Wire Wire Line
	5150 6700 4800 6700
$Comp
L Device:CP C1
U 1 1 621C3EB6
P 3500 7150
F 0 "C1" H 3618 7196 50  0000 L CNN
F 1 "280uF" H 3618 7105 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_10x10" H 3538 7000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1809301518_Lelon-VZH221M1HTR-1010_C134819.pdf" H 3500 7150 50  0001 C CNN
F 4 "C134819" H 3500 7150 50  0001 C CNN "JLCPCB"
F 5 "Sollte eig 680uF aber sehr teuer und groß bei 24V -> 220uf" H 3500 7150 50  0001 C CNN "Notes"
	1    3500 7150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 621C4AC2
P 6000 7100
F 0 "C2" H 6118 7146 50  0000 L CNN
F 1 "220uF" H 6118 7055 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T" H 6038 6950 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/lcsc/1811091924_AVX-TLJB227M006R0500_C30242.pdf" H 6000 7100 50  0001 C CNN
F 4 "C30242" H 6000 7100 50  0001 C CNN "JLCPCB"
	1    6000 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 7250 6000 7450
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 62332F5D
P 2050 1350
F 0 "J5" V 2014 1630 50  0000 L CNN
F 1 "Conn_01x06" V 1923 1630 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-6_P5.08mm" H 2050 1350 50  0001 C CNN
F 3 "~" H 2050 1350 50  0001 C CNN
	1    2050 1350
	0    1    -1   0   
$EndComp
Connection ~ 1850 3100
Wire Wire Line
	1850 3100 3000 3100
Wire Wire Line
	1100 3100 1850 3100
Wire Wire Line
	1850 1550 1850 3100
Wire Wire Line
	1100 3200 1750 3200
Wire Wire Line
	1750 1550 1750 3200
Connection ~ 1750 3200
Wire Wire Line
	1750 3200 3050 3200
Connection ~ 1950 3000
Wire Wire Line
	1950 3000 2050 3000
Wire Wire Line
	1950 1550 1950 3000
Wire Wire Line
	1150 2900 2050 2900
Wire Wire Line
	2050 1550 2050 2900
Connection ~ 2050 2900
Wire Wire Line
	2050 2900 3050 2900
Wire Wire Line
	2150 1550 2150 3400
Connection ~ 2150 3400
Wire Wire Line
	2250 1550 2250 3300
Connection ~ 2250 3300
Wire Wire Line
	2250 3300 2850 3300
Wire Wire Line
	2150 3400 3050 3400
$Comp
L Device:C C10
U 1 1 624F3931
P 6650 4850
F 0 "C10" H 6765 4896 50  0000 L CNN
F 1 "100nF" H 6765 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6688 4700 50  0001 C CNN
F 3 "~" H 6650 4850 50  0001 C CNN
F 4 "C14663" H 6650 4850 50  0001 C CNN "JLCPCB"
	1    6650 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5000 6250 5150
Connection ~ 6250 5150
Wire Wire Line
	6250 5150 5750 5150
Wire Wire Line
	6650 5150 6650 5000
Wire Wire Line
	6250 5150 6650 5150
Wire Wire Line
	6250 4700 6250 4650
Wire Wire Line
	5850 4650 6150 4650
Connection ~ 6150 4650
Wire Wire Line
	6150 4650 6250 4650
Wire Wire Line
	6150 4350 6650 4350
Wire Wire Line
	6650 4350 6650 4700
Connection ~ 6150 4350
Text Notes 5100 850  0    60   ~ 0
Tauschen in C709357 KH-TYPE-C-16P https://datasheet.lcsc.com/lcsc/2009111434_Shenzhen-Kinghelm-Elec-KH-TYPE-C-16P_C709357.pdf
$Comp
L Connector:USB_C_Plug_USB2.0 P?
U 1 1 6215D6AF
P 6750 1350
F 0 "P?" H 6857 2217 50  0000 C CNN
F 1 "USB_C_Plug_USB2.0" H 6857 2126 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_Amphenol_12401610E4-2A" H 6900 1350 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 6900 1350 50  0001 C CNN
	1    6750 1350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
