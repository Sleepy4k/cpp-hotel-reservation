#include <regex>
#include <string>
#include <iostream>

using namespace std;

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

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
    bool static is_data_numeric(string data, bool is_ws) {
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
    bool static is_date_valid(string date) {
      string delimiter = "/";

      string day = date.substr(0, date.find(delimiter));
      date.erase(0, date.find(delimiter) + 1);

      string month = date.substr(0, date.find(delimiter));
      date.erase(0, date.find(delimiter) + 1);

      string year = date.substr(0, date.find(delimiter));
      date.erase(0, date.find(delimiter) + 1);

      if (!is_data_numeric(day, false) || !is_data_numeric(month, false) || !is_data_numeric(year, false)) {
        return false;
      }

      if (day.length() != 2 || month.length() != 2 || year.length() != 4) {
        return false;
      }

      if (stoi(day) < 1 || stoi(day) > 31) {
        return false;
      }

      if (stoi(month) < 1 || stoi(month) > 12) {
        return false;
      }

      if (stoi(year) < 1000 || stoi(year) > 9999) {
        return false;
      }

      return true;
    }

    /**
     * @brief Validate input data for integer
     * 
     * @param min integer
     * @param max integer
     * 
     * @return int 
     */
    int static input_validation(int min, int max) {
      int choice;

      regex integer("[0-9]+");

      while (true) {
        cout << "Please Enter Your Choice : ";
        cin >> choice;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(512, '\n');
          cout << "\nPlease enter a number!!" << endl;
          continue;
        }

        if (choice >= min && choice <= max) {
          if (regex_match(to_string(choice), integer)) {
            cin.ignore(512, '\n');
            break;
          } else {
            cin.ignore(512, '\n');
            cout << "\nPlease enter a positif number!!" << endl;
          }
        } else {
          cin.ignore(512, '\n');
          cout << "\nPlease enter a number between " << min << " and " << max << "!!" << endl;
          continue;
        }
      }

      return choice;
    }
};

#endif