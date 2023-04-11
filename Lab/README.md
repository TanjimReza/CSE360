# Home Security System

This is a simple home security system built with Arduino. The system uses a magnetic reed switch, an LDR sensor, and a PIR sensor to detect whether a door or window has been opened, and whether there is any movement in the room. The system will then turn on an LED and send a notification via Bluetooth to alert the user.

## Components Used

- Arduino Uno
- Magnetic Reed Switch
- LDR Sensor
- PIR Sensor
- LED
- Bluetooth Module

## Wiring Diagram

Please refer to the following wiring diagram to connect the components:

![Wiring Diagram](/images/wiring-diagram.png) Added in Project Report

## Code Explanation

The Arduino code for this project can be found in the [home-security-system.ino](/Arduino_Code_Optimized.ino) file. Here is a brief explanation of the code:

- `LED`, `MAGNETIC_REED`, `LDR`, and `PIR` are the pin numbers for the LED, magnetic reed switch, LDR sensor, and PIR sensor, respectively.
- `LDR_STATE`, `PIR_STATE`, and `REED_STATE` are variables used to store the state of the LDR sensor, PIR sensor, and magnetic reed switch, respectively.
- In the `setup()` function, the serial communication is initialized, and the pins for the sensors and LED are configured as inputs and outputs.
- In the `loop()` function, the state of the LDR, PIR, and magnetic reed switch are read.
- If the magnetic reed switch is on, and the LDR and PIR sensors are also on, the LED is turned on, and a notification is sent via Bluetooth.
- If the magnetic reed switch is off, or either the LDR or PIR sensor is off, the LED is turned off.

