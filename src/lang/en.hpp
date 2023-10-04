#pragma once

#ifndef LANG_EN_HPP
#define LANG_EN_HPP

#include <map>

using std::map;
using std::string;

/**
 * @brief English translations
 * 
 * @var map<string, string>
 */
map<string, string> english_translations = {
  {"app_name", "Hotel Reservation System"},

  {"menu_list_main_welcome", "Welcome To Home Page"},
  {"menu_list_main_admin", "Admin Dashboard"},
  {"menu_list_main_user", "User Dashboard"},
  {"menu_list_main_register", "Registration User"},
  {"menu_list_main_forgot", "Forgot Password"},
  {"menu_list_main_exit", "Exit"},
  {"menu_list_main_press", "Press"},
  {"menu_list_main_invalid", "Invalid menu"},
  {"menu_list_main_thanks", "Thank You For Using"},

  {"menu_list_forgot_pet", "What was your favorite pet's name?"},
  {"menu_list_forgot_color", "What was your favorite color?"},
  {"menu_list_forgot_food", "What was your favorite food?"},
  {"menu_list_forgot_person", "Who is your favorite person?"},

  {"menu_list_admin_title", "Welcome, % to dashboard admin"},
  {"menu_list_admin_manage_room", "Manage Room"},
  {"menu_list_admin_manage_user", "Manage User"},
  {"menu_list_admin_manage_booking", "Manage Booking"},
  {"menu_list_admin_manage_admin", "Manage Admin"},
  {"menu_list_admin_manage_system", "Manage System"},
  {"menu_list_admin_report_and_statistic", "Report and Statistic"},
  {"menu_list_admin_press", "Press"},
  {"menu_list_admin_logout", "Logout"},
  {"menu_list_admin_invalid", "Invalid menu"},

  {"menu_list_user_title", "Welcome, % to dashboard user"},
  {"menu_list_user_search_room", "Search Room"},
  {"menu_list_user_booking_room", "Booking Room"},
  {"menu_list_user_booking_history", "Booking History"},
  {"menu_list_user_profile", "Profile"},
  {"menu_list_user_press", "Press"},
  {"menu_list_user_logout", "Logout"},
  {"menu_list_user_invalid", "Invalid menu"},

  {"menu_list_admin_system_title", "Hai %, welcome to system admin dashboard"},
  {"menu_list_admin_system_language", "Manage Language"},
  {"menu_list_admin_system_debug", "Manage Debug"},
  {"menu_list_admin_system_back", "Back"},
  {"menu_list_admin_system_press", "Press"},
  {"menu_list_admin_system_invalid", "Invalid menu"},

  {"menu_list_user_profile_title", "Hai %, welcome to profile user dashboard"},
  {"menu_list_user_profile_forgot", "Change Password"},
  {"menu_list_user_profile_back", "Back"},
  {"menu_list_user_profile_press", "Press"},
  {"menu_list_user_profile_invalid", "Invalid menu"},

  {"validation_integer_input", "Please enter your Choice: "},
  {"validation_integer_invalid", "Please enter a valid number!!"},
  {"validation_integer_between", "Please enter a number between % and %!!"},

  {"validation_string_invalid", "Please enter a valid input!!"},

  {"model_user_created", "created"},
  {"model_user_updated", "updated"},
  {"model_user_deleted", "deleted"},
  {"model_user_notfound", "User not found"},
  {"model_user_all_success", "User % successfully"},
  {"model_user_already_exist", "Username already exist"},

  {"model_room_created", "created"},
  {"model_room_updated", "updated"},
  {"model_room_deleted", "deleted"},
  {"model_room_notfound", "Room not found"},
  {"model_room_all_success", "Room % successfully"},
  {"model_room_already_exist", "Room already exist"},

  {"model_booking_created", "created"},
  {"model_booking_updated", "updated"},
  {"model_booking_deleted", "deleted"},
  {"model_booking_notfound", "Booking not found"},
  {"model_booking_all_success", "Booking % successfully"},
  {"model_booking_already_exist", "Booking already exist"},

  {"register_title", "Register Your Account"},
  {"register_input_username", "Please Enter Your Username: "},
  {"register_input_password", "Please Enter Your Password: "},
  {"register_input_confirm_password", "Please Enter Your Confirm Password: "},
  {"register_input_password_not_same", "Password and confirm password must be same"},

  {"login_title", "Login Your Account"},
  {"login_input_username", "Please Enter Your Username: "},
  {"login_input_password", "Please Enter Your Password: "},
  {"login_not_admin", "You are not admin"},
  {"login_invalid_password", "Password is wrong"},

  {"login_confirm_question", "Forgot your password? (y/n)"},
  {"login_confirm_input_confirm", "Please Enter Your Confirmation: "},
  {"login_confirm_input_invalid", "Confirmation must be y or n"},

  {"forgot_title", "Forgot Your Password"},
  {"forgot_input_username", "Please Enter Your Username: "},

  {"forgot_validate_title", "Validate Forgot Question"},
  {"forgot_validate_input_answer", "Please Enter Your Answer: "},
  {"forgot_validate_input_password", "Please Enter Your New Password: "},
  {"forgot_validate_input_confirm_password", "Please Enter Your Confirm New Password: "},
  {"forgot_validate_input_password_invalid", "Answer is wrong"},
  {"forgot_validate_input_password_not_same", "Password and confirm password must be same"},
  {"forgot_validate_input_password_must_be_different", "Password must be different from the old password"},

  {"forgot_create_title", "Create Forgot Question"},
  {"forgot_create_press", "Press"},
  {"forgot_create_input_answer", "Please Enter Your Answer: "},
  {"forgot_create_invalid_menu", "Invalid menu"},

  {"admin_system_input_language", "Please enter the language code (en, id): "},
  {"admin_system_invalid_language", "language must be en or id"},
  {"admin_system_input_debug", "Please enter the debug mode (true, false): "},
  {"admin_system_invalid_debug", "debug must be true or false"},
};

#endif // LANG_EN_HPP