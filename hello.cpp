#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int SAMPLE_RATE=44100;
const float FREQ_1=880.0f;
const float FREQ_2=440.0f;
const float DURATION=0.1f;


static std::string stringToBinary(const std::string& txt) {
    std::string binary;
    for(char c: txt){
        for(int i=7;i>-1;i--){
            binary+= ((c>>i)&1)?'1':'0';       
        }
    }
    return binary;
}

static std::vector<float> generateSoundWave(float frequency,float duration){
    std::vector<float> waves;
    int numSamples=static_cast<int>(SAMPLE_RATE*duration);
    for(int i=0;i<numSamples;i++){
        float sample=0.5f*sin(2.0f*M_PI*frequency*i/SAMPLE_RATE);
        waves.push_back(sample);
    }
    return waves;
}
int main(){
    std::string txt="hello world!!!";
    std::string binarytxt=stringToBinary(txt);
    std::cout<< binarytxt;
    
    for(char bit:binarytxt){
        float freq=bit=='1'?FREQ_1:FREQ_2;
        std::vector<float> waves=generateSoundWave(freq,DURATION);
         //std::cout<< waves;
    }
    return 0;
}

