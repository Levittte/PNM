#include <cmath>
#include "function.h"
#include <random>
#include <iomanip>
//вариант №7
double f(const double x)
{
    return exp(-1.46 * pow(x, 2)) / (3.5 + sin(x));
}

double f2d(const double x, const double y)
{
    if ((x > 0 && x < 1) && (y > 2 && y < 5))
        return x / pow(y, 2);
    else
        return 0;
    // return  ((y < x) and (y > x/2)) ? pow(x+y,2)/x : 0;
}

void rand_real_dist(double min, double max, double *arr, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dis(min, max);
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        arr[i] = dis(gen);
    }
}
