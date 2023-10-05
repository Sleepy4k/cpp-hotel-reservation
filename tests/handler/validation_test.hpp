#pragma once

#ifndef HANDLER_VALIDATION_TEST_HPP
#define HANDLER_VALIDATION_TEST_HPP

#include <string>
#include <cassert>
#include <iostream>
#include "../../src/handler/validation.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;

/**
 * @brief Validation test case
 * 
 * @struct ValidationTestCase
 */
struct ValidationTestCase {
  string input;
  bool expected_result;
  bool is_ws;
};

/**
 * @brief Run validation test
 * 
 * @return void
 */
void run_validation_test() {
  vector<ValidationTestCase> test_cases = {
    {"123", true, false},
    {"123", true, true},
    {"123 ", false, false},
    {"123 ", true, true},
    {"123a", false, false},
    {"123a", false, true},
    {"123 a", false, false},
    {"123 a", false, true},
    {"a123", false, false},
    {"a123", false, true},
    {"a123 ", false, false},
    {"a123 ", false, true},
    {"a123 b", false, false},
    {"a123 b", false, true}
  };

  for (const auto& test_case : test_cases) {
    try {
      bool result = Validation::is_data_numeric(test_case.input, test_case.is_ws);
      assert(result == test_case.expected_result);
      cout << "Test case passed: validate input " << test_case.input << '\n';
    } catch (const exception& e) {
      cerr << "Test " << test_case.input << " failed: " << e.what() << '\n';
    }
  }
}

#endif // HANDLER_VALIDATION_TEST_HPP