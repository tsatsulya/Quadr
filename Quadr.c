
#include "solve_equations.h"
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>

// TODO: tests, doxygen

static double min(double a, double b) {
    return (a > b) ?  b : a;
}

static double max(double a, double b) {
    return (a < b) ?  b : a;
}
// //{============================================================================
//! For safer natural+0 numbers
//!
//! @note NOT_A_NUMBER = -2 is for NAN
//! @note INF = -1 is for infinite numbers
//}============================================================================

static void out_solutions(enum number num_of_solv, double x1, double x2) {
    switch (num_of_solv)
    {

        case ZERO:
            printf ("No solutions:(((\n");
            break;

        case ONE:
            printf ("1 solution: %lf!\n", x1);
            break;

        case TWO:
            printf ("2 solutions: %lf and %lf!\n", x1, x2);
            break;

        case INF:
            printf ("Infinite number of solutions :33\n");
            break;

        default:
            printf ("ERROR: invalid values of solutions\n");
            return;

    }
}

void test_result_input(double a, double b, double c, int result, double x1_, double x2_, int num_of_solv, double x1, double x2) {
    printf("\ncoefficients: a = %lf; b = %lf; c = %lf\n", a, b, c);
    printf("result of the program: num_of_sol = %d, x1 = %lf, x2 = %lf\n", num_of_solv, x1, x2);
    printf("right result: num_of_sol = %d, x1 = %lf, x2 = %lf\\nn", result, x1_, x2_);
}

int test(const char* path) {
    double a, b, c;
    double x1_, x2_, x1, x2;
    int result;
    FILE* tests = fopen(path, "r");
    if (!tests) {
        printf(" Damn: %s\n", strerror(errno) );
        return 1;
    }
    int tests_count = 0;
    
    fscanf(tests, "%d", &tests_count);
    int accepted_tests = tests_count;

    for (int i = 0; i < tests_count; i++) {
        int valid_data = fscanf(tests, "%d%lf%lf%lf%lf%lf", &result, &x1_, &x2_, &a, &b, &c);
        enum number num_of_solv;
        if (valid_data!=6)  {
            num_of_solv = ERR;
        }
        else {
            num_of_solv = solve_quadr (a, b, c, &x1, &x2);
        }


        if (result != num_of_solv) {
            printf("TEST №%d : FAILED\n", i+1);
            accepted_tests--;
            if (result == -2) {
                puts("invalid input\n");
            }
            else {
                test_result_input(a, b, c, result, x1_, x2_, num_of_solv, x1, x2);
            }
            continue;
        }
        else {
            if (result == -2 || result == -1 || result == 0) continue;
            if (min(x1, x2) != min(x1_, x2_) || max(x1, x2) != max(x1_, x2_)) {
                printf("TEST №%d : FAILED\n", i+1);
                accepted_tests--;
                test_result_input(a, b, c, result, x1_, x2_, num_of_solv, x1, x2);
                continue;
            }
        }
        
    }
    printf("passed tests: %d / %d\n", accepted_tests, tests_count);
    fclose(tests);
    return 1;
}

int main () {
    
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    test("tests.txt");
    printf ("Input coefficients:    ");
    int valid_data = scanf  ("%lf %lf %lf", &a, &b, &c);
    puts("\n");

    enum number num_of_solv;
    if (valid_data!=3) 
        num_of_solv = ERR;
    else
        num_of_solv = solve_quadr (a, b, c, &x1, &x2);

    out_solutions(num_of_solv, x1, x2);

    printf("number of solutions: %d\n", num_of_solv);
    

    return 0;
}



