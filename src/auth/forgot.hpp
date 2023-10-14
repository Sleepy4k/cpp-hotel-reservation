#pragma once

#ifndef AUTH_FORGOT_HPP
#define AUTH_FORGOT_HPP

#include "../model/user.hpp"
#include "../helper/uuid.hpp"
#include "../const/menu_list.hpp"
#include "../handler/validation.hpp"

/**
 * @brief Forgot class to forgot the password
 * 
 * @class Forgot
 */
struct Forgot {
  /**
   * @brief Create forgot question
   * 
   * @param user User
   * 
   * @return void
   */
  static void create_forgot_question(User user, const bool allow_title = true) {
    vector<string> menu_list = MenuList::FORGOT_MENU;

    cout << "\n\n----------------------------------------" << endl;
    cout << "\t" << get_translated_string(App::APP_NAME) << endl;
    cout << "----------------------------------------" << endl;

    if (allow_title) cout << get_translated_string("forgot_create_title") << endl;

    for (unsigned int i = 0; i < menu_list.size(); i++) {
      cout << get_translated_string("forgot_create_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
    }

    int menu = Validation::integer_validation(1, menu_list.size());
    string answer = Validation::string_validation(get_translated_string("forgot_create_input_answer"), "forgot_answer");
    answer = Hash::encrypt(answer);
    user.set_forgot_answer(answer);

    switch (menu) {
      case 1: user.set_forgot_question_id(1);
        break;
      case 2: user.set_forgot_question_id(2);
        break;
      case 3: user.set_forgot_question_id(3);
        break;
      case 4: user.set_forgot_question_id(4);
        break;
      default:
        cout << get_translated_string("forgot_create_invalid_menu") << endl;
        break;
    }

    user.create();
  };

  /**
   * @brief Validate forgot question
   * 
   * @param user User
   * 
   * @return void
   */
  static void validate_forgot_question(User user) {
    cout << "\n\n----------------------------------------" << endl;
    cout << "\t" << get_translated_string(App::APP_NAME) << endl;
    cout << "----------------------------------------" << endl;
    cout << get_translated_string("forgot_validate_title") << endl;

    switch (user.get_forgot_question_id()) {
      case 1: cout << get_translated_string("menu_list_forgot_pet") << endl;
        break;
      case 2: cout << get_translated_string("menu_list_forgot_color") << endl;
        break;
      case 3: cout << get_translated_string("menu_list_forgot_food") << endl;
        break;
      case 4: cout << get_translated_string("menu_list_forgot_person") << endl;
        break;
    } 

    string answer = Validation::string_validation(get_translated_string("forgot_validate_input_answer"), "forgot_answer");

    if (!Hash::verify(answer, user.get_forgot_answer())) {
      cout << get_translated_string("forgot_validate_input_password_invalid") << endl;
      return validate_forgot_question(user);
    }

    string password = Validation::string_validation(get_translated_string("forgot_validate_input_password"), "password");
    string confirm_password = Validation::string_validation(get_translated_string("forgot_validate_input_confirm_password"), "password");

    if (password != confirm_password) {
      cout << get_translated_string("forgot_validate_input_password_not_same") << endl;
      return validate_forgot_question(user);
    }

    if (Hash::verify(password, user.get_password())) {
      cout << get_translated_string("forgot_validate_input_password_must_be_different") << endl;
      validate_forgot_question(user);
    } else {
      user.update(user.get_username(), user.get_password(), Hash::encrypt(password));
    }
  };

  /**
   * @brief Forgot password
   * 
   * @return void
   */
  static void forgot_password() {
    cout << "\n\n----------------------------------------" << endl;
    cout << "\t" << get_translated_string(App::APP_NAME) << endl;
    cout << "----------------------------------------" << endl;
    cout << get_translated_string("forgot_title") << endl;

    string username = Validation::string_validation(get_translated_string("forgot_input_username"), "username");
    User user = user.find(username);
    validate_forgot_question(user);
  };
};

#endif // AUTH_FORGOT_HPP