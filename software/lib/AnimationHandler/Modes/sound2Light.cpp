#include <AnimationHandler.h>
#include <arduinoFFT.h>

#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

//Geschätzt
#define samplingFrequency 1000

void printVector(double *vData, uint16_t bufferSize)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa = ((i * 1.0 * samplingFrequency) / ringBufferSize);

    String bar = "";
    for(unsigned int j = 0; j < vData[i]*10; j++) bar += "|";

    debugFkt(String(abscissa, 2) + "Hz: " + bar, DEBUG);
  }
}


CRGBWW AnimationHandler::sound2Light(){
  arduinoFFT FFT = arduinoFFT();

  double fourierBufferReal[ringBufferSize];
  double fourierBufferImag[ringBufferSize];

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

      printVector(fourierBufferReal, (ringBufferSize >> 1));
      unsigned int freqRangeValue[3] = {0,0,0};

      //TODO: Fix reduction to 3 frequency bands
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < (ringBufferSize/2)/3; j++)
          freqRangeValue[i] += fourierBufferReal[j] *10;
      }

    return CRGBWW{0,0,0,0,0};
}
