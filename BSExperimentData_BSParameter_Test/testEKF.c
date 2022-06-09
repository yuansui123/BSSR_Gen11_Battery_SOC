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

void main(){
   //printBlueSkySOC();
   //printTime();
}