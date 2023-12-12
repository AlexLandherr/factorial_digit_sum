#include <string>
#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::string add_num_str(std::string &str1, std::string &str2);
    std::string multiply_num_str(std::string &str1, std::string &str2);
    std::string factorial_str(int n);
    uint64_t sum_of_digits(std::string &str);
}

#endif