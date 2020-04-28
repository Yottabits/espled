#include <MicHandler.h>

MicHandler::MicHandler(varSilo* silo){
  this->silo = silo;
}

void MicHandler::printVector(double *vData, uint16_t bufferSize)
{
  for (uint16_t i = 0; i < (bufferSize >> 1); i++)
  {
    double abscissa = ((i * 1.0 * samplingFrequency) / ringBufferSize);

    String bar = "";
    for(unsigned int j = 0; j < vData[i]*10; j++) bar += "|";

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
      audioRingBuffer[ringBufferCounter++] = analogRead(A0)/1024.0;
      if(ringBufferCounter == ringBufferSize) ringBufferCounter = 0;
  }
