#pragma once

#ifndef CONTROLLER_ADMIN_ROOM_HPP
#define CONTROLLER_ADMIN_ROOM_HPP

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
class AdminRoomDashboard {
  public:
    /**
     * @brief List all rooms
     * 
     * @return void
     */
    static void list() {
      Room room;
      vector<Room> rooms = room.get();

      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("admin_room_list_title") << endl;

      int totalRooms = rooms.size();

      if (totalRooms > 0) {
        cout << Sprintf::format(get_translated_string("admin_room_list_header"), {to_string(totalRooms)}) << endl;

        for (unsigned int i = 0; i < totalRooms; i++) {
          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_uid"), {rooms[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_name"), {rooms[i].get_name()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_type"), {rooms[i].get_type()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_price"), {to_string(rooms[i].get_price())}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_capacity"), {to_string(rooms[i].get_capacity())}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_room_list_data_status"), {rooms[i].get_status()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }
      } else {
        cout << get_translated_string("admin_room_list_empty") << endl;
      }

      Getky::pause();
    };

    /**
     * @brief Create new room
     * 
     * @return void
     */
    static void create() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("admin_room_add_title") << endl;

      string name = Validation::string_validation(get_translated_string("admin_room_input_name"), "name");
      string type = Validation::string_validation(get_translated_string("admin_room_input_type"), "type");
      string price = Validation::string_validation(get_translated_string("admin_room_input_price"), "number");
      string capacity = Validation::string_validation(get_translated_string("admin_room_input_capacity"), "number");
      string status = Validation::string_validation(get_translated_string("admin_room_input_status"), "status");

      if (status == "available" || status == "tersedia") {
        status = "available";
      } else {
        status = "booked";
      }

      Room room;
      room.set_uid(UUID::generate_uuid());
      room.set_name(name);
      room.set_type(type);
      room.set_price(stoi(price));
      room.set_capacity(stoi(capacity));
      room.set_status(status);
      room.create();
    };

    /**
     * @brief Search room by uid
     * 
     * @return void
     */
    static void search() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("admin_room_search_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_room_input_uid"), "uid");

      Room room;
      Room data = room.find(uid);

      if (data.get_uid() == "") {
        cout << Sprintf::format(get_translated_string("admin_room_search_not_found"), {uid}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_name"), {data.get_name()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_type"), {data.get_type()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_price"), {to_string(data.get_price())}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_capacity"), {to_string(data.get_capacity())}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_status"), {data.get_status()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';
    };

    /**
     * @brief Edit room by uid
     * 
     * @return void
     */
    static void edit() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("admin_room_edit_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_room_input_uid"), "uid");

      Room room;
      Room data = room.find(uid);

      if (data.get_uid() == "") {
        cout << get_translated_string("admin_room_edit_not_found") << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_name"), {data.get_name()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_type"), {data.get_type()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_price"), {to_string(data.get_price())}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_capacity"), {to_string(data.get_capacity())}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_room_list_data_status"), {data.get_status()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      string name = Validation::string_validation(get_translated_string("admin_room_input_name"), "name");
      string type = Validation::string_validation(get_translated_string("admin_room_input_type"), "type");
      string price = Validation::string_validation(get_translated_string("admin_room_input_price"), "number");
      string capacity = Validation::string_validation(get_translated_string("admin_room_input_capacity"), "number");
      string status = Validation::string_validation(get_translated_string("admin_room_input_status"), "status");

      room.set_name(name);
      room.set_type(type);
      room.set_price(stoi(price));
      room.set_capacity(stoi(capacity));
      room.set_status(status);
      room.update(uid);
    };

    /**
     * @brief Delete room by uid
     * 
     * @return void
     */
    static void destroy() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("admin_room_delete_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_room_input_uid"), "uid");

      Room room;
      room.delete_room(uid);
    }

    /**
     * @brief Dashboard for admin room
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      vector<string> menu_list = MenuList::ADMIN_ROOM_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n--------------------------------------------------------------------" << endl;
        cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_room_title"), {user.get_username()}) << endl;

        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_room_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
          case 1:
            list();
            break;
          case 2:
            create();
            break;
          case 3:
            search();
            break;
          case 4:
            edit();
            break;
          case 5:
            destroy();
            break;
          case 6:
            return;
            break;
          default:
            cout << get_translated_string("menu_list_admin_room_invalid") << endl;
            break;
        }
      }
    };
};

#endif // CONTROLLER_ADMIN_ROOM_HPP