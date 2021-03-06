#include <MicHandler.h>

extern "C" {
#include "user_interface.h"
}


MicHandler::MicHandler(varSilo* silo){
  this->silo = silo;
}

void MicHandler::handleMic(){
 unsigned int currentCycleCount = ESP.getCycleCount();
  if(currentCycleCount - audioTimer >  80000){
    if(silo->mode == SOUND_2_LIGHT  || silo->mode == VU_METER){
    audioTimer = currentCycleCount;
    recordAudioSample();
  }
 }
}

double MicHandler::getPeakFrequency(){
  return FFT.MajorPeak(fourierBufferReal, ringBufferSize, samplingFrequency);
}

void MicHandler::printVector()
{
  for (uint16_t i = 3; i < (ringBufferSize >> 1); i++)
  {
    double abscissa = ((i * 1.0 * samplingFrequency) / ringBufferSize);

    String bar = "";
    for(unsigned int j = 0; j < fourierBufferReal[i]*10; j++) bar += "|";

    debugFkt(String(abscissa, 2) + "Hz: " + bar, DEBUG);
  }
}

void MicHandler::calculateFFT(){
  for(int i = 0; i < ringBufferSize; i++){
    unsigned int correctIndex = ringBufferCounter+i;
    if(correctIndex > ringBufferSize) correctIndex -= ringBufferSize;

    fourierBufferReal[i] = audioRingBuffer[correctIndex];
    fourierBufferImag[i] = 0.0;
  }

      FFT.DCRemoval(fourierBufferReal, ringBufferSize);
      debugFkt("FFT: DC removed", DEBUG);

      FFT.Windowing(fourierBufferReal, ringBufferSize, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
      debugFkt("FFT: Windowed", DEBUG);

      FFT.Compute(fourierBufferReal, fourierBufferImag, ringBufferSize, FFT_FORWARD);
      debugFkt("FFT: Computed", DEBUG);

      FFT.ComplexToMagnitude(fourierBufferReal, fourierBufferImag, ringBufferSize);
      debugFkt("FFT: Magnitude", DEBUG);
}

void MicHandler::recordAudioSample(){
      //audioRingBuffer[ringBufferCounter++] = /1024.0;
      audioRingBuffer[ringBufferCounter++] = analogRead(A0)/1024.0;
      if(ringBufferCounter == ringBufferSize) ringBufferCounter = 0;
  }

double MicHandler::getAverageAmplitude(){
  double volume = 0;
  for(int i = 0; i < ringBufferSize; i++){
    //remove DC offset and calculate signal energy of sampled audio
    volume += (audioRingBuffer[i] - 0.5) * (audioRingBuffer[i] - 0.5);
  }

    //normalize values
    volume /= ringBufferSize/4;
  return volume;
}
