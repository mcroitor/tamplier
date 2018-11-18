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
    if (_tamplier.get_template() != p0) {
        std::cout << "%TEST_FAILED% time=0 testname=testTamplier (tamplier_test) message=what happens?!" << std::endl;
    }
}

void testFill() {
    const std::map<std::string, std::string>& p0 = {
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
    std::string result = _tamplier.fill(p0);
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

    std::cout << "%TEST_STARTED% testFill (tamplier_test)" << std::endl;
    testFill();
    std::cout << "%TEST_FINISHED% time=0 testFill (tamplier_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

