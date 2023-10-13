#pragma once

#ifndef STORAGE_FILE_HPP
#define STORAGE_FILE_HPP

#include <fstream>
#include <iostream>
#include "../const/app.hpp"

using std::ios;
using std::cerr;
using std::cout;
using std::endl;

/**
 * @brief File class to handle file
 * 
 * @class File
 */
struct File {
  /**
   * @brief Create file
   * 
   * @param filename string
   * 
   * @return void
   */
  static void create(const string filename) {
    using std::fstream;

    fstream outfile(filename, ios::app);

    if (!outfile) {
      outfile.close();

      if (App::APP_DEBUG) {
        cerr << "Error opening file" << endl;
      }
    }
  }

  /**
   * @brief Read file
   * 
   * @param filename string
   * 
   * @return string 
   */
  static string read(const string filename) {
    using std::ifstream;

    string line;
    string content = "";
    ifstream file(filename);

    if (!file) {
      file.close();
      create(filename);
      return content;
    }

    while (getline(file, line)) {
      content += line + "\n";
    }

    file.close();
    return content;
  }

  /**
   * @brief Write file
   * 
   * @param filename string
   * @param content string
   * 
   * @return void
   */
  static void write(const string filename, const string content) {
    using std::ofstream;

    ofstream file(filename);

    if (!file) {
      file.close();
      create(filename);
      return;
    }

    file << content;
    file.close();
  }

  /**
   * @brief Delete file
   * 
   * @param filename string
   * 
   * @return void
   */
  static void delete_file(const string filename, const bool allow_print = true) {
    int result = remove(filename.c_str());

    if (App::APP_DEBUG && allow_print) {
      (result != 0) ? cerr << "Error deleting file" << endl : cout << "File successfully deleted" << endl;
    }
  }

  /**
   * @brief Check if file exists
   * 
   * @param filename string
   * 
   * @return bool
   */
  static bool exists(const string filename) {
    using std::ifstream;

    ifstream file(filename);

    if (!file) {
      file.close();
      return false;
    }

    file.close();
    return true;
  }
};

#endif