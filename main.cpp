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
 * ʹ��ѹ������������ѹ��ֵ
 */
double getForce(void) {
    double force;
    // ���βɼ�
    ADSingleV20(0, 0, &adResult);
    // �����ɼ���һ�����ݰ�Ϊ512������
    // ADContinuV20(0, 0, 512, 100000, adBuf);
    // for(int i=0;i<512;i++) {
    //   adResult += adBuf[i];
    // }
    // adResult /= 512.0;
    force = (double)(100.0/(2.7-adResult)-40.0);
    return force;
}
