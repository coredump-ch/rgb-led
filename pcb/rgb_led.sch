EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:rgb_led-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "18 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L POT RV2
U 1 1 5367E976
P 5050 1850
F 0 "RV2" H 5050 1750 50  0000 C CNN
F 1 "POT" H 5050 1850 50  0000 C CNN
F 2 "~" H 5050 1850 60  0000 C CNN
F 3 "~" H 5050 1850 60  0000 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
$Comp
L POT RV3
U 1 1 5367E98F
P 5050 2150
F 0 "RV3" H 5050 2050 50  0000 C CNN
F 1 "POT" H 5050 2150 50  0000 C CNN
F 2 "~" H 5050 2150 60  0000 C CNN
F 3 "~" H 5050 2150 60  0000 C CNN
	1    5050 2150
	1    0    0    -1  
$EndComp
$Comp
L POT RV1
U 1 1 5367E99E
P 5050 1550
F 0 "RV1" H 5050 1450 50  0000 C CNN
F 1 "POT" H 5050 1550 50  0000 C CNN
F 2 "~" H 5050 1550 60  0000 C CNN
F 3 "~" H 5050 1550 60  0000 C CNN
	1    5050 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5367ED4E
P 3700 2500
F 0 "#PWR01" H 3700 2500 30  0001 C CNN
F 1 "GND" H 3700 2430 30  0001 C CNN
F 2 "" H 3700 2500 60  0000 C CNN
F 3 "" H 3700 2500 60  0000 C CNN
	1    3700 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1400 4800 1400
Wire Wire Line
	4800 1400 4800 1550
Wire Wire Line
	5050 1700 4800 1700
Wire Wire Line
	4800 1700 4800 1850
Wire Wire Line
	5050 2000 4800 2000
Wire Wire Line
	4800 2000 4800 2150
$Comp
L VDD #PWR02
U 1 1 5367EDA4
P 3700 1050
F 0 "#PWR02" H 3700 1150 30  0001 C CNN
F 1 "VDD" H 3700 1160 30  0000 C CNN
F 2 "" H 3700 1050 60  0000 C CNN
F 3 "" H 3700 1050 60  0000 C CNN
	1    3700 1050
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 53DFF409
P 3350 1450
F 0 "P1" V 3300 1450 40  0000 C CNN
F 1 "CONN_2" V 3400 1450 40  0000 C CNN
F 2 "~" H 3350 1450 60  0000 C CNN
F 3 "~" H 3350 1450 60  0000 C CNN
	1    3350 1450
	-1   0    0    1   
$EndComp
$Comp
L CONN_4 P2
U 1 1 53DFF418
P 6200 1600
F 0 "P2" V 6150 1600 50  0000 C CNN
F 1 "CONN_4" V 6250 1600 50  0000 C CNN
F 2 "~" H 6200 1600 60  0000 C CNN
F 3 "~" H 6200 1600 60  0000 C CNN
	1    6200 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1550 3700 2500
Wire Wire Line
	4800 2150 3700 2150
Connection ~ 3700 2150
Wire Wire Line
	4800 1850 3700 1850
Connection ~ 3700 1850
Wire Wire Line
	4800 1550 3700 1550
Wire Wire Line
	3700 1350 3700 1050
Wire Wire Line
	5850 1450 5650 1450
Wire Wire Line
	5650 1450 5650 1100
Wire Wire Line
	5650 1100 3700 1100
Connection ~ 3700 1100
Wire Wire Line
	5300 1550 5850 1550
Wire Wire Line
	5850 1650 5550 1650
Wire Wire Line
	5550 1650 5550 1850
Wire Wire Line
	5550 1850 5300 1850
Wire Wire Line
	5850 1750 5700 1750
Wire Wire Line
	5700 1750 5700 2150
Wire Wire Line
	5700 2150 5300 2150
$EndSCHEMATC
