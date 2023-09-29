#include <vector>
#include <iostream>
#include "../handler/i18n.hpp"

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
    get_translated_string("menu_list_main_admin"),
    get_translated_string("menu_list_main_user"),
    get_translated_string("menu_list_main_register"),
    get_translated_string("menu_list_main_forgot"),
    get_translated_string("menu_list_main_exit")
  };

  /**
   * @brief Forgot menu list
   * 
   * @var vector<string>
   */
  const vector<string> FORGOT_MENU = {
    get_translated_string("menu_list_forgot_pet"),
    get_translated_string("menu_list_forgot_color"),
    get_translated_string("menu_list_forgot_food"),
    get_translated_string("menu_list_forgot_person"),
  };

  /**
   * @brief Admin dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_DASHBOARD_MENU = {
    "Manage Room",
    "Manage User",
    "Manage Booking",
    "Manage Admin",
    "Report and Statistic",
    "Manage System",
    "Logout"
  };

  /**
   * @brief User dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> USER_DASHBOARD_MENU = {
    "Search Room",
    "Booking Room",
    "History Booking",
    "Profile",
    "Logout"
  };
};

#endif