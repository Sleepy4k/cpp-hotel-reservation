#pragma once

#ifndef EN_TEST_HPP
#define EN_TEST_HPP

#include <cassert>
#include <iostream>
#include "../../src/lang/en.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::exception;

/**
 * @brief Check if translation is duplicated
 * 
 * @return void
 */
void run_en_translate_test() {
  try {
    bool is_duplicated = check_en_translate_duplicated();
    assert(!is_duplicated);
  } catch (exception& e) {
    cerr << "Test failed: " << e.what() << endl;
  }
}

#endif // EN_TEST_HPP