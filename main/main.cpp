#include <iostream>
#include <sstream>
#include <chrono>
#include <stdexcept>

#include "function.h"
#include "methods.h"

int main()
{

    double max_abs_dfx = 0.29321293601871024;
    double max_abs_ddfx = 0.32911193590042614;
    double max_abs_ddddfx = 4.159392047087623;

    const double a = 0.3;
    const double b = 0.8;

    const size_t n = 1000;

    std::cout<< "1 dim methods"<<std::endl;
    std::cout << "MID: " << mid_rect(a, b, n) << " RUNGE: " << fabs(mid_rect(a, b, n) - mid_rect(a, b, 2 * n)) << std::endl;
    std::cout << "LEFT: " << left_rect(a, b, n) << " RUNGE: " << fabs(left_rect(a, b, n) - left_rect(a, b, 2 * n)) << std::endl;
    std::cout << "RIGHT: " << right_rect(a, b, n) << " RUNGE: " << fabs(right_rect(a, b, n) - right_rect(a, b, 2 * n)) << std::endl;
    std::cout << "TRAPEZ: " << trapez(a, b, n) << " RUNGE: " << fabs(trapez(a, b, n) - trapez(a, b, 2 * n)) << " HALFSUM: " << (left_rect(a, b, n) + right_rect(a, b, n)) / 2 << std::endl;
    std::cout << "SIMPSON: " << simpson(a, b, n) << " RUNGE: " << fabs(simpson(a, b, n) - simpson(a, b, 2 * n)) << std::endl;
    std::cout << "3/8 NC: " << newton_cotes(a, b, n) << " RUNGE: " << fabs(newton_cotes(a, b, n) - newton_cotes(a, b, 2 * n)) << std::endl;

    std::cout << "MID ASB: " << max_abs_dfx * (pow(b - a, 2) / 2) << std::endl;
    std::cout << "LEFT ASB: " << max_abs_dfx * (pow(b - a, 2) / 2) << std::endl;
    std::cout << "RIGHT ASB: " << max_abs_ddfx * (pow(b - a, 3) / 24) << std::endl;
    std::cout << "TRAPEZ ASB: " << max_abs_ddfx * (pow(b - a, 3) / 12) << std::endl;
    std::cout << "SIMPSON ASB: " << max_abs_ddddfx * (pow(b - a, 5) / 2880) << std::endl;
    std::cout << "3/8 NC ASB: " << max_abs_ddddfx * (pow(b - a, 5) / 2880) << std::endl;

    const double a_xy = 0.1;
    const double b_xy = 0.9;

    const double c_xy = 2.1;
    const double d_xy = 4.9;

    std::cout<< "2 dim methods"<<std::endl;
    std::cout << "Monte carlo: " << monte_carlo_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(monte_carlo_2d(a_xy, b_xy,c_xy,d_xy, n) - monte_carlo_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "Simpson:"  << simpson_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(simpson_2d(a_xy, b_xy,c_xy,d_xy, n) - simpson_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "Trapez:"  << trapez_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(trapez_2d(a_xy, b_xy,c_xy,d_xy, n) - trapez_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "Mid rect:"  << mid_rect_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(mid_rect_2d(a_xy, b_xy,c_xy,d_xy, n) - mid_rect_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "Left rect:"  << left_rect_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(left_rect_2d(a_xy, b_xy,c_xy,d_xy, n) - left_rect_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "Right rect:"  << right_rect_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(right_rect_2d(a_xy, b_xy,c_xy,d_xy, n) - right_rect_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;
    std::cout << "3/8 NC:"  << newton_cotes_2d(a_xy, b_xy,c_xy,d_xy, n) << " RUNGE: " << fabs(newton_cotes_2d(a_xy, b_xy,c_xy,d_xy, n) - newton_cotes_2d(a_xy, b_xy,c_xy,d_xy, 2*n)) << std::endl;

    return 0;
}