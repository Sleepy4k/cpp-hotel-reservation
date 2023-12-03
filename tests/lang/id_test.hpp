#pragma once

#ifndef ID_TEST_HPP
#define ID_TEST_HPP

#include <cassert>
#include <iostream>
#include "../../src/lang/id.hpp"

using std::cerr;
using std::endl;
using std::exception;

/**
 * @brief Check if translation is duplicated
 * 
 * @return void
 */
void run_id_translate_test() {
  try {
    bool is_duplicated = check_id_translate_duplicated();
    assert(!is_duplicated);
  } catch (exception& e) {
    cerr << "Test failed: " << e.what() << endl;
  }
}

#endif // ID_TEST_HPP