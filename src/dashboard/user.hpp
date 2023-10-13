#pragma once

#ifndef DASHBOARD_USER_HPP
#define DASHBOARD_USER_HPP

#include "../controller/user/room.hpp"
#include "../controller/user/profile.hpp"

/**
 * @brief UserDashboard class to handle user dashboard
 * 
 * @class UserDashboard
 */
class UserDashboard {
  public:
    /**
     * @brief Show the user dashboard
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::USER_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_user_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_user_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: UserRoomDashboard::dashboard(user);
            break;
          case 2: cout << get_translated_string("menu_list_user_booking_room") << endl;
            break;
          case 3: cout << get_translated_string("menu_list_user_booking_history") << endl;
            break;
          case 4: UserProfileDashboard::dashboard(user);
            break;
          case 5: return;
            break;
          default: cout << get_translated_string("menu_list_user_invalid") << endl;
            break;
        }
      }
    };
};

#endif // DASHBOARD_USER_HPP