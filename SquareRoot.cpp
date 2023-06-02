#include <iostream>

double customSqrt(double n) {
    double x = n;
    double y = 1;
    double e = 0.000001;
    while(x - y > e)
    {
        x = (x + y)/2;
        y = n/x;
    }
    return x;
}

int main() {
    char repeat = 'y';
    while (repeat == 'y') {
        for (int i = 1; i <= 25; i += 2) {
            double sqrt_val = customSqrt(i);
            std::cout << "The square root of " << i << " is " << sqrt_val << '\n';
        }
        break;
    }
    return 0;
}

