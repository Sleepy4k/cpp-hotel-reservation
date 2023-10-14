#pragma once

#ifndef MODEL_BOOKING_HPP
#define MODEL_BOOKING_HPP

#include "room.hpp"
#include "user.hpp"

/**
 * @brief Booking class to handle booking
 * 
 * @class Booking
 */
class Booking {
  private:
    /**
     * @brief Booking unique id
     * 
     * @var string
     */
    string uid;

    /**
     * @brief Booking user id
     * 
     * @var string
     */
    string user_id;

    /**
     * @brief Booking room id
     * 
     * @var string
     */
    string room_id;

    /**
     * @brief Booking check in date
     * 
     * @var string
     */
    string check_in_date;

    /**
     * @brief Booking check out date
     * 
     * @var string
     */
    string check_out_date;

    /**
     * @brief Booking status
     * 
     * @var string
     */
    string status;

  public:
    /**
     * @brief Construct a new Booking object
     * 
     * @param uid string
     * @param user_id string
     * @param room_id string
     * @param check_in_date string
     * @param check_out_date string
     * @param status string
     * 
     * @return void
     */
    Booking(string uid, string user_id, string room_id, string check_in_date, string check_out_date, string status) {
      set_uid(uid);
      set_user_id(user_id);
      set_room_id(room_id);
      set_check_in_date(check_in_date);
      set_check_out_date(check_out_date);
      set_status(status);
    };

    /**
     * @brief Construct a new Booking object
     * 
     * @return void
     */
    Booking() {
      set_uid("");
      set_user_id("");
      set_room_id("");
      set_check_in_date("");
      set_check_out_date("");
      set_status("");
    };

    /**
     * @brief Set the uid object
     * 
     * @param uid string
     * 
     * @return void
     */
    const void set_uid(const string uid) {
      this->uid = uid;
    };

    /**
     * @brief Set the user id object
     * 
     * @param user_id string
     * 
     * @return void
     */
    const void set_user_id(const string user_id) {
      this->user_id = user_id;
    };

    /**
     * @brief Set the room id object
     * 
     * @param room_id string
     * 
     * @return void
     */
    const void set_room_id(const string room_id) {
      this->room_id = room_id;
    };

    /**
     * @brief Set the check in date object
     * 
     * @param check_in_date string
     * 
     * @return void
     */
    const void set_check_in_date(const string check_in_date) {
      this->check_in_date = check_in_date;
    };

    /**
     * @brief Set the check out date object
     * 
     * @param check_out_date string
     * 
     * @return void
     */
    const void set_check_out_date(const string check_out_date) {
      this->check_out_date = check_out_date;
    };

    /**
     * @brief Set the status object
     * 
     * @param status string
     * 
     * @return void
     */
    const void set_status(const string status) {
      this->status = status;
    };

    /**
     * @brief Get the uid object
     * 
     * @return string 
     */
    const string get_uid() {
      return this->uid;
    };

    /**
     * @brief Get the user id object
     * 
     * @return string 
     */
    const string get_user_id() {
      return this->user_id;
    };

    /**
     * @brief Get the room id object
     * 
     * @return string 
     */
    const string get_room_id() {
      return this->room_id;
    };

    /**
     * @brief Get the check in date object
     * 
     * @return string 
     */
    const string get_check_in_date() {
      return this->check_in_date;
    };

    /**
     * @brief Get the check out date object
     * 
     * @return string 
     */
    const string get_check_out_date() {
      return this->check_out_date;
    };

    /**
     * @brief Get the status object
     * 
     * @return string 
     */
    const string get_status() {
      return this->status;
    };

    /**
     * @brief Get all booking data
     * 
     * @return vector<Booking> 
     */
    const vector<Booking> get() {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/booking.csv");

      string line;
      vector<Booking> data;
      vector<string> row;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        data.push_back(Booking(row[0], row[1], row[2], row[3], row[4], row[5]));
      
        row.clear();
      }

      return data;
    };

    /**
     * @brief Create a new booking
     * 
     * @param allow_print bool
     * 
     * @return void
     */
    const void create(const bool allow_print = true) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/booking.csv");

      string line;
      vector<string> row;
      bool is_exist = false;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        if (row[1] == this->user_id && row[2] == this->room_id && row[5] == this->status) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        cout << get_translated_string("model_booking_already_exist") << endl;
      } else {
        fstream outfile(Path::getPath() + "/booking.csv", ios::app);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << this->uid << "," << this->user_id << "," << this->room_id << "," << this->check_in_date << "," << this->check_out_date << "," << this->status << endl;
          outfile.close();

          if (allow_print) {
            cout << Sprintf::format(get_translated_string("model_booking_all_success"), {get_translated_string("model_booking_created")}) << endl;
          }
        }
      }
    };

    /**
     * @brief Find booking by uid
     * 
     * @param uid string
     * 
     * @return Booking 
     */
    const Booking find(const string uid) {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/booking.csv");

      Booking booking;
      string line;
      vector<string> row;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        if (row[0] == uid) {
          booking = Booking(row[0], row[1], row[2], row[3], row[4], row[5]);
        }

        row.clear();
      }

      return booking;
    };

    /**
     * @brief Update booking by uid
     * 
     * @param uid string
     * 
     * @return void
     */
    const void update(const string uid) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/booking.csv");

      string line;
      vector<string> row;
      bool is_exist = false;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        if (row[0] == uid) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        vector<Booking> booking = this->get();

        fstream outfile(Path::getPath() + "/booking.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < booking.size(); i++) {
            if (booking[i].get_uid() == uid) {
              booking[i].set_user_id(this->user_id);
              booking[i].set_room_id(this->room_id);
              booking[i].set_check_in_date(this->check_in_date);
              booking[i].set_check_out_date(this->check_out_date);
              booking[i].set_status(this->status);
            }

            booking[i].create(false);
          }

          cout << Sprintf::format(get_translated_string("model_booking_all_success"), {get_translated_string("model_booking_updated")}) << endl;
        }
      } else {
        cout << get_translated_string("model_booking_notfound") << endl;
      }
    };

    /**
     * @brief Delete booking by uid
     * 
     * @param uid string
     * 
     * @return void
     */
    const void delete_booking(const string uid) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/booking.csv");

      string line;
      vector<string> row;
      bool is_exist = false;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        if (row[0] == uid) {
          is_exist = true;
        }

        row.clear();
      }

      if (!is_exist) {
        cout << get_translated_string("model_booking_notfound") << endl;
      } else {
        vector<Booking> booking = this->get();

        fstream outfile(Path::getPath() + "/booking.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < booking.size(); i++) {
            if (booking[i].get_uid() != uid) {
              booking[i].create(false);
            }
          }

          cout << Sprintf::format(get_translated_string("model_booking_all_success"), {get_translated_string("model_booking_deleted")}) << endl;
        }
      }
    };

    /**
     * @brief Get the string representation of the booking
     * 
     * @return vector<Booking> 
     */
    const string toString() {
      return "UID: " + this->uid + "\n"
            + "User ID: " + this->user_id + "\n"
            + "Room ID: " + this->room_id + "\n"
            + "Check In Date: " + this->check_in_date + "\n"
            + "Check Out Date: " + this->check_out_date + "\n"
            + "Status: " + this->status + "\n";
    };
};

#endif // MODEL_BOOKING_HPP