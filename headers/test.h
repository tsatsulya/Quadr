#include <stdio.h>
#include "solve_equations.h"

typedef struct Test {
    double a, b, c;
    enum number result;
    double x1, x2;

} Test;

Test* tests_init(const char* path, int* tests_count);

void output_test_info(Test* test);

void output_program_result(Test* test);

int test_check(Test* test);

void global_testing(const char* path);