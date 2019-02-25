#include <iostream>
#include <sstream>
#include <chrono>
#include <stdexcept>

#include "matrix.h"
#include "function.h"
#include "methods.h"

int main(){

    const double a = 0.3;
    const double b = 0.8;
    double res = 0;
    double res2 = 0;
    size_t n = 10000;
    double res3 = 0;
    double res4 = 0;
    auto startTime = std::chrono::steady_clock::now();

    res = mid_rect(a, b,n);
    res2 = mid_rect(a, b,2*n);
    std::cout<<"MID:"<<res<<" RUNGE:"<<fabs(res2-res)<<std::endl;
    res = left_rect(a, b,n);
    res2 = left_rect(a, b,2*n);
    std::cout<<"LEFT:"<<res<<" RUNGE:"<<fabs(res2-res)<<std::endl;
    res = right_rect(a, b,n);
    res2 = right_rect(a, b,2*n);
    std::cout<<"RIGHT:"<<res<<" RUNGE:"<<fabs(res2-res)<<std::endl;
    res = trapez(a, b,n);
    res2 = trapez(a, b,2*n);
    res3 = right_rect(a,b,n);
    res4 = left_rect(a,b,n);
    std::cout<<"TRAPEZ:"<<res<<" RUNGE:"<<fabs(res2-res)<<" HALFSUM"<<(res3+res4)/2<<std::endl;
    res = simpson(a, b,n);
    res2 = simpson(a, b,2*n);
    std::cout<<"SIMPSON:"<<res<<" RUNGE:"<<fabs(res2-res)<<std::endl;
    // res = monte_carlo(a, b,10000);
    // std::cout<<"MONTE CARLO:"<<res<<std::endl;
    auto runTime= std::chrono::steady_clock::now(); 
    // auto runtimeDuration = std::chrono::duration_cast<std::chrono::duration<double>>(runTime - startTime);
    // std::cout<<"RUNTIME:"<<runtimeDuration.count()<<std::endl;
    return 0;
}