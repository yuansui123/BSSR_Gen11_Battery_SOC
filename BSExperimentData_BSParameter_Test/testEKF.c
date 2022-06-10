#include <stdio.h>
#include "batteryEKF.h"
#include "batteryEKF.c"

void printTime(){
   float time = 0.0f;

   for(int i =0; i<MAX_ITERATION_NUM; i++){
      time += deltaT[i];
      printf("%f\n", time);
   }
}

void printBlueSkySOC(){
   EKF_Battery test; 

   initBatteryAlgo(&test);

   for(int i=0; i<MAX_ITERATION_NUM; i++){
      run_EKF(&test.batteryPack[0], i);
      printf("%f\n", test.batteryPack[0].stateX[0]);
}

}

void printOCV(){
   float soc = 0.0f;
   float ocv_calculated = 0.0f;
   for (int i = 0; i<BSSR_OCV_DATA_SIZE; i++){
      printf("ocv actual = %f \n", BSSR_OCV[i]);
      ocv_calculated = OCV(soc);
      soc += 0.005;
      printf("ocv calculated = %f \n", ocv_calculated);
   }
}

void main(){
   printBlueSkySOC();
   //printTime();
   //printOCV();
}