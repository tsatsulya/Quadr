#include "test.h"

Test* tests_init(const char* path, int* tests_count) {
    
    FILE* file = fopen(path, "r");
    assert(file && "failed to read file");
    

    fscanf(file, "%d", tests_count);

    Test* tests = ( Test* ) calloc( *tests_count, sizeof(Test) );

    double x1 = NAN, x2 = NAN, a = NAN, b = NAN, c = NAN;
    int result = ERR;
    int err = 0;
    for (int i = 0; i < *tests_count; i++) {

        int valid_data = fscanf(file, "%d%lf%lf%lf%lf%lf", &result, &x1, &x2, &a, &b, &c);

        if (valid_data == 6) {

            Test r = {a, b, c, ( enum number ) result, x1, x2};
            *(tests+i) = r;
        }
        else { 
            err++;
            continue;
        }

    }
    *tests_count-=err;
    return tests;


}

void output_test_info(Test* test) {

    puts("test info:");

    printf("        coeffitients: a = %lf ; b = %lf ; c = %lf\n", test->a, test->b, test->c);
    printf("        number of solutions: %d\n", test->result);

    if (test->result == 1)
        printf("        solve: %lf \n\n", test->x1);
    if (test->result == 2)
        printf("        solves: %lf , %lf\n\n", test->x1, test->x2);
}

void output_program_result(Test* test) {

    double x1 = NAN, x2 = NAN;
    enum number result = solve_quadr(test->a, test->b, test->c, &x1, &x2);
    
    puts("program result:");

    printf("        number of solutions: %d\n", result);

    if (result == 1) 
        printf("        Solution : %lf\n\n", x1);


    if (result == 2) 
        printf("        Solutions : %lf ; %lf\n\n", x1, x2);

}

int test_check(Test* test) {
    double x1 = NAN, x2 = NAN;
    enum number result = solve_quadr(test->a, test->b, test->c, &x1, &x2);
    //output_program_result(result, x1, x2);

    if (result != test->result) 
        return 0;

    if (result == 0 || result == -1) 
        return 1;

    if (min(x1, x2) != min(test->x1, test->x2) || max(x1, x2) != max(test->x1, test->x2)) 
        return 0;

    return 1;
}

void global_testing(const char* path) {
        int tests_count;
    int wa = 0;
    Test* tests = tests_init(path, &tests_count);

    for (int i = 0; i < tests_count; ++i) {
        int is_succ = test_check(tests+i);
        //puts( is_succ ? "OK" : "WA" );

        if (!is_succ) {
            puts("\n!TEST FAILED!\n");
            wa++;
            output_test_info(tests+i);
            output_program_result(tests+i);
        }
    }
    printf("passed tests: %d / %d\n", tests_count-wa, tests_count);
}