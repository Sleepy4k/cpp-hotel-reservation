#pragma once

#ifndef HELPER_UUID_TEST_HPP
#define HELPER_UUID_TEST_HPP

#include <string>
#include <cassert>
#include <iostream>
#include "../../src/helper/uuid.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;

/**
 * @brief Run uuid test
 * 
 * @return void
 */
void run_uuid_test() {
  for (unsigned i = 0; i < 10; i++) {
    try {
      string uuid = UUID::generate_uuid();
      assert(uuid.length() >= 8);
      assert(uuid.length() <= 13);
      cout << "Test case passed: generate id " << uuid << endl;
    } catch (const exception& e) {
      cerr << "Test failed: " << e.what() << endl;
    }
  }
}

#endif // HELPER_UUID_TEST_HPP