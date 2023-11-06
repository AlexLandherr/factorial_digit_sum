#include "include/functions.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

namespace func {
    std::string add_num_str(std::string str1, std::string str2) {
        std::string result;
        //Making sure number strings are equally long.
        if (str1.length() > str2.length()) {
            str2.insert(0, (str1.length() - str2.length()), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, (str2.length() - str1.length()), '0');
        }

        //Adding number strings together, one digit at a time from right to left.
        int carry = 0;
        for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
            std::string digit_1 = str1.substr(i, 1);
            std::string digit_2 = str2.substr(i, 1);
            result.insert(0, std::to_string((std::stoi(digit_1) + std::stoi(digit_2) + carry) % 10));
            //std::cout << "i: " << i << " digit_1: " << digit_1 << " digit_2: " << digit_2 << " temp_sum: " << (std::stoi(digit_1) + std::stoi(digit_2) + carry) << " carry: " << carry << '\n';
            carry = (std::stoi(digit_1) + std::stoi(digit_2) + carry) / 10;
        }

        //Prepend the final carry value to the result std::string.
        //std::cout << "carry after loop exit: " << carry << '\n';
        if (carry > 0) {
            result.insert(0, std::to_string(carry));
        }

        return result;
    }

    std::string multiply_num_str(std::string str1, std::string str2) {
        /*For each digit in str1 multiply it with each digit from str2 (from right to left)
        and add the carry to said product.
        
        Then prepend the (result % 10) to a string to be inserted in a vector holding the result for
        the each digit in str1 times the corresponding one in str2.
        
        Then take the sum of the numbers in the vector to get the final product.*/
        std::string result = "0";
        std::vector<std::string> interim_results;

        //Making sure number strings are equally long.
        /* std::cout << "Before making sure they're of equal lenght:" << '\n';
        std::cout << "str1: " << str1 << '\n';
        std::cout << "str2: " << str2 << '\n';
        std::cout << '\n'; */
        if (str1.length() > str2.length()) {
            str2.insert(0, (str1.length() - str2.length()), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, (str2.length() - str1.length()), '0');
        }
        /* std::cout << '\n';
        std::cout << "After making sure they're of equal lenght:" << '\n';
        std::cout << "str1: " << str1 << '\n';
        std::cout << "str2: " << str2 << '\n';
        std::cout << '\n'; */

        for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
            uint64_t carry = 0;
            std::string current_digit_prod_str;
            std::string digit_1 = str1.substr(i, 1);
            uint64_t place_value_multiplier = std::pow(10, static_cast<int>(str1.length() - (i + 1)));

            for (int j = static_cast<int>(str2.length()) - 1; j >= 0; j--) {
                std::string digit_2 = str2.substr(j, 1);
                current_digit_prod_str.insert(0, std::to_string((((std::stoi(digit_1) * place_value_multiplier) * std::stoi(digit_2)) + carry) % 10));

                /* std::cout << "i: " << i << " j: " << j << " dg1: " << digit_1 << " dg2: " << digit_2 << " pvm: " << place_value_multiplier
                << " inter_res: " << std::to_string((((std::stoi(digit_1) * place_value_multiplier) * std::stoi(digit_2)) + carry) % 10) <<
                " carry: " << carry << '\n'; */

                carry = (((std::stoi(digit_1) * place_value_multiplier) * std::stoi(digit_2)) + carry) / 10;
            }

            if (carry > 0) {
                current_digit_prod_str.insert(0, std::to_string(carry));
            }

            interim_results.push_back(current_digit_prod_str);
        }

        /* std::cout << "Interim results:" << '\n';
        for (std::string str : interim_results) {
            std::cout << str << '\n';
        }
        std::cout << '\n'; */

        if (interim_results.size() == 1) {
            result = interim_results[0];
        } else {
            for (int k = 0; k < static_cast<int>(interim_results.size()); k++) {
                result = add_num_str(result, interim_results[k]);
            }
        }

        return result;
    }

    std::string factorial_str(int n) {
        std::string result = "1";
        for (int i = 1; i <= n; i++) {
            //std::cout << i << "! " << "Running product: " << result << '\n';
            result = multiply_num_str(result, std::to_string(i));
            //std::cout << i << "!" << " = " << result << '\n';
        }
        return result;
    }
}