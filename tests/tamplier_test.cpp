/* 
 * File:   tamplier_test.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 31 iulie 2018, 16:17
 */

#include <stdlib.h>
#include <iostream>
#include "tamplier.h"

/*
 * Simple C++ Test Suite
 */

void testTamplier() {
    std::string p0 = "this is a <template>";
    mc::tamplier _tamplier(p0);
    if (_tamplier.to_string() != p0) {
        std::cout << "%TEST_FAILED% time=0 testname=testTamplier (tamplier_test) message=what happens?!" << std::endl;
    }
}

void testFillVector() {
    const mc::vector& p0 = {
        {"<!-- title -->", "this is a title"},
        {"<!-- body -->", "this is a body content"}
    };

    const std::string tpl = "<html>"
            "<head>"
            "<title><!-- title --></title>"
            "</head>"
            "<body>"
            "<!-- body -->"
            "</body>"
            "</html>";

    const std::string test_value = "<html>"
            "<head>"
            "<title>this is a title</title>"
            "</head>"
            "<body>"
            "this is a body content"
            "</body>"
            "</html>";

    mc::tamplier _tamplier(tpl);
    std::string result = _tamplier.fill(p0).to_string();
    if (result != test_value) {
        std::cout << "%TEST_FAILED% time=0 testname=testFill (tamplier_test) message=error message sample" << std::endl;
    }
}

void testFillVectorN() {
    const mc::vector& p0 = {
        {"111", "31"},
        {"222", "32"},
        {"333", "33"},
        {"11", "21"},
        {"33", "32"}
    };

    std::size_t depth = 1;

    const std::string tpl = "1111111111";
    const std::string test_value = "3131321";

    mc::tamplier _tamplier(tpl);
    std::string result = _tamplier.fill(p0, depth).to_string();
    if (result == test_value) {
        std::cout << "%TEST_PASSED% time=0 testname=testFillN (tamplier_test) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_FAILED% time=0 testname=testFillN (tamplier_test) message=error filling" << std::endl;
        std::cout << "\ttpl = " << tpl << std::endl;
        std::cout << "\tdepth = " << depth << std::endl;
        std::cout << "\ttest_value = " << test_value << std::endl;
        std::cout << "\tresult = " << result << std::endl;
    }
}

void testFillContinueousVector() {
    const std::string tpl = "<html>"
            "<head>"
            "<title><!-- title --></title>"
            "</head>"
            "<body>"
            "<!-- body -->"
            "</body>"
            "</html>";

    const std::string test_value = "<html>"
            "<head>"
            "<title>this is a title</title>"
            "</head>"
            "<body>"
            "this is a body content"
            "</body>"
            "</html>";

    mc::tamplier _tamplier(tpl);
    std::string result = _tamplier
            .fill({{"<!-- title -->", "this is a title"}})
            .fill({{"<!-- body -->", "this is a body content"}})
            .to_string();
    if (result != test_value) {
        std::cout << "%TEST_FAILED% time=0 testname=testFill (tamplier_test) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% tamplier_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testTamplier (tamplier_test)" << std::endl;
    testTamplier();
    std::cout << "%TEST_FINISHED% time=0 testTamplier (tamplier_test)" << std::endl;

    std::cout << "%TEST_STARTED% testFillVector (tamplier_test)" << std::endl;
    testFillVector();
    std::cout << "%TEST_FINISHED% time=0 testFillVector (tamplier_test)" << std::endl;

    std::cout << "%TEST_STARTED% testFillVectorN (tamplier_test)" << std::endl;
    testFillVectorN();
    std::cout << "%TEST_FINISHED% time=0 testFillVectorN (tamplier_test)" << std::endl;

    std::cout << "%TEST_STARTED% testFillContinueousVector (tamplier_test)" << std::endl;
    testFillContinueousVector();
    std::cout << "%TEST_FINISHED% time=0 testFillContinueousVector (tamplier_test)" << std::endl;
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

