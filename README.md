# SALCI
Sensor Array Light Controlled Instrument

This code can be compiled and uploaded using the Arduino IDE. 

Using Arduino hardware (Mega 2560) a music network can be created
with music notes delivered over MIDI protocol.




<a href="#">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/SALCIThumb.png">
</a>


# Parts List

### One Or More Arduinos
This has been tested with Arduino Mega2560 but will work with other Arduinos with some modifications required.  Sensor count will be limited by the board's available Analog inputs

<a href="#">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/arduino_mega2560.jpg" width="600">
</a>


### A Photocell For Each Sensor 
Max number limited by Analog Inputs on board

<a href="https://www.sparkfun.com/products/11508">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/Mini_Photocell.jpg" width="300">
</a>

### 10K Resistor For Each Sensor 
Note that the link is for a package of resistors.

<a href="https://www.sparkfun.com/products/9088">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/10k_resistor.jpg" width="300">
</a>

# Circuit

This image (generated with Fritzing) shows the basic circuits used on the hardware. Each sensor is using a 10k voltage divider since the dark sensor resistance is at 10k. If the photocell resistor (sensor) has a different resistance the resistor should match the photocell for the most dynamic range. In the layout below only some of the analog inputs circuits are shown. The voltage divider circuit should be/can use repeated for each analog input that you want to you.

<a href="#">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/SALCI_Layout.png">
</a>




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

# See Dual Serial Monitor Scripts

https://geekinc.ca/using-screen-as-a-serial-terminal-on-mac-os-x/

Above seemed ot have lags, so adjusted:

```
ls /dev/tty.*
```

Then use list to 

```
screen /dev/tty.usbmodem142301 115200
 ```
 
 the tty over cu seemed to return faster.
 But had to force close "screen" in Activity Monitor when I had some interference.
 
 See picture from today that shows the connection

<a href="#">
<img src="https://github.com/dunhampa/SALCI/blob/master/content/ConverterConnections.jpg">
</a>