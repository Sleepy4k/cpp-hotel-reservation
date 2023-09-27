#include <vector>
#include <iostream>

using namespace std;

#ifndef CONST_MENU_LIST_HPP
#define CONST_MENU_LIST_HPP

/**
 * @brief Menu list for the user
 * 
 * @namespace MenuList
 */
namespace MenuList {
  const vector<string> MAIN_MENU = {
    "Admin Dashboard",
    "User Dashboard",
    "Registration User",
    "Forgot Password",
    "Exit"
  };
}

#endif