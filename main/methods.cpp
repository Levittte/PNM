#include "function.h"
#include "methods.h"

double mid_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=0; i < n -1; i++){

        result += f(a + h * (i + 0.5)); 
    }

    return result*h;
}

double left_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=0; i < n - 1; i++){

        result += f(a + h * i); 
    }

    return result*h;
}

double right_rect(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b-a)/n; 

    #pragma omp parallel for reduction (+:result)
    for(size_t i=1; i < n; i++){

        result += f(a + h * i); 
    }

    return result*h;
}

double simpson(const double a, const double b, const size_t n){
   
    double result = 0;
    const double h = (b-a)/(2*n);

    #pragma omp parallel for reduction (+:result)
    for(size_t i=1;i<=(2*n-1);i++)
    {
        result+=(3+pow(-1,i+1))*f(a+i*h);
    }
    return h/3*(f(a)+f(b)+result);
}

double trapez(const double a, const double b, const size_t n){
    double result = 0;
    const double h = (b - a) / n;

    result =(f(a)+f(b))/2;

    #pragma omp parallel for reduction (+:result)
    for(size_t i = 1; i < n - 1; i++) {
        result+=f(a+i*h);
    }

    return result*h;
}

double monte_carlo(const double a, const double b, const size_t n){
  
    return 0.0;
}