#ifndef __METHODS_H__
#define __METHODS_H__

#include <omp.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

//1dim methods
//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%BF%D1%80%D1%8F%D0%BC%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%BE%D0%B2
double mid_rect(const double a, const double b, const size_t n);
double right_rect(const double a, const double b, const size_t n);
double left_rect(const double a, const double b, const size_t n);
//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D1%82%D1%80%D0%B0%D0%BF%D0%B5%D1%86%D0%B8%D0%B9
double trapez(const double a, const double b, const size_t n);
//https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%A1%D0%B8%D0%BC%D0%BF%D1%81%D0%BE%D0%BD%D0%B0
double simpson(const double a, const double b, const size_t n);
double newton_cotes(const double a, const double b, const size_t n);

//2dim methods
//https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%9C%D0%BE%D0%BD%D1%82%D0%B5-%D0%9A%D0%B0%D1%80%D0%BB%D0%BE
double monte_carlo_2d(const double a, const double b,const double c,const double d, const size_t n);
double simpson_2d(const double a,const double b,const double c,const double d,const size_t n);
double trapez_2d(const double a,const double b, const double c,const double d,const size_t n);
double mid_rect_2d(const double a, const double b, const double c, const double d, const size_t n);
double left_rect_2d(const double a, const double b, const double c, const double d, const size_t n);
double right_rect_2d(const double a, const double b, const double c, const double d, const size_t n);
double newton_cotes_2d(const double a, const double b, const double c, const double d, const size_t n);


#endif // __METHODS_H__