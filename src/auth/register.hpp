#pragma once

#ifndef AUTH_REGISTER_HPP
#define AUTH_REGISTER_HPP

#include "../model/user.hpp"
#include "../helper/uuid.hpp"
#include "../handler/validation.hpp"

/**
 * @brief Register class to register the user
 * 
 * @class Register
 */
struct Register {
  /**
   * @brief Register user
   * 
   * @param role string
   * 
   * @return void
   */
  static void register_user(const string role = "user", const bool allow_title = true) {
    cout << "\n\n----------------------------------------" << endl;
    cout << "\t" << get_translated_string(App::APP_NAME) << endl;
    cout << "----------------------------------------" << endl;

    if (allow_title) cout << get_translated_string("register_title") << endl;

    string username = Validation::string_validation(get_translated_string("register_input_username"), "username");
    
    User user;
    User data = user.find(username);

    if (data.get_uid() != "") {
      cout << get_translated_string("model_user_already_exist") << endl;
      return register_user();
    }
    
    string password = Validation::string_validation(get_translated_string("register_input_password"), "password");
    string confirm_password = Validation::string_validation(get_translated_string("register_input_confirm_password"), "password");

    if (password != confirm_password) {
      cout << get_translated_string("register_input_password_not_same") << endl;
      return register_user();
    }

    data.set_uid(UUID::generate_uuid());
    data.set_role(role);
    data.set_username(username);
    data.set_password(Hash::encrypt(password));
    Forgot::create_forgot_question(data, allow_title);
  };
};

#endif // AUTH_REGISTER_HPP