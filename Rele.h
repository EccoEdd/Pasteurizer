/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com
*
*   06/12/2023
*
*/
class Rele{
    
    public:
        Rele(int p){
            pin = p;
            pinMode(pin, OUTPUT);
            enabled = true;
        }
        void prueba(){
            digitalWrite(pin, LOW);
            delay(5000);
            digitalWrite(pin, LOW);
            delay(5000);
        }
        void tempController(double temperature){
            if(temperature >= 75 && enabled){
                enabled = false;
                digitalWrite(pin, HIGH);
            }

            if(enabled){
                digitalWrite(pin, LOW);
            }
        }

    private:
        int pin;
        bool enabled;
};