# Striptease-example-teensy4.1

This is an example to show how to use the Striptease library, and it's also the actual setup deployed in my living room. :-)

## Physical layout

In this setup four physical strips are used:
- left: 192 LEDs, 144 LED/m, connected to channel 1
- right: 192 LEDs, 144 LED/m, connected to channel 2
- top: 169 LEDs, 60 LED/m, connected to channel 6
- xmasTree: 240 LEDs, 60 LED/m, connected to channel 3

Strips "left" and "right" are placed side by side below a piece of furniture about 270cm wide, at floor level. They are wired from the center, so they are arranged in opposite directions.

<--------------- left | right --------------->

Note: I could have certainly used a single strip wired at one side, but it would have caused a slight reduction of the framerate, which depends on the lenght of the longest strip.

Strip "top" is hidden at about 50cm from the ceiling, pointing upwards (only reflected light is visible). It is wired from the left.

top -------------------------------------->

Array "xmasTree"... well, it wrapped around my Christmas tree, when it's there.

## main.cpp

In this file the various components are "wired" together and initial settings (like audio input to be used) are specified.

## MyStage.h

In this file constants about physical strips (LED count, pin and density) and maximum allowed power are declared.

## MyStage.cpp

In this file strips and multiplexed effects are defined.

### Strips definitions

Physical strips are added to the stage using the `addStrip()` method.

Optional virtual strips can be created as required by composing `JoinedStrip`, `ReversedStrip` and `SubStrip`.

In this case they are defined as follows:
- front: a single left-to-right strip obtained by joining "left" and "right", taking the gap in the middle into account.
- topLeft/topRight: two portions of the "top" strip, from the center outwards.
- subLeft/subRight: two portions of the "left" and "right" strips.

All strips, physical or virtual can be used at the same time.

### Effects definitions

Effects are added to the stage using the `addFx()` method. Up to 20 effects can be multiplexed for simultaneous display on any strip (physical or virtual).

Standard effects included in the library can be overlayed one on top of the other one on any strip, to create much more sophisticated and richer visual effects. In this setup 38 multiplexed effects are defined.

Enjoy!