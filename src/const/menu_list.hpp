#include <vector>
#include <iostream>

using namespace std;

#ifndef MENU_LIST_HPP
#define MENU_LIST_HPP

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
    "Exit"
  };
}

#endif