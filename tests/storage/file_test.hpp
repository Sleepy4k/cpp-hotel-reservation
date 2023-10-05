#pragma once

#ifndef STORAGE_FILE_TEST_HPP
#define STORAGE_FILE_TEST_HPP

#include <string>
#include <cassert>
#include <iostream>
#include "../../src/const/path.hpp"
#include "../../src/storage/file.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;

/**
 * @brief Create a file test object
 * 
 * @param filename string
 * 
 * @return void
 */
void create_file_test(const string filename) {
  try {
    File::create(filename);
    cout << "Test case passed: create file " << filename << endl;
  } catch (exception& e) {
    cerr << "Test " << filename << " failed: " << e.what() << endl;
  }
}

/**
 * @brief Write a file test object
 * 
 * @param filename string
 * @param content string
 * 
 * @return void
 */
void write_file_test(const string filename, const string content) {
  try {
    File::write(filename, content);
    cout << "Test case passed: write file " << filename << endl;
  } catch (exception& e) {
    cerr << "Test " << filename << " failed: " << e.what() << endl;
  }
}

/**
 * @brief Read a file test object
 * 
 * @param filename string
 * 
 * @return string
 */
string read_file_test(const string filename) {
  try {
    string content = File::read(filename);
    content = content.substr(0, content.size() - 1);
    cout << "Test case passed: read file " << filename << endl;
    return content;
  } catch (exception& e) {
    cerr << "Test " << filename << " failed: " << e.what() << endl;
    return "";
  }
}

/**
 * @brief Delete a file test object
 * 
 * @param filename string
 * 
 * @return void
 */
void delete_file_test(const string filename) {
  try {
    File::delete_file(filename, false);
    cout << "Test case passed: delete file " << filename << endl;
  } catch (exception& e) {
    cerr << "Test " << filename << " failed: " << e.what() << endl;
  }
}

/**
 * @brief Run file test
 * 
 * @return void
 */
void run_file_test() {
  string filename = Path::getPath() + "/test.txt";
  string content = "Hello World";

  create_file_test(filename);
  write_file_test(filename, content);
  string result = read_file_test(filename);
  delete_file_test(filename);

  assert(result == content);
  cout << "Test case passed: match file with data " << result << endl;
}

#endif // STORAGE_FILE_TEST_HPP