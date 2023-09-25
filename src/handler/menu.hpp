#include "validation.hpp"
#include "../const/app.hpp"
#include "../auth/login.hpp"
#include "../auth/register.hpp"
#include "../const/menu_list.hpp"

using namespace std;

#ifndef MENU_HPP
#define MENU_HPP

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
    void static main_menu() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Welcome To Home Page" << endl;

      for (int i = 0; i < MenuList::MAIN_MENU.size(); i++) {
        cout << "Press " << i + 1 << " --> " << MenuList::MAIN_MENU[i] << endl;
      }

      int menu = Validation::input_validation(1, 4);

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
          cout << "Exit" << endl;
          break;
        default:
          cout << "Invalid menu" << endl;
          break;
      }
    }
};

#endif