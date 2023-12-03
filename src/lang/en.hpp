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
const map<string, string> english_translations = {
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

  {"menu_list_admin_system_title", "Hi %, welcome to system admin dashboard"},
  {"menu_list_admin_system_language", "Manage Language"},
  {"menu_list_admin_system_debug", "Manage Debug"},
  {"menu_list_admin_system_back", "Back"},
  {"menu_list_admin_system_press", "Press"},
  {"menu_list_admin_system_invalid", "Invalid menu"},

  {"menu_list_admin_room_title", "Hi %, welcome to room admin dashboard"},
  {"menu_list_admin_room_list", "Show All Room"},
  {"menu_list_admin_room_add", "Add New Room"},
  {"menu_list_admin_room_search", "Search Room"},
  {"menu_list_admin_room_edit", "Edit Room"},
  {"menu_list_admin_room_delete", "Delete Room"},
  {"menu_list_admin_room_back", "Back"},
  {"menu_list_admin_room_press", "Press"},
  {"menu_list_admin_room_invalid", "Invalid menu"},

  {"menu_list_admin_user_title", "Hi %, welcome to user admin dashboard"},
  {"menu_list_admin_user_list", "Show All User"},
  {"menu_list_admin_user_add", "Add New User"},
  {"menu_list_admin_user_search", "Seach User"},
  {"menu_list_admin_user_edit", "Edit User"},
  {"menu_list_admin_user_delete", "Delete User"},
  {"menu_list_admin_user_back", "Back"},
  {"menu_list_admin_user_press", "Press"},
  {"menu_list_admin_user_invalid", "Invalid menu"},

  {"menu_list_admin_admin_title", "Hi %, welcome to admin dashboard"},
  {"menu_list_admin_admin_list", "Show All Admin"},
  {"menu_list_admin_admin_add", "Add New Admin"},
  {"menu_list_admin_admin_search", "Seach Admin"},
  {"menu_list_admin_admin_edit", "Edit Admin"},
  {"menu_list_admin_admin_delete", "Delete Admin"},
  {"menu_list_admin_admin_back", "Back"},
  {"menu_list_admin_admin_press", "Press"},
  {"menu_list_admin_admin_invalid", "Invalid menu"},

  {"menu_list_admin_booking_title", "Hi %, welcome to booking dashboard"},
  {"menu_list_admin_admin_list", "Show All Booking"},
  {"menu_list_admin_admin_search", "Seach Booking"},
  {"menu_list_admin_admin_edit", "Edit Booking"},
  {"menu_list_admin_admin_delete", "Delete Booking"},
  {"menu_list_admin_admin_back", "Back"},
  {"menu_list_admin_admin_press", "Press"},
  {"menu_list_admin_admin_invalid", "Invalid menu"},

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
  {"login_invalid_username", "Username not found"},
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

  {"admin_room_list_title", "List of all room"},
  {"admin_room_add_title", "Create new room"},
  {"admin_room_search_title", "Search a room"},
  {"admin_room_edit_title", "Edit room data"},
  {"admin_room_delete_title", "Delete room data"},
  {"admin_room_list_header", "Found % total data"},
  {"admin_room_list_data_uid", "UUID : %"},
  {"admin_room_list_data_name", "Name : %"},
  {"admin_room_list_data_type", "Type : %"},
  {"admin_room_list_data_price", "Price : %"},
  {"admin_room_list_data_capacity", "Capacity : %"},
  {"admin_room_list_data_status", "Status : %"},
  {"admin_room_list_empty", "No Data Found"},
  {"admin_room_input_uid", "Please Enter Room UID: "},
  {"admin_room_input_name", "Please Enter Room Name: "},
  {"admin_room_input_type", "Please Enter Room Type: "},
  {"admin_room_input_price", "Please Enter Room Price: "},
  {"admin_room_input_capacity", "Please Enter Room Capacity: "},
  {"admin_room_input_status", "Please Enter Room Status (available/booked): "},
  {"admin_room_not_found", "Sorry room with uid % not found in our database"},

  {"admin_user_list_title", "List of all user"},
  {"admin_user_search_title", "Search a user"},
  {"admin_user_edit_title", "Edit user data"},
  {"admin_user_delete_title", "Remove user data"},
  {"admin_user_list_header", "Found % total data"},
  {"admin_user_list_data_uid", "UUID : %"},
  {"admin_user_list_data_username", "Username : %"},
  {"admin_user_list_data_role", "Role : %"},
  {"admin_user_list_empty", "No Data Found"},
  {"admin_user_input_username", "Please Enter Username : "},
  {"admin_user_input_role", "Please Enter Role (admin/user) : "},
  {"admin_user_edit_invalid", "Invalid role"},
  {"admin_user_not_found", "Sorry user with username % not found in our database"},

  {"admin_admin_list_title", "List of all admin"},
  {"admin_admin_search_title", "Search a admin"},
  {"admin_admin_edit_title", "Edit admin data"},
  {"admin_admin_delete_title", "Remove admin data"},
  {"admin_admin_list_header", "Found % total data"},
  {"admin_admin_list_data_uid", "UUID : %"},
  {"admin_admin_list_data_username", "Username : %"},
  {"admin_admin_list_data_role", "Role : %"},
  {"admin_admin_list_empty", "No Data Found"},
  {"admin_admin_input_username", "Please Enter Username : "},
  {"admin_admin_input_role", "Please Enter Role (admin/user) : "},
  {"admin_admin_edit_invalid", "Invalid role"},
  {"admin_admin_not_found", "Sorry admin with username % not found in our database"},

  {"admin_booking_list_title", "List of all booking"},
  {"admin_booking_search_title", "Search a booking"},
  {"admin_booking_edit_title", "Edit booking data"},
  {"admin_booking_delete_title", "Remove bokking data"},
  {"admin_booking_list_header", "Found % total data"},
  {"admin_booking_list_data_uid", "UUID : %"},
  {"admin_booking_list_data_user_uid", "User ID : %"},
  {"admin_booking_list_data_room_uid", "Room ID : %"},
  {"admin_booking_list_data_check_in", "Check IN : %"},
  {"admin_booking_list_data_check_out", "Check OUT : %"},
  {"admin_booking_list_data_status", "Status : %"},
  {"admin_booking_list_empty", "No Data Found"},
  {"admin_booking_input_check_in", "Please Enter Username : "},
  {"admin_booking_input_check_out", "Please Enter Role (admin/user) : "},
  {"admin_booking_input_check_out", "Please Enter Role (admin/user) : "},
  {"admin_booking_not_found", "Sorry booking with id % not found in our database"},
  {"admin_booking_not_found", "Sorry booking with id % not found in our database"},

  {"press_any_key_to_continue", "Press any key to continue"},
};

/**
 * @brief Check if translation is duplicated (for testing purpose)
 * 
 * @return true || false
 */
bool check_en_translate_duplicated() {
  map<string, string> temp;

  for (auto const& x : english_translations) {
    if (temp.find(x.first) == temp.end()) {
      temp.insert({x.first, x.second});
    } else {
      return true;
    }
  }

  return false;
}

#endif // LANG_EN_HPP