#include <assert.h>
#include <ctype.h>
#include "headers/test.h"

// //{============================================================================
//! For safer natural+0 numbers
//!
//! @note NOT_A_NUMBER = -2 is for NAN
//! @note INF = -1 is for infinite numbers
//}============================================================================


// static void solutions_output(enum number num_of_solv, double x1, double x2) {
//     switch (num_of_solv)
//     {

//         case ZERO:
//             printf ("No solutions:(((\n");
//             break;

//         case ONE:
//             printf ("1 solution: %lf!\n", x1);
//             break;

//         case TWO:
//             printf ("2 solutions: %lf and %lf!\n", x1, x2);
//             break;

//         case INF:
//             printf ("Infinite number of solutions :33\n");
//             break;

//         default:
//             printf ("ERROR: invalid values of solutions\n");
//             return;

//     }
// }



int main () {
    
    //double a = NAN, b = NAN, c = NAN;
    //double x1 = NAN, x2 = NAN;

    global_testing("tests");



    // printf ("Input coefficients:    ");
    // int valid_data = scanf  ("%lf %lf %lf", &a, &b, &c);
    // puts("\n");

    // enum number num_of_solv;
    // if (valid_data!=3) 
    //     num_of_solv = ERR;
    // else
    //     num_of_solv = solve_quadr (a, b, c, &x1, &x2);

    // solutions_output(num_of_solv, x1, x2);

    // printf("number of solutions: %d\n", num_of_solv);
    

    return 0;
}



