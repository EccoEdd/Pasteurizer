/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com   
*
*   06/04/2023
*
*/
#include <math.h>
class Temperature
{
private:
    unsigned int val;
    double temp;
    unsigned int analog;
public:
    Temperature(int analogR){
        val = 0;
        temp = 0;
        analog = analogR;
    }

    double getTemperature(){
        val = analogRead(0);
        temp = log(((10240000/val) - 10000));
        temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
        temp = temp - 273.15;
        return temp;
    }
};
