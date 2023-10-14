#pragma once

#ifndef CONTROLLER_USER_ROOM_HPP
#define CONTROLLER_USER_ROOM_HPP

#include "../../const/app.hpp"
#include "../../model/user.hpp"
#include "../../model/room.hpp"
#include "../../helper/getky.hpp"
#include "../../const/menu_list.hpp"
#include "../../handler/validation.hpp"

/**
 * @brief AdminRoomDashboard class to handle admin room dashboard
 * 
 * @class AdminRoomDashboard
 */
class UserRoomDashboard {
  public:
    /**
     * @brief List all rooms
     * 
     * @param room Room
     * 
     * @return void
     */
    static void list(Room room) {
      using std::to_string;

      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("user_room_list_title") << endl;

      vector<Room> rooms = room.get();
      int totalRooms = rooms.size();

      if (totalRooms > 0) {
        for (int i = 0; i < totalRooms; i++) {
          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_uid"), {rooms[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_name"), {rooms[i].get_name()}) << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_type"), {rooms[i].get_type()}) << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_price"), {to_string(rooms[i].get_price())}) << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_capacity"), {to_string(rooms[i].get_capacity())}) << '\n';
          cout << Sprintf::format(get_translated_string("user_room_list_data_status"), {rooms[i].get_status()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }

        cout << '\n' << Sprintf::format(get_translated_string("user_room_list_header"), {to_string(totalRooms)}) << endl;
      } else {
        cout << get_translated_string("user_room_list_empty") << endl;
      }

      Getky::pause();
    };

    /**
     * @brief Search room by uid
     * 
     * @param room Room
     * 
     * @return void
     */
    static void search(Room room) {
      using std::to_string;

      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("user_room_search_title") << endl;

      string uid = Validation::string_validation(get_translated_string("user_room_input_uid"), "uid");
      Room data = room.find(uid);

      if (data.get_uid() == "") {
        cout << Sprintf::format(get_translated_string("user_room_not_found"), {uid}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_name"), {data.get_name()}) << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_type"), {data.get_type()}) << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_price"), {to_string(data.get_price())}) << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_capacity"), {to_string(data.get_capacity())}) << '\n';
      cout << Sprintf::format(get_translated_string("user_room_list_data_status"), {data.get_status()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      Getky::pause();
    };

    /**
     * @brief Dashboard for admin room
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      Room room;
      vector<string> menu_list = MenuList::USER_ROOM_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_user_room_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_user_room_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1: list(room);
            break;
          case 2: search(room);
            break;
          case 3: return;
            break;
          default: cout << get_translated_string("menu_list_user_room_invalid") << endl;
            break;
        }
      }
    };
};

#endif // CONTROLLER_USER_ROOM_HPP