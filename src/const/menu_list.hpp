#pragma once

#ifndef CONST_MENU_LIST_HPP
#define CONST_MENU_LIST_HPP

using std::string;
using std::vector;

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
    "menu_list_main_admin",
    "menu_list_main_user",
    "menu_list_main_register",
    "menu_list_main_forgot",
    "menu_list_main_exit"
  };

  /**
   * @brief Forgot menu list
   * 
   * @var vector<string>
   */
  const vector<string> FORGOT_MENU = {
    "menu_list_forgot_pet",
    "menu_list_forgot_color",
    "menu_list_forgot_food",
    "menu_list_forgot_person"
  };

  /**
   * @brief Admin dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_DASHBOARD_MENU = {
    "menu_list_admin_manage_room",
    "menu_list_admin_manage_user",
    "menu_list_admin_manage_booking",
    "menu_list_admin_manage_admin",
    "menu_list_admin_manage_system",
    "menu_list_admin_logout"
  };

  /**
   * @brief User dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> USER_DASHBOARD_MENU = {
    "menu_list_user_search_room",
    "menu_list_user_booking_room",
    "menu_list_user_booking_history",
    "menu_list_user_profile",
    "menu_list_user_logout"
  };

  /**
   * @brief Admin system dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_SYSTEM_DASHBOARD_MENU = {
    "menu_list_admin_system_language",
    "menu_list_admin_system_debug",
    "menu_list_admin_system_back"
  };

  /**
   * @brief Admin room dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_ROOM_DASHBOARD_MENU = {
    "menu_list_admin_room_list",
    "menu_list_admin_room_add",
    "menu_list_admin_room_search",
    "menu_list_admin_room_edit",
    "menu_list_admin_room_delete",
    "menu_list_admin_room_back"
  };

  /**
   * @brief Admin user dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_USER_DASHBOARD_MENU = {
    "menu_list_admin_user_list",
    "menu_list_admin_user_add",
    "menu_list_admin_user_search",
    "menu_list_admin_user_edit",
    "menu_list_admin_user_delete",
    "menu_list_admin_user_back"
  };

  /**
   * @brief Admin admin dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_ADMIN_DASHBOARD_MENU = {
    "menu_list_admin_admin_list",
    "menu_list_admin_admin_add",
    "menu_list_admin_admin_search",
    "menu_list_admin_admin_edit",
    "menu_list_admin_admin_delete",
    "menu_list_admin_admin_back"
  };

  /**
   * @brief Admin booking dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> ADMIN_BOOKING_DASHBOARD_MENU = {
    "menu_list_admin_booking_list",
    "menu_list_admin_booking_search",
    "menu_list_admin_booking_edit",
    "menu_list_admin_booking_delete",
    "menu_list_admin_booking_back"
  };

  /**
   * @brief User profile dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> USER_PROFILE_DASHBOARD_MENU = {
    "menu_list_user_profile_forgot",
    "menu_list_user_profile_back"
  };

  /**
   * @brief User room dashboard menu list
   * 
   * @var vector<string>
   */
  const vector<string> USER_ROOM_DASHBOARD_MENU = {
    "menu_list_user_room_list",
    "menu_list_user_room_search",
    "menu_list_user_room_back"
  };
};

#endif // CONST_MENU_LIST_HPP