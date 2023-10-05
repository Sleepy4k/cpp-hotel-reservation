#pragma once

#ifndef HANDLER_HASH_TEST_HPP
#define HANDLER_HASH_TEST_HPP

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "../../src/handler/hash.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::exception;

/**
 * @brief Run hash test
 * 
 * @return void
 */
void run_hash_test() {
  vector<string> test_cases = {
    "Hello World",
    "Hello World Again",
    "Hello World Again And Again"
  };

  for (const auto& test_case : test_cases) {
    try {
      string result = Hash::encrypt(test_case);
      assert(Hash::verify(test_case, result) == true);
      cout << "Test case passed: generate hash " << result << endl;
    } catch (const exception& e) {
      cerr << "Test " << test_case << " failed: " << e.what() << endl;
    }
  }
}

#endif // HANDLER_HASH_TEST_HPP