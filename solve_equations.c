#include "solve_equations.h"


int is_equal(double a, double b) {
    return abs(a-b) < EPS; 
}
enum number solve_linear( double a, double b, double* x ) {

    assert (x != NULL);

    assert (isfinite(a));
    assert (isfinite(b));


    if (is_equal(a, 0)) { 
        if (is_equal(b, 0))                      //0 = 0
            return INF;

        return ZERO;                            //b = 0
    }

    *x = -b / a;                                //ax + b = 0

    return ONE;
}

enum number solve_quadr( double a, double b, double c, double* x1, double* x2 ) {

    assert (x1 != NULL);
    assert (x2 != NULL);

    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));


    if (is_equal(a, 0))
        return solve_linear(b, c, x1);

    if (is_equal(c, 0)) {                          // a*x*x + x*b = 0
        *x1 = 0;
        *x2 = -b / a;
        return TWO;
    }

    double D = b * b - 4 * a * c; 

    if (D < 0)
        return ZERO;

    if (is_equal(D, 0)) {

        *x1 = *x2 = -b / (2 * a);
        return ONE;
    }

    double sqrt_D = sqrt(D);

    *x1 = (-b + sqrt_D) / (2 * a);
    *x2 = (-b - sqrt_D) / (2 * a);

    return TWO;
}