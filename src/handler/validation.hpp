#pragma once

#ifndef HANDLER_VALIDATION_HPP
#define HANDLER_VALIDATION_HPP

#include <regex>
#include <limits>
#include <iostream>
#include "../handler/i18n.hpp"
#include "../helper/sprintf.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::getline;
using std::to_string;
using std::streamsize;
using std::numeric_limits;

/**
 * @brief Validation class to validate the data
 * 
 * @class Validation
 */
class Validation {
  public:
    /**
     * @brief Check if the data is numeric or not
     * 
     * @param data string
     * @param is_ws boolean
     * 
     * @return true 
     * @return false 
     */
    static bool is_data_numeric(string data, bool is_ws) {
      if (is_ws) {
        for (unsigned int i = 0; i < data.length(); i++) {
          if (!isdigit(data[i]) && !isspace(data[i])) {
            return false;
          }
        }
      } else {
        for (unsigned int i = 0; i < data.length(); i++) {
          if (!isdigit(data[i])) {
            return false;
          }
        }
      }

      return true;
    };

    /**
     * @brief Validate the input data for integer type
     * 
     * @param min integer
     * @param max integer
     * 
     * @return int 
     */
    static int integer_validation(int min, int max) {
      int choice;

      while (true) {
        cout << get_translated_string("validation_integer_input");

        if (!(cin >> choice)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "\n" << get_translated_string("validation_integer_invalid") << endl;
        } else if (choice < min || choice > max) {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "\n" << Sprintf::format(get_translated_string("validation_integer_between"), {to_string(min), to_string(max)}) << endl;
        } else {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          return choice;
        }
      }
    };

    /**
     * @brief Validate the input data for string type
     * 
     * @param prompt string
     * @param validationType string
     * 
     * @return string 
     */
    static string string_validation(const string& prompt, const string validationType) {
      string data;

      regex validationRegex;
      if (validationType == "username") {
        validationRegex = "^[a-zA-Z0-9_]{5,}$";
      } else if (validationType == "password") {
        validationRegex = "^[a-zA-Z0-9_]{6,}$";
      } else if (validationType == "confirmation") {
        validationRegex = "^[yn]$";
      } else if (validationType == "date") {
        validationRegex = "^\\d{2}/\\d{2}/\\d{4}$";
      } else if (validationType == "forgot_answer") {
        validationRegex = "^[a-zA-Z0-9_]{1,}$";
      } else {
        validationRegex = "^[a-zA-Z0-9_]{1,}$";
      }

      while (true) {
        cout << prompt;
        getline(cin, data);

        if (regex_match(data, validationRegex)) {
          return data;
        } else {
          cout << "\n" << get_translated_string("validation_string_invalid") << endl;
        }
      }
    };
};

#endif // HANDLER_VALIDATION_HPP