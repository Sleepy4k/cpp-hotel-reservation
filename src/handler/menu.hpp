#include "validation.hpp"
#include "../auth/login.hpp"
#include "../auth/register.hpp"

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
    void main_menu() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               Hotel Reservation System                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Welcome To Home Page" << endl;
      cout << "Press 1 --> Admin Dashboard" << endl;
      cout << "Press 2 --> User Dashboard" << endl;
      cout << "Press 3 --> Registration User" << endl;
      cout << "Press 4 --> Exit" << endl;

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