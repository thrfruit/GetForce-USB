#include <iostream>
#include "usb-daq-v20.h"
#include "windows.h"
float adResult;
double getForce(void);

int main() {
    float fn;
    while(1){
        fn=getForce();
        std::cout<<"Force="<<fn<<"\n";
        Sleep(1000);
    }
    return 0;
}

/*
 * 使用压力传感器测量压力值
 */
double getForce(void) {
    double force;
    // 单次采集
    ADSingleV20(0, 0, &adResult);
    // 连续采集，一个数据包为512个数据
    // ADContinuV20(0, 0, 512, 100000, adBuf);
    // for(int i=0;i<512;i++) {
    //   adResult += adBuf[i];
    // }
    // adResult /= 512.0;
    force = (double)(100.0/(2.7-adResult)-40.0);
    return force;
}
