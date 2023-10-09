#pragma once

#ifndef HANDLER_I18N_TEST_HPP
#define HANDLER_I18N_TEST_HPP

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "../../src/handler/i18n.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::exception;

/**
 * @brief Run i18n test
 * 
 * @return void
 */
void run_i18n_test() {
  vector<Language> test_cases = {
    Language::ENGLISH,
    Language::INDONESIA
  };

  for (const auto& test_case : test_cases) {
    try {
      set_language(test_case);
      assert(supported_language == test_case);
      cout << "Test case passed: set language to " << (test_case == Language::ENGLISH ? "ENGLISH" : "INDONESIA") << endl;
    } catch (const exception& e) {
      cerr << "Test " << (test_case == Language::ENGLISH ? "ENGLISH" : "INDONESIA") << " failed: " << e.what() << endl;
    }
  }
};

#endif // HANDLER_I18N_TEST_HPP