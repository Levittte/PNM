#include "function.h"
#include "methods.h"

double mid_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=0; i < n; i++){

        result += f(a + h * (i + 0.5)); 
    }

    return result*h;
}

double left_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=0; i < n; i++){

        result += f(a + h * (i-1)); 
    }

    return result*h;
}

double right_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=0; i < n; i++){

        result += f(a + h * i); 
    }

    return result*h;
}

double simpson(const double a, const double b, const size_t n){

}

double trapez(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b - a) / n;

    result +=f(a);
    result +=f(b);

    #pragma omp parallel for reduction (+:result)
    for(size_t i = 0; i < n; i++) {
        result+=f(a+i*h);
    }

    return result*h;
}