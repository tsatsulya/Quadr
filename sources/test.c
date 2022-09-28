#include "test.h"


Test* tests_init(const char* path, int* tests_count) {
    
    FILE* file = fopen(path, "r");
    assert(file && "failed to read file");
    

    fscanf(file, "%d", tests_count);

    Test* tests = ( Test* ) calloc( *tests_count, sizeof(Test) );

    double x1 = NAN, x2 = NAN, a = NAN, b = NAN, c = NAN;
    int result = ERR;
    int failed_test_count = 0;
    for (int i = 0; i < *tests_count; i++) {

        int valid_data = fscanf(file, "%d%lf%lf%lf%lf%lf", &result, &x1, &x2, &a, &b, &c);

        if (valid_data != 6) {
            failed_test_count++;
            continue; 
        }
        else {
            // TODO: Why "r"? Check out compound literals!
            *(tests+i) = ( Test ){a, b, c, ( enum number ) result, x1, x2};
        }

    }
    *tests_count-=failed_test_count;
    return tests;


}


void print_solutions(enum number result, double x1, double x2) {
    if (result == 1)
        printf("        solution: %lf \n\n", x1);
    if (result == 2)
        printf("        solutions: %lf , %lf\n\n", x1, x2);
}

void print_test_info(Test* test) { 

    puts("test info:");

    printf("        coeffitients: a = %lf ; b = %lf ; c = %lf\n", test->a, test->b, test->c);
    printf("        number of solutions: %d\n", test->result);

    print_solutions(test->result, test->x1, test->x2);
}

void print_program_result(enum number result, double x1, double x2) {
    
    puts("program result:");

    printf("        number of solutions: %d\n", result);

    print_solutions(result, x1, x2);

}

bool test_quadratic_solver(Test* test, double* x1, double* x2, enum number result) { 

    result = solve_quadr(test->a, test->b, test->c, x1, x2);
    //output_program_result(result, x1, x2);

    if (result != test->result) 
        return WA;

    if (result == ZERO || result == INF) 
        return OK;

    if (min(*x1, *x2) != min(test->x1, test->x2) || max(*x1, *x2) != max(test->x1, test->x2)) 
        return WA;

    return OK;
}

void global_testing(const char* path) { // TODO: global warming

    int tests_count;

    int wrong_answers = 0;

    Test* tests = tests_init(path, &tests_count);
    double x1 = NAN, x2 = NAN;
    enum number result = ERR;
    for (int i = 0; i < tests_count; ++i) {

        int is_successful = test_quadratic_solver(tests+i, &x1,  &x2,  result);
        
        //puts( is_succ ? "OK" : "WA" );

        if (!is_successful) {
            puts("\n!TEST FAILED!\n");
            wrong_answers++;
            print_test_info(tests+i);
            print_program_result(result, x1, x2);
        }
    }
    printf("passed tests: %d / %d\n", tests_count-wrong_answers, tests_count);
}