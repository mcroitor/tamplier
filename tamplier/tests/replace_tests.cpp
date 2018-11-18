/* 
 * File:   replace_tests.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 31 iulie 2018, 15:17
 */

#include <stdlib.h>
#include <array>
#include <iostream>
#include "tamplier.h"

/*
 * Simple C++ Test Suite
 */

std::array<std::string, 4> tests[9] = {
    {"mama mila ramu", "mama", "masa", "masa mila ramu"},
    {"(())()", "()", ")(", "()())("},
    {"to be or not to be", "be", "beer", "to beer or not to beer"},
    {"1111111111", "11", "1", "11111"},
    {"1111111111", "11", "2", "22222"},
    {"this is an immutable string", "nokey", "novariant", "this is an immutable string"},
    {"mama mila ramu", "ma", "pa", "papa mila ramu"},
    {"mama mila ramu", " ", "", "mamamilaramu"},
    {"mama mila ramu", "", "masa", "mama mila ramu"}
};

void testReplace() {
    for(auto test: tests){
        std::string from = test[1];
        std::string to = test[2];
        std::string source = test[0];
        std::string test_value = test[3];
        std::string result = mc::replace(from, to, source);
        if (result == test_value){
            std::cout << "%TEST_PASSED% time=0 testname=testReplace (replace_tests) message=error message sample" << std::endl;
        } 
        else {
            std::cout << "%TEST_FAILED% time=0 testname=testReplace (replace_tests) message=error replacing" << std::endl;
            std::cout << "\tfrom = " << from << std::endl;
            std::cout << "\tto = " << to << std::endl;
            std::cout << "\tsource = " << source << std::endl;
            std::cout << "\ttest_value = " << test_value << std::endl;
            std::cout << "\tresult = " << result << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% replace_tests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testReplace (replace_tests)" << std::endl;
    testReplace();
    std::cout << "%TEST_FINISHED% time=0 testReplace (replace_tests)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

