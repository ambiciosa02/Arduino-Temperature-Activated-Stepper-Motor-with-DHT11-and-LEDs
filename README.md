# Arduino-Temperature-Activated-Stepper-Motor-with-DHT11-and-LEDs
This sketch is a Temperature-Controlled Stepper Motor Project using Arduino, DHT11, and 28BYJ-48.

🔍 How it works
1️⃣ Hardware used

Arduino (Uno, Nano, etc.)

28BYJ-48 stepper motor with ULN2003 driver

DHT11 temperature sensor

4 LEDs for visual indicator

2️⃣ Program flow

Setup:

Initialize DHT11 sensor.

Configure Stepper motor with 2048 steps/revolution and speed of 8 RPM.

Set up 4 LEDs and turn them on permanently.

Loop:

Read temperature from DHT11.

If temperature > 24°C, rotate the stepper motor 10 steps.

Otherwise, the motor remains stationary.

Print temperature values to the Serial Monitor for monitoring.

3️⃣ Notes

myStepper.step(10) can be adjusted for faster or slower rotation.

The 4 LEDs act as a constant visual indicator, not directly related to motor control.

DHT11 readings may occasionally fail, so isnan() check is necessary.
