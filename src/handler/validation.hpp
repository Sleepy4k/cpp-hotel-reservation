#include <regex>
#include <string>
#include <iostream>

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

    /**
     * @brief Validate the input data for string type
     * 
     * @param type string
     * 
     * @return string 
     */
    static string string_validation(string type) {
      string data;

      if (type == "username") {
        regex username("^[a-zA-Z0-9]{5,}$");

        while (true) {
          cout << "Please Enter Your Username : ";
          getline(cin, data);

          if (regex_match(data, username)) {
            break;
          } else {
            cout << "\nPlease enter a valid username!!" << endl;
            continue;
          }
        }
      } else if (type == "password") {
        regex password("^[a-zA-Z0-9]{8,}$");

        while (true) {
          cout << "Please Enter Your Password : ";
          getline(cin, data);

          if (regex_match(data, password)) {
            break;
          } else {
            cout << "\nPlease enter a valid password!!" << endl;
            continue;
          }
        }
      } else if (type == "password_confirmation") {
        regex password("^[a-zA-Z0-9]{8,}$");

        while (true) {
          cout << "Please Enter Your Password Confirmation : ";
          getline(cin, data);

          if (regex_match(data, password)) {
            break;
          } else {
            cout << "\nPlease enter a valid password confirmation!!" << endl;
            continue;
          }
        }
      } else if (type == "date") {
        while (true) {
          cout << "Please Enter Your Date (dd/mm/yyyy) : ";
          getline(cin, data);

          if (is_date_valid(data)) {
            break;
          } else {
            cout << "\nPlease enter a valid date!!" << endl;
            continue;
          }
        }
      } else {
        while (true) {
          cout << "Please Enter Your " << type << " : ";
          getline(cin, data);

          if (data.length() > 0) {
            break;
          } else {
            cout << "\nPlease enter a valid " << type << "!!" << endl;
            continue;
          }
        }
      }

      return data;
    }
};

#endif