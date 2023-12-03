#pragma once

#ifndef CONTROLLER_ADMIN_BOOKING_HPP
#define CONTROLLER_ADMIN_BOOKING_HPP

#include "../../const/app.hpp"
#include "../../helper/getky.hpp"
#include "../../model/booking.hpp"
#include "../../auth/register.hpp"
#include "../../const/menu_list.hpp"

/**
 * @brief AdminBookingDashboard class to handle admin booking dashboard
 * 
 * @class AdminBookingDashboard
 */
class AdminBookingDashboard {
  public:
    /**
     * @brief List all booking data
     * 
     * @param user User
     * 
     * @return void
    */
    static void list(Booking booking) {
      using std::to_string;

      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_booking_list_title") << endl;

      vector<Booking> bookings = booking.get();
      int totalBookings = bookings.size();

      if (totalBookings > 0) {
        for (int i = 0; i < totalBookings; i++) {
          cout << "\n--------------------------------------------------------" << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_uid"), {bookings[i].get_uid()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_user_uid"), {bookings[i].get_user_id()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_room_uid"), {bookings[i].get_room_id()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_in"), {bookings[i].get_check_in_date()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_out"), {bookings[i].get_check_out_date()}) << '\n';
          cout << Sprintf::format(get_translated_string("admin_booking_list_data_status"), {bookings[i].get_status()}) << '\n';
          cout << "--------------------------------------------------------" << '\n';
        }

        cout << '\n' << Sprintf::format(get_translated_string("admin_booking_list_header"), {to_string(totalBookings)}) << endl;
      } else {
        cout << get_translated_string("admin_booking_list_empty") << endl;
      }

      Getky::pause();
    }

    /**
     * @brief Search booking by user id
     * 
     * @param user User
     * 
     * @return void
    */
    static void search(Booking booking) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_booking_search_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_booking_search_uid"), "uid");
      Booking data = booking.find(uid);

      if (data.get_uid() == "") {
        cout << Sprintf::format(get_translated_string("admin_booking_not_found"), {uid}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_user_uid"), {data.get_user_id()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_room_uid"), {data.get_room_id()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_in"), {data.get_check_in_date()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_out"), {data.get_check_out_date()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_status"), {data.get_status()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      Getky::pause();
    }

    /**
     * @brief Edit booking by uid
     * 
     * @param user User
     * 
     * @return void
    */
    static void edit(Booking booking) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_booking_edit_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_booking_search_uid"), "uid");
      Booking data = booking.find(uid);

      if (data.get_uid() == "") {
        cout << Sprintf::format(get_translated_string("admin_booking_not_found"), {uid}) << endl;
        return;
      }

      cout << "\n--------------------------------------------------------" << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_uid"), {data.get_uid()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_user_uid"), {data.get_user_id()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_room_uid"), {data.get_room_id()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_in"), {data.get_check_in_date()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_check_out"), {data.get_check_out_date()}) << '\n';
      cout << Sprintf::format(get_translated_string("admin_booking_list_data_status"), {data.get_status()}) << '\n';
      cout << "--------------------------------------------------------" << '\n';

      string check_in = Validation::string_validation(get_translated_string("admin_booking_input_check_in"), "date");
      string check_out = Validation::string_validation(get_translated_string("admin_booking_input_check_out"), "date");
      string status = Validation::string_validation(get_translated_string("admin_booking_input_status"), "status_booking");

      data.set_check_in_date(check_in);
      data.set_check_out_date(check_out);
      data.set_status(status);
    }

    /**
     * @brief Destroy booking by uid
     * 
     * @param user User
     * 
     * @return void
    */
    static void destroy(Booking booking) {
      cout << "\n\n----------------------------------------" << endl;
      cout << "\t" << get_translated_string(App::APP_NAME) << endl;
      cout << "----------------------------------------" << endl;
      cout << get_translated_string("admin_booking_destroy_title") << endl;

      string uid = Validation::string_validation(get_translated_string("admin_booking_search_uid"), "uid");
      booking.delete_booking(uid);
    }

    /**
     * @brief Show the admin booking dashboard
     * 
     * @param user User
     * 
     * @return void
    */
    static void dashboard(User user) {
      Booking booking;
      vector<string> menu_list = MenuList::ADMIN_BOOKING_DASHBOARD_MENU;

      while (true) {
        cout << "\n\n----------------------------------------" << endl;
        cout << "\t" << get_translated_string(App::APP_NAME) << endl;
        cout << "----------------------------------------" << endl;
        cout << Sprintf::format(get_translated_string("menu_list_admin_booking_title"), {user.get_username()}) << endl;
      
        for (unsigned int i = 0; i < menu_list.size(); i++) {
          cout << get_translated_string("menu_list_admin_booking_press") << " " << i + 1 << " --> " << get_translated_string(menu_list[i]) << '\n';
        }

        int menu = Validation::integer_validation(1, menu_list.size());

        switch (menu) {
        case 1: list(booking);
          break;
        case 2: search(booking);
          break;
        case 3: edit(booking);
          break;
        case 4: destroy(booking);
          break;
        case 5: return;
          break;
        default:
          break;
        }
      }
    }
};

#endif // CONTROLLER_ADMIN_BOOKING_HPP