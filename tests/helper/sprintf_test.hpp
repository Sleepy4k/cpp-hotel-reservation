#pragma once

#ifndef HELPER_SPRINTF_TEST_HPP
#define HELPER_SPRINTF_TEST_HPP

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "../../src/helper/sprintf.hpp"

using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::exception;

/**
 * @brief Sprintf test case
 * 
 * @struct SprintfTestCase
 */
struct SprintfTestCase {
  string format_str;
  vector<string> args;
  string expected_result;
};

/**
 * @brief Run sprintf test
 * 
 * @return void
 */
void run_sprintf_test() {
  vector<SprintfTestCase> test_cases = {
    {"Hello %", {"World"}, "Hello World"},
    {"Hello % %", {"World", "Again"}, "Hello World Again"},
    {"Hello World", {}, "Hello World"},
    {"Hello %", {}, "Hello "}
  };

  for (const auto& test_case : test_cases) {
    try {
      string result = Sprintf::format(test_case.format_str, test_case.args);
      assert(result == test_case.expected_result);
      cout << "Test case passed: format string " << result << '\n';
    } catch (const exception& e) {
      cerr << "Test " << test_case.format_str << " failed: " << e.what() << '\n';
    }
  }
}

#endif // HELPER_SPRINTF_TEST_HPP