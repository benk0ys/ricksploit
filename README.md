RickRoll Digispark Demo 🎵

A lightweight educational BadUSB demonstration for the ATtiny85 Digispark.
This project showcases how a USB HID device can emulate keyboard input to automatically open a harmless prank page (Rick Roll) on a target machine.

Designed for cybersecurity awareness labs, HID research, and USB attack surface demonstrations in controlled environments.

<p align="center"> <img width="700" src="https://media.tenor.com/x8v1oNUOmg4AAAAd/rickroll-roll.gif"> </p>
Features
Plug-and-play Digispark payload
Emulates a trusted USB keyboard (HID)
Opens the default browser automatically
Launches the classic Rick Roll URL
No persistence
No privilege escalation
No data collection or exfiltration
Hardware Requirements
Digispark ATtiny85
USB port
Target machine running:
Linux
Windows
Most desktop environments supporting HID keyboards
Software Requirements
Arduino IDE or arduino-cli
Digistump AVR board package
micronucleus bootloader utility
Project Structure
.
├── payload.ino
└── README.md
Payload Source Code

Create payload.ino:

#define LAYOUT_FRENCH
#include "DigiKeyboard.h"

void setup() {
  // Wait for device initialization
  DigiKeyboard.delay(5000);

  // Open Run dialog (Windows)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Open Rick Roll
  DigiKeyboard.println("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
Compilation

Using arduino-cli:

arduino-cli compile \
  --fqbn digistump:avr:digispark-tiny \
  --output-dir . \
  payload.ino
Flashing the Firmware

Flash the compiled payload onto the Digispark:

micronucleus --run ./payload.ino.hex

When prompted:

Plug in the Digispark
Wait for upload completion
Unplug and test
Technical Breakdown
Why It Works

Modern operating systems inherently trust USB Human Interface Devices (HID), such as keyboards and mice.

The Digispark emulates a legitimate keyboard and injects keystrokes automatically at high speed.

Because the payload only opens a public URL:

no elevated privileges are required,
no system files are modified,
and no sensitive data is accessed.
Educational Purpose

This project is intended for:

cybersecurity awareness training,
USB HID demonstrations,
hardware hacking workshops,
BadUSB research labs,
defensive security education.

Use only on systems you own or are explicitly authorized to test.

Defensive Recommendations
USB Device Control
Linux — USBGuard
sudo apt install usbguard
sudo systemctl enable --now usbguard
Restrict Unknown HID Devices

Create custom udev rules to block unauthorized VID/PID devices.

Example:

ATTRS{idVendor}=="16d0", ATTRS{idProduct}=="0753", ATTR{authorized}="0"

Reload rules:

sudo udevadm control --reload-rules
sudo udevadm trigger
Disclaimer

This repository is provided strictly for educational and defensive cybersecurity purposes.

The author assumes no responsibility for misuse or unauthorized deployment.
