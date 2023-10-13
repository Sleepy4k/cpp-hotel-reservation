#pragma once

#ifndef CONTROLLER_USER_PROFILE_HPP
#define CONTROLLER_USER_PROFILE_HPP

#include "../../const/app.hpp"
#include "../../model/user.hpp"
#include "../../auth/forgot.hpp"
#include "../../const/menu_list.hpp"
#include "../../handler/validation.hpp"

/**
 * @brief UserProfileDashboard class to handle user profile dashboard
 * 
 * @class UserProfileDashboard
 */
class UserProfileDashboard {
  public:
    /**
     * @brief Dashboard function to show user profile dashboard
     * 
     * @param user 
     */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::USER_PROFILE_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_user_profile_title"), {user.get_username()}) << endl;
      
        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_user_profile_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: Forgot::validate_forgot_question(user);
            break;
          case 2: return;
            break;
          default: cout << get_translated_string("menu_list_user_profile_invalid") << endl;
            break;
        }
      }
    };
};

#endif // CONTROLLER_USER_PROFILE_HPP