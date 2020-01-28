#include <iostream>
#include "mylib.h"

// examples
void tulostus() {
    std::cout << "***********" << std::endl;
    return;
}

double circleArea(double radius) {
    radius *= radius;
    return PI * radius;
}
// END examples

int square(int x) {
    return x*x;
}

int rectArea(int w, int h) {
    return w*h;
}

double tripPrice(double km, double gasUse, double gasPrice) {
    km /= 100; // usage is 1/100 km
    return gasPrice * (gasUse * km);
}

int wage(int hours) {
    int ret;
    int hourly = 10;
    if (hours > 40) {
        ret = 40 * hourly;
        hours -= 40;
        ret += hours * (1.5 * hourly);
    } else {
        ret = hours * hourly;
    }

    return ret;
}