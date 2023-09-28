#include <string>
#include <iostream>

using namespace std;

#ifndef CONST_PATH_HPP
#define CONST_PATH_HPP

string basepath = __FILE__;

/**
 * @brief Path constant for the application
 * 
 * @namespace Path
 */
namespace Path {
  /**
   * @brief Get the Path object
   * 
   * @return const string 
   */
  const string getPath() {
    return basepath;
  }

  /**
   * @brief Set the Path object
   * 
   * @param path string
   * 
   * @return void
   */
  const void setPath(string path) {
    size_t lastBackslashPos = path.find_last_of("\\/");

    if (lastBackslashPos != std::string::npos) {
      path = path.substr(0, lastBackslashPos);
    }

    basepath = path;
  }
};

#endif