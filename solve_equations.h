#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>  
#include <math.h>  
const double EPS = 0.000001;


enum number {
    ERR    = -2,
    INF    = -1,
    ZERO   = 0,
    ONE    = 1,
    TWO    = 2,
};



int is_equal(double a, double b);

//{============================================================================
//! Solve linear equation " ax + b = 0 "
//!
//! @param [in]  a       coefficient a
//! @param [in]  b       coefficient b
//!
//! @param [out] x      pointer for solution
//!
//! @return number of solutions
//!
//! @note in case of infinite number of solutions returns INF_NUM_OF_SOL = -1
//}============================================================================

enum number solve_linear( double a, double b, double* x );

//{============================================================================
//! Solves quadratic equations " ax^2 + bx + c = 0 "
//!
//! @param [in]  a       a-coefficient
//! @param [in]  b       b-coefficient
//! @param [in]  c       c-coefficient
//!
//! @param [out] x1      pointer for first solution
//! @param [out] x2      pointer for second solution
//!
//! @return number of solutions
//!
//! @note in case of infinite number of solutions returns INF_NUM_OF_SOL = -1
//}============================================================================

enum number solve_quadr( double a, double b, double c, double* x1, double* x2 );