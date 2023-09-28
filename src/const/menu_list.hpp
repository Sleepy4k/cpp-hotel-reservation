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
  /**
   * @brief Main menu list
   * 
   * @var vector<string>
   */
  const vector<string> MAIN_MENU = {
    "Admin Dashboard",
    "User Dashboard",
    "Registration User",
    "Forgot Password",
    "Exit"
  };

  /**
   * @brief Forgot menu list
   * 
   * @var vector<string>
   */
  const vector<string> FORGOT_MENU = {
    "What was your favorite pet's name?",
    "What is your favorite color?",
    "What is your favorite food?",
    "Who is your favorite person?"
  };
};

#endif