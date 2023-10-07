#pragma once

#ifndef CONTROLLER_ADMIN_USER_HPP
#define CONTROLLER_ADMIN_USER_HPP

#include "../../const/app.hpp"
#include "../../model/user.hpp"
#include "../../const/menu_list.hpp"
#include "../../handler/validation.hpp"

class AdminUserDashboard {
  public:
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::ADMIN_USER_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n--------------------------------------------------------------------" << endl;
        cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_user_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1:
            cout << get_translated_string("menu_list_admin_user_list");
            break;
          case 2:
            cout << get_translated_string("menu_list_admin_user_add"); 
            break;
          case 3:
            cout << get_translated_string("menu_list_admin_user_search");
            break;
          case 4:
            cout << get_translated_string("menu_list_admin_user_edit");
            break;
          case 5:
            cout << get_translated_string("menu_list_admin_user_delete");
            break;
          case 6:
            return;
            break;
          default:
            cout << get_translated_string("menu_list_admin_user_invalid") << endl;
            break;
        }
      }
    }
}

#endif // CONTROLLER_ADMIN_USER_HPP