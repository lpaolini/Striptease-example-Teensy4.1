#include "Striptease.h"
#include "remote/SonyRemote_RMD420.h"
#include "remote/SerialRemote.h"

#include "MyStage.h"

AudioSensor *audioSensor = new AudioSensor();
State *state = new State();
Stage *stage = new MyStage(audioSensor, state);
Controller *controller = new Controller(stage, audioSensor, state);
IRRemote *remote = new SonyRemote_RMD420(controller);
SerialRemote *serialRemote = new SerialRemote(controller);

void init() {
    Serial.begin(115200);
    randomSeed(analogRead(0));
}

void setup() {
    init();
    audioSensor->setup();
    state->setup();
    controller->setup();
    controller->setBrightness(10);
    controller->setAudioEnabled(true);
    // controller->setStandbyTimer(5000);
    // controller->setStatsTimer(2000);
    remote->setup();
    serialRemote->setup();
}

void loop() {
    audioSensor->loop();
    state->loop();
    controller->loop();
    remote->loop();
    serialRemote->loop();
}
