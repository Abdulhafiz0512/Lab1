#include <iostream>
using namespace std;
class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Timer(int h, int m, int s) {
        seconds = s % 60;
        m=m+s/60;
        minutes = m % 60;
        h=h+m/60;
        hours = h % 24;


    }


    void printTime() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

int main() {
    int h,m,s;
    cin>>h>>m>>s;

    Timer t1(h, m, s);
    t1.printTime();



    return 0;
}