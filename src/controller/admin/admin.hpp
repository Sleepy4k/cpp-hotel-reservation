#pragma once

#ifndef CONTROLLER_ADMIN_ADMIN_HPP
#define CONTROLLER_ADMIN_ADMIN_HPP

#include "../../const/app.hpp"
#include "../../helper/getky.hpp"
#include "../../auth/register.hpp"
#include "../../const/menu_list.hpp"

/**
 * @brief AdminAdminDashboard class to handle admin admin dashboard
 * 
 * @class AdminAdminDashboard
 */
class AdminAdminDashboard {
  public:
    /**
     * @brief List all users
     * 
     * @param user User
     * 
     * @return void
    */
    static void list(User user) {
      using std::to_string;

      vector<User> users = user.get();

      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_admin_list_title") << endl;

      int totalAdmins = users.size();

      if (totalAdmins > 0) {
        int totalUser = 0;

        for (int i = 0; i < totalAdmins; i++) {
          if (users[i].get_role() == "user") {
            totalUser++;
            continue;
          }

          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("admin_admin_list_data_uid"), {users[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_admin_list_data_role"), {users[i].get_role()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_admin_list_data_username"), {users[i].get_username()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }

        cout << '\n' << Sprintf::format(get_translated_string("admin_admin_list_header"), {to_string(totalAdmins - totalUser)}) << endl;
      } else {
        cout << get_translated_string("admin_admin_list_empty") << endl;
      }

      Getky::pause();
    }

    /**
     * @brief Search user by username
     * 
     * @param user User
     * 
     * @return void
    */
    static void search(User user) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_admin_search_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_admin_input_username"), "username");
      User data = user.find(username);

      if (data.get_uid() == "" || data.get_role() == "user") {
        cout << Sprintf::format(get_translated_string("admin_admin_not_found"), {username}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_role"), {data.get_role()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_username"), {data.get_username()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      Getky::pause();
    }

    /**
     * @brief Edit user by username
     * 
     * @param user User
     * 
     * @return void
    */
    static void edit(User user) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_admin_edit_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_admin_input_username"), "username");
      User data = user.find(username);

      if (data.get_uid() == "" || data.get_role() == "user" || data.get_username() == user.get_username()) {
        cout << Sprintf::format(get_translated_string("admin_admin_not_found"), {username}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_role"), {data.get_role()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_admin_list_data_username"), {data.get_username()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      string role = Validation::string_validation(get_translated_string("admin_admin_input_role"), "role");

      if (role == "admin" || role == "user" || role == "pengguna") {
        (role == "pengguna") ? role = "user" : role = role;
        user.update_role(username, role);
      } else {
        cout << get_translated_string("admin_user_edit_invalid") << endl;
      }
    }

    /**
     * @brief Delete user by username
     * 
     * @param user User
     * 
     * @return void
    */
    static void destroy(User user) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_admin_delete_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_admin_input_username"), "username");
      User data = user.find(username);

      if (data.get_role() == "user" || data.get_username() == user.get_username()) {
        cout << Sprintf::format(get_translated_string("admin_admin_not_found"), {username}) << endl;
        return;
      }

      user.delete_user(username);
    }

    /**
     * @brief Dashboard for admin user
     * 
     * @param user User
     * 
     * @return void
    */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::ADMIN_ADMIN_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_admin_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_admin_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: list(user);
            break;
          case 2: Register::register_user("admin", false);
            break;
          case 3: search(user);
            break;
          case 4: edit(user);
            break;
          case 5: destroy(user);
            break;
          case 6: return;
            break;
          default: cout << get_translated_string("menu_list_admin_admin_invalid") << endl;
            break;
        }
      }
    }
};

#endif // CONTROLLER_ADMIN_ADMIN_HPP