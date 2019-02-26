#include <iostream>
#include <sstream>
#include <chrono>
#include <stdexcept>

#include "matrix.h"
#include "function.h"
#include "methods.h"

int main(){

    double max_abs_dfx = 0.29321293601871024;
    double max_abs_ddfx = 0.32911193590042614;
    double max_abs_ddddfx =  4.159392047087623;

    const double a = 0.3;
    const double b = 0.8;
    const size_t n = 10000;


    // auto startTime = std::chrono::steady_clock::now();

  
    std::cout<<"MID: "<<mid_rect(a, b,n)<<" RUNGE: "<<fabs(mid_rect(a, b,n)-mid_rect(a, b,2*n))<<std::endl;
    std::cout<<"LEFT: "<<left_rect(a, b,n)<<" RUNGE: "<<fabs(left_rect(a, b,n)-left_rect(a, b,2*n))<<std::endl;
    std::cout<<"RIGHT: "<<right_rect(a, b,n)<<" RUNGE: "<<fabs(right_rect(a, b,n)-right_rect(a, b,2*n))<<std::endl;
    std::cout<<"TRAPEZ: "<<trapez(a, b,n)<<" RUNGE: "<<fabs(trapez(a, b,n)-trapez(a, b,2*n))<<" HALFSUM: "<<(left_rect(a,b,n)+right_rect(a,b,n))/2<<std::endl;
    std::cout<<"SIMPSON: "<<simpson(a, b,n)<<" RUNGE: "<<fabs(simpson(a, b,n)-simpson(a, b,2*n))<<std::endl;
    std::cout<<"3/8 NC: "<<newton_cotes(a, b,n)<<" RUNGE: "<<fabs(newton_cotes(a, b,n)-newton_cotes(a, b,2*n))<<std::endl;


    std::cout<<"MID ASB: "<<max_abs_dfx*(pow(b-a,2)/2)<<std::endl;
    std::cout<<"LEFT ASB: "<<max_abs_dfx*(pow(b-a,2)/2)<<std::endl;
    std::cout<<"RIGHT ASB: "<<max_abs_ddfx*(pow(b-a,3)/24)<<std::endl;
    std::cout<<"TRAPEZ ASB: "<<max_abs_ddfx*(pow(b-a,3)/12)<<std::endl;
    std::cout<<"SIMPSON ASB: "<<max_abs_ddddfx*(pow(b-a,5)/2880)<<std::endl;
    std::cout<<"3/8 NC ASB: "<<max_abs_ddddfx*(pow(b-a,5)/2880)<<std::endl;
    // res = monte_carlo(a, b,10000);
    // std::cout<<"MONTE CARLO:"<<res<<std::endl;
    // auto runTime= std::chrono::steady_clock::now(); 
    // auto runtimeDuration = std::chrono::duration_cast<std::chrono::duration<double>>(runTime - startTime);
    // std::cout<<"RUNTIME:"<<runtimeDuration.count()<<std::endl;
    return 0;
}