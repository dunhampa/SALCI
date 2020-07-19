Goal Getting Arduino to Appear as Midi Controller:


Following:

https://create.arduino.cc/projecthub/Isaac_LL/midi-and-arduino-740fe7

which lead me to:

https://www.arduino.cc/en/Hacking/DFUProgramming8U2

Which led me to:

```
https://www.macports.org/install.php#pkg
```

Downloaded and installed macports

Then from terminal


First step:

```
sudo port install dfu-programmer
```


```
git clone https://github.com/kuwatay/mocolufa.git
```

changed into that directory

cd mocolufa/

pluged in Arduino made sure I was communicating, shorted out pins, no longer so

erased memory 
```
sudo dfu-programmer atmega16u2 erase
```

```
sudo dfu-programmer atmega16u2 flash ./HEX/dualMoco.hex
```

```
sudo dfu-programmer atmega16u2 reset
```

Jumping pings on original tutorial and loaded code:

```
#include <MIDI.h> // Include MIDI Library
#define C3 48  // Define some notes
//MIDI_CREATE_DEFAULT_INSTANCE(); // Create an instance of the midi library
void setup() {
   MIDI.begin(MIDI_CHANNEL_OMNI); // Begin MIDI and listen to all channels
}
void loop() {
 MIDI.sendNoteOn(C3, 120, 1); // Send note C3 on with a velocity of 120 and on channel 1
 delay(500);
 MIDI.sendNoteOff(C3, 0, 1);
 delay(500);
}
```

I put the MIDI.h file in there as well

This works one gotchas: needed to shut Arduino interface because it was seemingly leaving port open.


