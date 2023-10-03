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
class Register {
  public:
    /**
     * @brief Register user
     * 
     * @param role string
     * 
     * @return void
     */
    static void register_user(string role = "user") {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("register_title") << endl;

      string username = Validation::string_validation(get_translated_string("register_input_username"), "username");
      string password = Validation::string_validation(get_translated_string("register_input_password"), "password");
      string confirm_password = Validation::string_validation(get_translated_string("register_input_confirm_password"), "password");

      if (password != confirm_password) {
        cout << get_translated_string("register_input_password_not_same") << endl;
        register_user();
      } else {
        User user;
        user.set_uid(UUID::generate_uuid());
        user.set_role(role);
        user.set_username(username);
        user.set_password(Hash::encrypt(password));

        Forgot::create_forgot_question(user);
      }
    };
};

#endif // AUTH_REGISTER_HPP