#include <stdio.h>
#include "solve_equations.h"
#include <stdbool.h>

typedef struct QuadraticEquationTest { 
    double a, b, c;
    enum number result;
    double x1, x2;
} Test;

enum result {
    OK = 1,
    WA = 0
};

Test* tests_init(const char* path, int* tests_count);

void print_test_info(Test* test);

void print_program_result(enum number result, double x1, double x2);

bool test_quadratic_solver(Test* test, double* x1, double* x2, enum number result);

void global_testing(const char* path);

void print_solutions(enum number result, double x1, double x2)