#include "validation.hpp"
#include "../const/app.hpp"
#include "../auth/login.hpp"
#include "../auth/register.hpp"
#include "../const/menu_list.hpp"

using namespace std;

#ifndef HANDLER_MENU_HPP
#define HANDLER_MENU_HPP

/**
 * @brief Menu class to show the menu list to the user
 * 
 * @class Menu
 */
class Menu {
  public:
    /**
     * @brief Show the main menu list to the user
     * 
     * @return void
     */
    static void main_menu() {
      vector<string> menu_list = MenuList::MAIN_MENU;

      while (true) {
        cout << "\n\n--------------------------------------------------------------------" << endl;
        cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << get_translated_string("menu_list_main_welcome") << endl;

        for (int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_main_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << endl;
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1:
            Login::login(true);
            break;
          case 2:
            Login::login(false);
            break;
          case 3:
            Register::register_user();
            break;
          case 4:
            Forgot::forgot_password();
            break;
          case 5:
            cout << get_translated_string("menu_list_main_thanks") << " " << get_translated_string(App::APP_NAME) << endl;
            exit(0);
            break;
          default:
            cout << get_translated_string("menu_list_main_invalid") << endl;
            break;
        }
      }
    };
};

#endif