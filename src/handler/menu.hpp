#pragma once

#ifndef HANDLER_MENU_HPP
#define HANDLER_MENU_HPP

#include "validation.hpp"
#include "../const/app.hpp"
#include "../auth/login.hpp"
#include "../auth/register.hpp"
#include "../const/menu_list.hpp"

/**
 * @brief Menu class to show the menu list to the user
 * 
 * @class Menu
 */
struct Menu {
  /**
   * @brief Show the main menu list to the user
   * 
   * @return void
   */
  static void init() {
    vector<string> menu_list = MenuList::MAIN_MENU;

    while (true) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("menu_list_main_welcome") << endl;

      for (unsigned int i = 0; i < menu_list.size(); i++) {
        cout << get_translated_string("menu_list_main_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
      }

      int menu = Validation::integer_validation(1, menu_list.size());

      switch (menu) {
        case 1: Login::login(true);
          break;
        case 2: Login::login(false);
          break;
        case 3: Register::register_user();
          break;
        case 4: Forgot::forgot_password();
          break;
        case 5: cout << get_translated_string("menu_list_main_thanks") << " " << get_translated_string(App::APP_NAME) << endl;
          exit(0);
          break;
        default: cout << get_translated_string("menu_list_main_invalid") << endl;
          break;
      }
    }
  }
};

#endif // HANDLER_MENU_HPP