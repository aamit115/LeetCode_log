#include <stdlib.h>
double* convertTemperature(double celsius, int* returnSize) {
    double Kelvin = celsius + 273.15;
    double Fahrenheit = celsius * 1.80 + 32.00;
    double* ans = (double*)malloc(2 * sizeof(double));
    ans[0] = Kelvin;
    ans[1] = Fahrenheit;
    *returnSize = 2;
    return ans;
}