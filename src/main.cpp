#include "include/functions.h"
#include <iostream>

/*
n! means n x (n-1) x ··· x 3 x 2 x 1.

For example, 10! = 10 × 9 × ··· × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!.
*/

int main() {
    //std::cout << "The sum of the digits in the number 100! is:" << '\n';
    for (int i = 1; i <= 21; i++) {
        std::cout << i << "! = " << func::factorial_str(i) << '\n';
    }
    //std::cout << func::multiply_num_str("87178291200", "15") << '\n'; //Should be 14! = 14 x 13! = 87 178 291 200.

    return 0;
}