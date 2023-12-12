#include "include/functions.h"
#include <iostream>
#include <string>

/*
n! means n x (n-1) x ··· x 3 x 2 x 1.

For example, 10! = 10 × 9 × ··· × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!.
*/

int main() {
    std::string num_str = func::factorial_str(100);
    std::cout << "The sum of the digits in the number 100! is:" << '\n';
    std::cout << func::sum_of_digits(num_str) << '\n';
    /* for (int i = 1; i <= 21; i++) {
        std::cout << i << "! = " << func::factorial_str(i) << '\n';
    } */
    /* std::string fac = func::factorial_str(100);
    std::string fac_100 = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
    if (fac == fac_100) {
        std::cout << "Correct!" << '\n';
    } else {
        std::cout << "Wrong!" << '\n';
    } */
    /* std::string num_str = "3628800";
    std::cout << func::sum_of_digits(num_str) << '\n'; */
    //std::cout << func::multiply_num_str("87178291200", "15") << '\n'; //Should be 14! = 14 x 13! = 87 178 291 200.

    return 0;
}