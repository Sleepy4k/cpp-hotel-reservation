#pragma once

#ifndef HANDLER_SPRINTF_HPP
#define HANDLER_SPRINTF_HPP

#include <sstream>

using std::vector;

/**
 * @brief Sprintf class to format the string
 * 
 * @class Sprintf
 */
struct Sprintf {
  /**
   * @brief Format the string
   * 
   * @param format string
   * @param args vector<string>
   * 
   * @return string
   */
  static string format(const string format, const vector<string> args = {}) {
    using std::stringstream;

    unsigned int i = 0;
    unsigned int j = 0;
    stringstream result;

    while (i < format.length()) {
      if (format[i] == '%') {
        if (j < args.size()) {
          result << args[j];
          j++;
        } else {
          result << "";
        }
      } else {
        result << format[i];
      }

      i++;
    }

    return result.str();
  }
};

#endif // HANDLER_SPRINTF_HPP