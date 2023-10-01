#include <regex>
#include <limits>
#include <iostream>
#include "../handler/i18n.hpp"
#include "../helper/sprintf.hpp"

using namespace std;

#ifndef HANDLER_VALIDATION_HPP
#define HANDLER_VALIDATION_HPP

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
        for (int i = 0; i < data.length(); i++) {
          if (!isdigit(data[i]) && !isspace(data[i])) {
            return false;
          }
        }
      } else {
        for (int i = 0; i < data.length(); i++) {
          if (!isdigit(data[i])) {
            return false;
          }
        }
      }

      return true;
    }

    /**
     * @brief Check if the date is valid or not
     * 
     * @param date string
     * 
     * @return true 
     * @return false 
     */
    static bool is_date_valid(string date) {
      regex datePattern("^\\d{2}/\\d{2}/\\d{4}$");

      if (!regex_match(date, datePattern)) {
        return false;
      }

      smatch match;
      regex_search(date, match, datePattern);

      int day = stoi(match.str(1));
      int month = stoi(match.str(2));
      int year = stoi(match.str(3));

      if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) {
        return false;
      }

      return true;
    }

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
    }

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
    }
};

#endif