#pragma once

#ifndef CONTROLLER_ADMIN_USER_HPP
#define CONTROLLER_ADMIN_USER_HPP

#include "../../const/app.hpp"
#include "../../helper/getky.hpp"
#include "../../auth/register.hpp"
#include "../../const/menu_list.hpp"

/**
 * @brief AdminUserDashboard class to handle admin user dashboard
 * 
 * @class AdminUserDashboard
 */
class AdminUserDashboard {
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
      cout << get_translated_string("admin_user_list_title") << endl;

      int totalUsers = users.size();

      if (totalUsers > 0) {
        int totalAdmin = 0;

        for (int i = 0; i < totalUsers; i++) {
          if (users[i].get_role() == "admin") {
            totalAdmin++;
            continue;
          }

          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("admin_user_list_data_uid"), {users[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_user_list_data_role"), {users[i].get_role()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_user_list_data_username"), {users[i].get_username()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }

        cout << '\n' << Sprintf::format(get_translated_string("admin_user_list_header"), {to_string(totalUsers - totalAdmin)}) << endl;
      } else {
        cout << get_translated_string("admin_user_list_empty") << endl;
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
      cout << get_translated_string("admin_user_search_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_user_input_username"), "username");
      User data = user.find(username);

      if (data.get_uid() == "" || data.get_role() == "admin") {
        cout << Sprintf::format(get_translated_string("admin_user_not_found"), {username}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_role"), {data.get_role()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_username"), {data.get_username()}) << '\n';
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
      cout << get_translated_string("admin_user_edit_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_user_input_username"), "username");
      User data = user.find(username);

      if (data.get_uid() == "" || data.get_role() == "admin") {
        cout << Sprintf::format(get_translated_string("admin_user_not_found"), {username}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_role"), {data.get_role()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_user_list_data_username"), {data.get_username()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      string role = Validation::string_validation(get_translated_string("admin_user_input_role"), "role");

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
      cout << get_translated_string("admin_user_delete_title") << endl;

      string username = Validation::string_validation(get_translated_string("admin_user_input_username"), "username");
      User data = user.find(username);

      if (data.get_role() == "admin") {
        cout << Sprintf::format(get_translated_string("admin_user_not_found"), {username}) << endl;
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
      vector<string> menu_list = MenuList::ADMIN_USER_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_user_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: list(user);
            break;
          case 2: Register::register_user("user", false);
            break;
          case 3: search(user);
            break;
          case 4: edit(user);
            break;
          case 5: destroy(user);
            break;
          case 6: return;
            break;
          default: cout << get_translated_string("menu_list_admin_user_invalid") << endl;
            break;
        }
      }
    }
};

#endif // CONTROLLER_ADMIN_USER_HPP