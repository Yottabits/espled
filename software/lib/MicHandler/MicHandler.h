#ifndef MICHANDLER_H
#define MICHANDLER_H

#include <Arduino.h>
#include <arduinoFFT.h>
#include <TypeDefinitions.h>
#include <PinDefinitions.h>


#define samplingFrequency 1000
#define samplingDelay 1000/samplingFrequency
#define ringBufferSize 128

extern void debugFkt(String, LogLevel);

class MicHandler{
  public:
    MicHandler(varSilo *silo);

    void handleMic();
    void calculateFFT();
    void getMaxAmplitude();
    void getPeakFrequency();
    void averageAmplitude();
    double getAverageAmplitude();

    void printVector();

    float audioRingBuffer[ringBufferSize];
  private:
    void recordAudioSample();
    varSilo* silo;

    arduinoFFT FFT = arduinoFFT();
    double fourierBufferReal[ringBufferSize];
    double fourierBufferImag[ringBufferSize];

    unsigned int audioTimer = 0;
    unsigned int ringBufferCounter = 0;

};

#endif
