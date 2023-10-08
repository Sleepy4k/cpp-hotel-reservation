#pragma once

#ifndef CONTROLLER_ADMIN_USER_HPP
#define CONTROLLER_ADMIN_USER_HPP

#include "../../const/app.hpp"
#include "../../helper/getky.hpp"
#include "../../auth/register.hpp"
#include "../../const/menu_list.hpp"

class AdminUserDashboard {
  public:
    /**
     * @brief List all users
     * 
     * @return void
    */
    static void list(User user) {
      vector<User> users = user.get();

      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("menu_list_admin_user_list") << endl;

      int totalUsers = users.size();

      if (totalUsers > 0) {
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_title"), {to_string(totalUsers)}) << endl;

        for (unsigned int i = 0; i < totalUsers; i++) {
          if (users[i].get_role() == "admin") {
            continue;
          }

          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_uid"), {users[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_username"), {users[i].get_username()}) << '\n';
          cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_role"), {users[i].get_role()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }
      } else {
        cout << get_translated_string("menu_list_admin_user_list_empty") << endl;
      }

      Getky::pause();
    }

    /**
     * @brief Search user by username
     * 
     * @return void
    */
    static void search(User user) {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("menu_list_admin_user_search") << endl;

      string username = Validation::string_validation(get_translated_string("menu_list_admin_user_search_input_username"), "username");

      User data = user.find(username);

      if (data.get_uid() != "" && data.get_role() != "admin") {
        cout << "\n--------------------------------------------------------" << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_uid"), {data.get_uid()}) << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_username"), {data.get_username()}) << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_role"), {data.get_role()}) << '\n';
        cout << "--------------------------------------------------------" << '\n';
      } else {
        cout << get_translated_string("menu_list_admin_user_search_not_found") << endl;
      }
    }

    /**
     * @brief Edit user by username
     * 
     * @return void
    */
    static void edit() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("menu_list_admin_user_edit") << endl;

      string username = Validation::string_validation(get_translated_string("menu_list_admin_user_edit_input_username"), "username");

      User user;
      User data = user.find(username);

      if (data.get_uid() != "" && data.get_role() != "admin") {
        cout << "\n--------------------------------------------------------" << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_uid"), {data.get_uid()}) << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_username"), {data.get_username()}) << '\n';
        cout << Sprintf::format(get_translated_string("menu_list_admin_user_list_data_role"), {data.get_role()}) << '\n';
        cout << "--------------------------------------------------------" << '\n';
      } else {
        cout << get_translated_string("menu_list_admin_user_edit_not_found") << endl;
        return;
      }

      string role = Validation::string_validation(get_translated_string("menu_list_admin_user_edit_input_role"), "role");

      if (role == "admin" || role == "user") {
        user.update_role(username, role);
        cout << get_translated_string("menu_list_admin_user_edit_success") << endl;
      } else {
        cout << get_translated_string("menu_list_admin_user_edit_invalid") << endl;
      }
    }

    /**
     * @brief Delete user by username
     * 
     * @return void
    */
    static void destroy() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("menu_list_admin_user_delete") << endl;

      string username = Validation::string_validation(get_translated_string("menu_list_admin_user_delete_input_username"), "username");

      User user;
      User data = user.find(username);

      if (data.get_role() == "admin") {
        cout << get_translated_string("menu_list_admin_user_delete_not_found") << endl;
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
            list(user);
            break;
          case 2:
            Register::register_user("user");
            break;
          case 3:
            search(user);
            break;
          case 4:
            edit();
            break;
          case 5:
            destroy();
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
};

#endif // CONTROLLER_ADMIN_USER_HPP