#pragma once

#ifndef AUTH_LOGIN_HPP
#define AUTH_LOGIN_HPP

#include "forgot.hpp"
#include "../dashboard/user.hpp"
#include "../dashboard/admin.hpp"
#include "../handler/validation.hpp"

/**
 * @brief Login class to login the user
 * 
 * @class Login
 */
struct Login {
  /**
   * @brief Confirm forgot password
   * 
   * @param is_admin bool
   * 
   * @return void
   */
  static void confirm(const bool is_admin) {
    cout << get_translated_string("login_confirm_question") << endl;
    string confirmation = Validation::string_validation(get_translated_string("login_confirm_input_confirm"), "confirmation");

    if (confirmation == "y") {
      Forgot::forgot_password();
    } else if (confirmation == "n" || confirmation == "t") {
      login(is_admin);
    } else {
      cout << get_translated_string("login_confirm_input_invalid") << endl;
      confirm(is_admin);
    }
  };

  /**
   * @brief Login user
   * 
   * @param is_admin bool
   * @param error int
   * 
   * @return void
   */
  static void login(const bool is_admin, const int error = 0) {
    cout << "\n\n----------------------------------------" << endl;
    cout << "\t" << get_translated_string(App::APP_NAME) << endl;
    cout << "----------------------------------------" << endl;
    cout << get_translated_string("login_title") << endl;

    string username = Validation::string_validation(get_translated_string("login_input_username"), "username");
    User user = user.find(username);

    if (user.get_uid() == "") {
      cout << get_translated_string("login_invalid_username") << endl;
      return login(is_admin);
    }

    string password = Validation::string_validation(get_translated_string("login_input_password"), "password");

    if (!Hash::verify(password, user.get_password())) {
      cout << get_translated_string("login_invalid_password") << endl;
      return (error < 2) ? login(is_admin, error + 1) : confirm(is_admin);
    }

    bool isAdmin = (user.get_role() == "admin");

    if (is_admin && isAdmin) {
      AdminDashboard::dashboard(user);
    } else if (!is_admin && !isAdmin) {
      UserDashboard::dashboard(user);
    } else {
      cout << get_translated_string("login_not_admin") << endl;
      login(is_admin);
    }
  };
};

#endif // AUTH_LOGIN_HPP