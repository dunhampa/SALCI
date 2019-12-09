# SALCI
Sensor Array Light Controlled Instrument

This code can be compiled and uploaded using the Arduino IDE. 

Using Arduino hardware (Mega 2560) a music network can be created
with music notes delivered over MIDI protocol.

![]( https://github.com/dunhampa/SALCI/blob/master/content/SALCIThumb.png)

# Parts List


<img src="https://github.com/dunhampa/SALCI/blob/master/content/arduino_mega2560.jpg" width="300">


# Debug Setup

## Connecting with 2 serial cables to see what is going on.  

One serial connection is via the USB port that creates a serial connection and powers the Arduino Mega. The other is created by wiring directly to the TX1 and RX 1 (pins 18 and 19 on an Mega) using a TFDI converter ($8 USB from microcenter or other).

On a Mac it's nice to open up a terminal per connection. 
When device is powered up and connected you can find the reference to these connections by typing

```
ls /dev/cu.usb*
```

Example return:

```
/dev/cu.usbmodem14131		/dev/cu.usbserial-A1081D55
```

As a matter of convention the usbmodem is going to be the onboard serial conversion. 

We can open first connection:

```
sudo screen /dev/cu.usbmodem14131 9600 –L
```

And second connection:

```
sudo screen /dev/cu.usbserial-A1081D55 9600 –L
```
