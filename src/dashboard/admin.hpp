#pragma once

#ifndef DASHBOARD_ADMIN_HPP
#define DASHBOARD_ADMIN_HPP

#include "../controller/admin/room.hpp"
#include "../controller/admin/user.hpp"
#include "../controller/admin/admin.hpp"
#include "../controller/admin/system.hpp"

/**
 * @brief AdminDashboard class to handle admin dashboard
 * 
 * @class AdminDashboard
 */
class AdminDashboard {
  public:
    /**
     * @brief Show the admin dashboard
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::ADMIN_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n--------------------------------------------------------------------" << endl;
        cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: AdminRoomDashboard::dashboard(user);
            break;
          case 2: AdminUserDashboard::dashboard(user);
            break;
          case 3: cout << get_translated_string("menu_list_admin_manage_booking") << endl;
            break;
          case 4: AdminAdminDashboard::dashboard(user);
            break;
          case 5: cout << get_translated_string("menu_list_admin_report_and_statistic") << endl;
            break;
          case 6: AdminSystemDashboard::dashboard(user);
            break;
          case 7: return;
            break;
          default: cout << get_translated_string("menu_list_admin_invalid") << endl;
            break;
        }
      }
    };
};

#endif // DASHBOARD_ADMIN_HPP