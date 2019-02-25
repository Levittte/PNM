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
    auto startTime = std::chrono::steady_clock::now();

    res = mid_rect(a, b,200);
    std::cout<<"MID:"<<res<<std::endl;
    res = left_rect(a, b,200);
    std::cout<<"LEFT:"<<res<<std::endl;
    res = right_rect(a, b,200);
    std::cout<<"RIGHT:"<<res<<std::endl;
    res = trapez(a, b,200);
    std::cout<<"TRAPEZ:"<<res<<std::endl;
    res = simpson(a, b,200);
    std::cout<<"SIMPSON:"<<res<<std::endl;
    // res = monte_carlo(a, b,10000);
    // std::cout<<"MONTE CARLO:"<<res<<std::endl;
    auto runTime= std::chrono::steady_clock::now(); 
    auto runtimeDuration = std::chrono::duration_cast<std::chrono::duration<double>>(runTime - startTime);
    std::cout<<"RUNTIME:"<<runtimeDuration.count()<<std::endl;
    return 0;
}