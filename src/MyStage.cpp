#include "MyStage.h"

MyStage::MyStage(AudioSensor *audioSensor, State *state) {

    // physical strips

    Strip *xmasTree = addStrip<STRIP_XMASTREE_COUNT, STRIP_XMASTREE_PIN, STRIP_XMASTREE_DENSITY>();
    Strip *frontLeft = addStrip<STRIP_LEFT_COUNT, STRIP_LEFT_PIN, STRIP_LEFT_DENSITY>();
    Strip *frontRight = addStrip<STRIP_RIGHT_COUNT, STRIP_RIGHT_PIN, STRIP_RIGHT_DENSITY>();
    Strip *top = addStrip<STRIP_TOP_COUNT, STRIP_TOP_PIN, STRIP_TOP_DENSITY>();

    // virtual strips

    Strip *front = new JoinedStrip(new ReversedStrip(frontLeft), frontRight, 2);
    Strip *subFrontLeft = new SubStrip(frontLeft, 15, 79);
    Strip *subFrontRight = new SubStrip(frontRight, 15, 79);
    Strip *topLeft = new ReversedStrip(new SubStrip(top, 0, 83));
    Strip *topRight = new SubStrip(top, 85, 168);

    Fx *frontBlackout = new Blackout(front);
    Fx *topBlackout = new Blackout(top);
    Fx *xmasBlackout = new Blackout(xmasTree);

    CRGB blueBackgroundColor = CHSV(160, 255, 40);
    CRGB redBackgroundColor = CHSV(0, 255, 40);
    
    FastLED.setMaxPowerInMilliWatts(1000 * MAX_WATTS);
    FastLED.setCorrection(TypicalLEDStrip);

    // Fx #1

    addFx(
        new Sunset(top, state),
        new Sunset(front, state),
        new Sunset(xmasTree, state)
    );

    // Fx #2

    addFx(
        new Volcane(frontLeft, audioSensor->left, state),
        new Volcane(frontRight, audioSensor->right, state),
        topBlackout,
        new Volcane(xmasTree, audioSensor->mono, state)
    );

    // Fx #3

    addFx(
        new Jelly(frontLeft, audioSensor->left, state),
        new Jelly(frontRight, audioSensor->right, state),
        new Jelly(top, audioSensor->mono, state),
        new Jelly(xmasTree, audioSensor->mono, state)
    );

    // Fx #4

    addFx(
        new Chaser(frontLeft, audioSensor->left, state),
        new Chaser(frontRight, audioSensor->right, state),
        new Chaser(top, audioSensor->mono, state),
        new Chaser(xmasTree, audioSensor->mono, state)
    );

    // Fx #5

    addFx(
        new Glitter(front, state),
        new Glitter(top, state),
        new Glitter(xmasTree, state)
    );

    // Fx #6

    addFx(
        new VU1(frontLeft, audioSensor->left, state),
        new VU1(frontRight, audioSensor->right, state),
        new Blackout(top),
        new VU1(topLeft, audioSensor->left, state),
        new VU1(topRight, audioSensor->right, state),
        new Jelly(xmasTree, audioSensor->mono, state)
    );

    // Fx #7

    addFx(
        new Elastic(front, audioSensor->mono, state),
        new Elastic(top, audioSensor->mono, state),
        new Elastic(xmasTree, audioSensor->mono, state)
    );

    // Fx #8

    addFx(
        new Sinelon(front, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 5, 1000, CRGB::LimeGreen),
        new VU2(frontRight->overlay(), audioSensor->right, 5, 1000, CRGB::LimeGreen),
        new Sinelon(top, state),
        new Sinelon(xmasTree, state)
    );

    // Fx #9

    addFx(
        new SineMeter(frontLeft, audioSensor->left, state),
        new SineMeter(frontRight, audioSensor->right, state),
        topBlackout,
        new SineMeter(xmasTree, audioSensor->mono, state)
    );

    // Fx #10

    addFx(
        new Matrix(front, audioSensor->mono, state),
        new PeakMeter(subFrontLeft, audioSensor->left),
        new PeakMeter(subFrontRight, audioSensor->right),
        topBlackout,
        new Ripple(xmasTree, audioSensor->mono, state, redBackgroundColor)
    );

    // Fx #11

    addFx(
        new Ripple(front, audioSensor->mono, state, blueBackgroundColor),
        new VU2(frontLeft->overlay(), audioSensor->left, 1, 1000, CRGB::Blue),
        new VU2(frontRight->overlay(), audioSensor->right, 1, 1000, CRGB::Blue),
        new Ripple(top, audioSensor->mono, state, blueBackgroundColor),
        new Ripple(xmasTree, audioSensor->mono, state, blueBackgroundColor)
    );

    // Fx #12

    addFx(
        new Strobe(frontLeft, audioSensor->left, state),
        new Strobe(frontRight, audioSensor->right, state),
        new Strobe(top, audioSensor->mono, state),
        new Strobe(xmasTree, audioSensor->mono, state)
    );

    // Fx #13

    addFx(
        new Ants(frontLeft, audioSensor->left, state),
        new Ants(frontRight, audioSensor->right, state),
        topBlackout,
        new Ants(xmasTree, audioSensor->mono, state)
    );

    // Fx #14

    addFx(
        new DeepSpace(front, audioSensor->mono, state, CRGB::DarkRed, CRGB::HotPink),
        new Jelly(frontLeft->overlay(), audioSensor->left, state),
        new Jelly(frontRight->overlay(), audioSensor->right, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 1, 200, CRGB::LimeGreen),
        new VU2(frontRight->overlay(), audioSensor->right, 1, 200, CRGB::LimeGreen),
        new Ripple(top, audioSensor->mono, state, blueBackgroundColor),
        new Photons(xmasTree, audioSensor->mono, state)
    );

    // Fx #15

    addFx(
        new Fire(frontLeft, audioSensor->left),
        new Fire(frontRight, audioSensor->right),
        topBlackout,
        new Fire(xmasTree, audioSensor->mono)
    );

    // Fx #16

    addFx(
        new Beat(frontLeft, audioSensor->left),
        new Beat(frontRight, audioSensor->right),
        topBlackout,
        new Beat(xmasTree, audioSensor->mono)
    );

    // Fx #17

    addFx(
        new Blackout(front),
        new Blur(frontLeft->overlay()),
        new Blur(frontRight->overlay()),
        new Ants(frontLeft->overlay(), audioSensor->left, state),
        new Ants(frontRight->overlay(), audioSensor->right, state),
        topBlackout,
        new Blur(xmasTree)
    );

    // Fx #18

    addFx(
        new Blackout(front),
        new Juggle(frontLeft->overlay(), state),
        new Juggle(frontRight->overlay(), state),
        new Vertigo(frontLeft->overlay(), audioSensor->left, state),
        new Vertigo(frontRight->overlay(), audioSensor->right, state),
        new Juggle(top, state),
        new Juggle(xmasTree, state)
    );

    // Fx #19

    addFx(
        new Matrix(front, audioSensor->mono, state),
        new Ants(front->overlay(), audioSensor->mono, state),
        new Matrix(top, audioSensor->mono, state),
        new Matrix(xmasTree, audioSensor->mono, state)
    );

    // Fx #20

    addFx(
        new Drops(frontLeft, audioSensor->left, state),
        new Drops(frontRight, audioSensor->right, state),
        new Spiral(front->overlay(), state, 10, 2, .3),
        new Drops(top, audioSensor->mono, state),
        new Drops(xmasTree, audioSensor->mono, state)
    );

    // Fx #21

    addFx(
        new Blackout(frontLeft),
        new Blackout(frontRight),
        new Scroller(frontLeft->overlay(), audioSensor->left, state),
        new Scroller(frontRight->overlay(), audioSensor->right, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 1, 1000, CRGB::White),
        new VU2(frontRight->overlay(), audioSensor->right, 1, 1000, CRGB::White),
        new Ripple(xmasTree, audioSensor->mono, state),
        topBlackout
    );

    // Fx #22

    addFx(
        new Fireworks(frontLeft, audioSensor->left, state),
        new Fireworks(frontRight, audioSensor->right, state),
        new Fireworks(top, audioSensor->mono, state),
        new Fireworks(xmasTree, audioSensor->mono, state)
    );

    // Fx #23

    addFx(
        new Vertigo(frontLeft, audioSensor->left, state),
        new Vertigo(frontRight, audioSensor->right, state),
        topBlackout,
        new Ripple(xmasTree, audioSensor->mono, state)
    );

    // Fx #24

    addFx(
        frontBlackout,
        new DeepSpace(front->overlay(), audioSensor->mono, state, 0x800000, 0x000020),
        topBlackout,
        xmasBlackout
    );

    // Fx #25

    addFx(
        new Matrix(front, audioSensor->mono, state),
        new Fireworks(front->overlay(), audioSensor->mono, state),
        new Drops(frontLeft->overlay(), audioSensor->left, state),
        new Drops(frontRight->overlay(), audioSensor->right, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 1, 500),
        new VU2(frontRight->overlay(), audioSensor->right, 1, 500),
        topBlackout,
        new Drops(xmasTree, audioSensor->mono, state)
    );

    // Fx #26

    addFx(
        new Elastic(front, audioSensor->mono, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 1, 1000),
        new VU2(frontRight->overlay(), audioSensor->right, 1, 1000),
        topBlackout,
        new Sparks(xmasTree, audioSensor->mono, state)
    );

    // Fx #27

    addFx(
        new Ripple(front, audioSensor->mono, state, blueBackgroundColor),
        new Ants(frontLeft->overlay(), audioSensor->left, state),
        new Ants(frontRight->overlay(), audioSensor->right, state),
        topBlackout,
        new Ants(xmasTree, audioSensor->mono, state)
    );

    // Fx #28

    addFx(
        new DeepSpace(front, audioSensor->mono, state, 0x000040, 0x101010),
        new VU1(frontLeft->overlay(), audioSensor->left, state),
        new VU1(frontRight->overlay(), audioSensor->right, state),
        topBlackout,
        new Drops(xmasTree, audioSensor->mono, state)
    );

    // Fx #29

    addFx(
        new Ripple(top, audioSensor->mono, state, blueBackgroundColor),
        new Spectrum(topLeft->overlay(), audioSensor->left),
        new Spectrum(topRight->overlay(), audioSensor->right),
        new Ripple(front, audioSensor->mono, state, blueBackgroundColor),
        new Spectrum(frontLeft->overlay(), audioSensor->left),
        new Spectrum(frontRight->overlay(), audioSensor->right),
        new Ripple(xmasTree, audioSensor->mono, state, blueBackgroundColor)
    );

    // Fx #30
    
    addFx(
        new Sparks(frontLeft, audioSensor->left, state),
        new Sparks(frontRight, audioSensor->right, state),
        new Sparks(top, audioSensor->mono, state),
        new Background(xmasTree, blueBackgroundColor),
        new Sparks(xmasTree->overlay(), audioSensor->mono, state, CRGB::White, CRGB::Red)
    );

    // Fx #31
    
    addFx(
        new Orbit(frontLeft, state),
        new Orbit(frontRight, state, 120),
        topBlackout,
        new Orbit(xmasTree, state)
    );

    // Fx #32
    
    addFx(
        new RippleReflections(front, audioSensor->mono, state),
        topBlackout,
        new Drops(xmasTree, audioSensor->mono, state)
    );

    // Fx #33
    
    addFx(
        new RainbowMelt(front, audioSensor->mono, state),
        new VU2(frontLeft->overlay(), audioSensor->left, 5, 1000, CRGB::White),
        new VU2(frontRight->overlay(), audioSensor->right, 5, 1000, CRGB::White),
        new RainbowMelt(top, audioSensor->mono, state),
        new RainbowMelt(xmasTree, audioSensor->mono, state)
    );

    // Fx #34
    
    addFx(
        new FastPulse(front, audioSensor->mono, state),
        new VU1(frontLeft->overlay(), audioSensor->left, state),
        new VU1(frontRight->overlay(), audioSensor->right, state),
        new FastPulse(top, audioSensor->mono, state),
        new FastPulse(xmasTree, audioSensor->mono, state)
    );

    // Fx #35
    
    addFx(
        new MarchingRainbow(front, audioSensor->mono, state),
        new MarchingRainbow(top, audioSensor->mono, state),
        new MarchingRainbow(xmasTree, audioSensor->mono, state)
    );

    // Fx #36
    
    addFx(
        new ColorTwinkles(front, audioSensor->mono, state),
        new Jelly(frontLeft->overlay(), audioSensor->left, state),
        new Jelly(frontRight->overlay(), audioSensor->right, state),
        topBlackout,
        new ColorTwinkles(xmasTree, audioSensor->mono, state)
    );

    // Fx #37
    
    addFx(
        new SubtleWave(frontLeft, audioSensor->left, state),
        new SubtleWave(frontRight, audioSensor->right, state),
        new Spiral(front->overlay(), state, 10, 2, .3),
        topBlackout,
        new Drops(xmasTree, audioSensor->mono, state)
    );
    
    // Fx #38

    addFx(
        frontBlackout,
        new ColorTwinkles(front->overlay(.25), audioSensor->mono, state),
        new Traffic(front->overlay(), audioSensor->mono, state),
        new MarchingRainbow(top, audioSensor->mono, state),
        xmasBlackout,
        new ColorTwinkles(xmasTree->overlay(.25), audioSensor->mono, state),
        new Drops(xmasTree->overlay(), audioSensor->mono, state),
        new Sparks(xmasTree->overlay(), audioSensor->mono, state)
    );

    setCycleSpeedFx(
        new CycleSpeed(frontLeft, state),
        new CycleSpeed(frontRight, state)
    );

    setSpeedMeterFx(
        new SpeedMeter(frontLeft, state),
        new SpeedMeter(frontRight, state)
    );

    setMicGainMeterFx(
        new MicGainMeter(frontLeft, audioSensor->left, audioSensor),
        new MicGainMeter(frontRight, audioSensor->right, audioSensor)
    );

    setInputLevelMeterFx(
        new InputLevelMeter(frontLeft, audioSensor->left, audioSensor),
        new InputLevelMeter(frontRight, audioSensor->right, audioSensor)
    );
}
