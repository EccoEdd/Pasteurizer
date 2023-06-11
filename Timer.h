/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com   
*
*   06/04/2023
*
*/

class Timer {
private:
    unsigned long startMillis;
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;

public:
    Timer() {
        startMillis = 0;
        seconds = 0;
        minutes = 0;
        hours = 0;
    }

    void start() {
        startMillis = millis();
    }

    void update() {
        unsigned long currentMillis = millis();
        unsigned long elapsedMillis = currentMillis - startMillis;

        seconds = elapsedMillis / 1000;
        minutes = seconds / 60;
        hours = minutes / 60;
    }

    unsigned int getSeconds() {
        return seconds;
    }

    unsigned int getMinutes() {
        return minutes;
    }

    unsigned int getHours() {
        return hours;
    }
};
