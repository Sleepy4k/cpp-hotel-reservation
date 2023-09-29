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
    get_translated_string("menu_list_forgot_person")
  };

  /**
   * @brief Admin dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_DASHBOARD_MENU = {
    get_translated_string("menu_list_admin_manage_room"),
    get_translated_string("menu_list_admin_manage_user"),
    get_translated_string("menu_list_admin_manage_booking"),
    get_translated_string("menu_list_admin_manage_admin"),
    get_translated_string("menu_list_admin_report_and_statistic"),
    get_translated_string("menu_list_admin_manage_system"),
    get_translated_string("menu_list_admin_logout")
  };

  /**
   * @brief User dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> USER_DASHBOARD_MENU = {
    get_translated_string("menu_list_user_search_room"),
    get_translated_string("menu_list_user_booking_room"),
    get_translated_string("menu_list_user_booking_history"),
    get_translated_string("menu_list_user_profile"),
    get_translated_string("menu_list_user_logout")
  };

  /**
   * @brief Admin system dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_SYSTEM_DASHBOARD_MENU = {
    get_translated_string("menu_list_admin_system_language"),
    get_translated_string("menu_list_admin_system_debug"),
    get_translated_string("menu_list_admin_system_back")
  };
};

#endif