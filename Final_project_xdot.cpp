#include "mbed.h"
#define BETA 3975
AnalogIn sensor_1(PB_0);
DigitalOut vcc_1(GPIO0);
//AnalogIn sensor_2(PB_2);
//DigitalOut vcc_2(GPIO3);
//AnalogIn sensor_3(PA_5);
//DigitalOut vcc_3(GPIO1);
//const int sensorMin = 0;     
//const int sensorMax = 1024;

int main() {
    printf("\r\n Flame Test program");
    printf("\r\n********\r\n");
    vcc_1 = 3.3;
//    vcc_2 = 3.3;
//    vcc_3 = 3.3;
    unsigned int val_1, val_2, val_3;
    while (1) {
        val_1=sensor_1.read_u16();
        //printf("Flame sensor 1 reading is %d \t \t \n",val_1);
        if (val_1 > 60000)
        {
            printf("No fire detected\t \t");
        }
        else if(val_1 > 40000 && val_1 < 60000)
        {
            printf("Fire detected at 20 to 30m \t \t");
        }
        else if(val_1 > 20000 && val_1 < 40000)
        {
            printf("Fire detected at 10 to 20m\t \t ");
        }
        else
        {
            printf("Fire detected at 1 to 10m\t \t");
        }
            
//        val_2=sensor_2.read_u16();
//        printf("Flame sensor 2 reading is %d \n",val_2);
//        val_3=sensor_3.read_u16();
//        printf("Flame sensor 3 reading is %d \n",val_3);
        // range value:
        /*switch (range) {
          case 0:    // A fire closer than 1.5 feet away.
            printf("** Close Fire **");
            break;
          case 1:    // A fire between 1-3 feet away.
            printf("** Distant Fire **");
            break;
          case 2:    // No fire detected.
            printf("No Fire");
            break;
        }*/
        wait(5);
    }
}