# Chip-n-Moto
Modified Chip'n'Bot for Micro DC Motors
**This is still a work in progress and I will update this as I can**

# What You Need:
Arduino Uno - https://www.amazon.com/dp/B01N298F54

HC-SR04 Sensor - http://www.dxsoul.com/product/hc-sr04-ultrasonic-sensor-distance-measuring-module-901133696

9v battery

9v battery connector cap with barrel connector - http://www.dxsoul.com/product/dd15-dc-9v-battery-button-power-plug-for-arduino-2560-2560r3-uno-uno-r3-328-5-pcs-901273059

2 rubber bands

2 Adafruit DC Motor in Micro Servo Body - https://www.adafruit.com/product/2941

1 SG90 Micro Servo - http://www.dx.com/p/towerpro-sg90-9g-mini-servo-with-accessories-12859

L298P Ardumoto - http://www.dx.com/p/l298p-avr-lpc-stm32-uno-mega-2a-motor-driver-shield-436284

# Assembly
Print off Wheels, Sensor Support, and Chassis, if you have trouble with the wheel hubs please print off 2x Wheel Hubs

If you have to use the hubs please install them into the wheels with adhesive to prevent slipping.

Install the rear wheel onto the chassis
install the SG90 in a vertical position in the center using 2 provided screws.
install the DC motors using zip-ties via the included slots and secure the motors.
install the wheels using a single screw into the center of each wheel/wheel hub
install the HC-SR04 into the sensor support and affix with screws OR super glue in the coner holes.
let the dry and install the servo arm onto the bottom of the sensor support.
affix the sensor support and servo arm onto the servo using a single screw in the middle of the servo arm to the gear.
install the arduino uno board onto the chassis using the risers of your choice
prepare the L298P by attaching headers to pins 3, 10, 11, 12, Vin.  mount onto the Arduino Uno Board with the headers you installed.

If you are patient you can just add headers to the needed pins and retain pin-pass-through for other items in the build such as power and ground locations.

Attach:
Pin 5 //SG90 PWM
Pin 7 //HC-SR04 Echo
Pin 8 //HC-SR04 Trigger through the riser board
Pin 3 to riser board L298P PWMA
Pin 11 to riser board L298P PWMB
Pin 12 to riser board L298P DirA
Pin 13 to riser board L298P DirB
Vin to riser board L298P Vin
And PWR+GND for the SG90

Please feel free to send any suggestions to mr.stephen.stipe@gmail.com
