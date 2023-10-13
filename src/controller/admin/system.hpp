#pragma once

#ifndef CONTROLLER_ADMIN_SYSTEM_HPP
#define CONTROLLER_ADMIN_SYSTEM_HPP

#include "../../const/app.hpp"
#include "../../model/user.hpp"
#include "../../const/menu_list.hpp"
#include "../../handler/validation.hpp"

/**
 * @brief AdminSystemDashboard class to handle admin system dashboard
 * 
 * @class AdminSystemDashboard
 */
class AdminSystemDashboard {
  public:
    /**
     * @brief Set the language
     * 
     * @param language Language
     * 
     * @return void
     */
    static void manage_language() {
      string language = Validation::string_validation(get_translated_string("admin_system_input_language"), "language");

      if (language == "en") {
        set_language(Language::ENGLISH);
      } else if (language == "id") {
        set_language(Language::INDONESIA);
      } else {
        cout << get_translated_string("admin_system_invalid_language") << endl;
      }
    };

    /**
     * @brief Set the debug
     * 
     * @param debug Debug
     * 
     * @return void
     */
    static void manage_debug() {
      string debug = Validation::string_validation(get_translated_string("admin_system_input_debug"), "debug");

      if (debug == "true" || debug == "ya") {
        App::set_debug(true);
      } else if (debug == "false" || debug == "tidak") {
        App::set_debug(false);
      } else {
        cout << get_translated_string("admin_system_invalid_debug") << endl;
      }
    };

    /**
     * @brief Show the admin system dashboard
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::ADMIN_SYSTEM_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_system_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_system_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: manage_language();
            break;
          case 2: manage_debug();
            break;
          case 3: return;
            break;
          default: cout << get_translated_string("menu_list_admin_system_invalid") << endl;
            break;
        }
      }
    };
};

#endif // CONTROLLER_ADMIN_SYSTEM_HPP