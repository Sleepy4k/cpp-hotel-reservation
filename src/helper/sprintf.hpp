#pragma once

#ifndef HANDLER_SPRINTF_HPP
#define HANDLER_SPRINTF_HPP

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Sprintf class to format the string
 * 
 * @class Sprintf
 */
class Sprintf {
  public:
    /**
     * @brief Format the string
     * 
     * @param format string
     * @param args vector<string>
     * 
     * @return string
     */
    static string format(const string& format, const vector<string>& args) {
      int i = 0;
      int j = 0;
      string result = "";

      while (i < format.length()) {
        if (format[i] == '%') {
          if (j < args.size()) {
            result += args[j];
            j++;
          } else {
            result += "";
          }
        } else {
          result += format[i];
        }

        i++;
      }

      return result;
    };
};

#endif // HANDLER_SPRINTF_HPP