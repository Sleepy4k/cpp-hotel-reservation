#pragma once

#ifndef MODEL_ROOM_HPP
#define MODEL_ROOM_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include "../const/path.hpp"
#include "../handler/i18n.hpp"
#include "../helper/sprintf.hpp"

using std::cerr;
using std::cout;
using std::vector;

/**
 * @brief Room class to handle room
 * 
 * @class Room
 */
class Room {
  private:
    /**
     * @brief Room unique id
     * 
     * @var string
     */
    string uid;

    /**
     * @brief Room name
     * 
     * @var string
     */
    string name;

    /**
     * @brief Room type
     * 
     * @var string
     */
    string type;

    /**
     * @brief Room price
     * 
     * @var int
     */
    int price;

    /**
     * @brief Room capacity
     * 
     * @var int
     */
    int capacity;

    /**
     * @brief Room status
     * 
     * @var string
     */
    string status;

  public:
    /**
     * @brief Construct a new Room object
     * 
     * @param uid string
     * @param name string
     * @param type string
     * @param price int
     * @param capacity int
     * @param status string
     * 
     * @return void
     */
    Room(string uid, string name, string type, int price, int capacity, string status) {
      set_uid(uid);
      set_name(name);
      set_type(type);
      set_price(price);
      set_capacity(capacity);
      set_status(status);
    };

    /**
     * @brief Construct a new Room object
     * 
     * @return void
     */
    Room() {
      set_uid("");
      set_name("");
      set_type("");
      set_price(0);
      set_capacity(0);
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
     * @brief Set the name object
     * 
     * @param name string
     * 
     * @return void
     */
    const void set_name(const string name) {
      this->name = name;
    };

    /**
     * @brief Set the type object
     * 
     * @param type string
     * 
     * @return void
     */
    const void set_type(const string type) {
      this->type = type;
    };

    /**
     * @brief Set the price object
     * 
     * @param price int
     * 
     * @return void
     */
    const void set_price(const int price) {
      this->price = price;
    };

    /**
     * @brief Set the capacity object
     * 
     * @param capacity int
     * 
     * @return void
     */
    const void set_capacity(const int capacity) {
      this->capacity = capacity;
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
     * @brief Get the name object
     * 
     * @return string 
     */
    const string get_name() {
      return this->name;
    };

    /**
     * @brief Get the type object
     * 
     * @return string 
     */
    const string get_type() {
      return this->type;
    };

    /**
     * @brief Get the price object
     * 
     * @return int 
     */
    const int get_price() {
      return this->price;
    };

    /**
     * @brief Get the capacity object
     * 
     * @return int 
     */
    const int get_capacity() {
      return this->capacity;
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
     * @brief Get all rooms
     * 
     * @return vector<Room> 
     */
    const vector<Room> get() {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/room.csv");

      string line;
      vector<Room> data;
      vector<string> row;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        data.push_back(Room(row[0], row[1], row[2], stoi(row[3]), stoi(row[4]), row[5]));

        row.clear();
      }

      return data;
    };

    /**
     * @brief Create a new room
     * 
     * @param allow_print bool
     * 
     * @return void
     */
    const void create(const bool allow_print = true) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/room.csv");

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

        if (row[1] == this->name && row[2] == this->type) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        cout << get_translated_string("model_room_already_exist") << endl;
        return;
      } else {
        fstream outfile(Path::getPath() + "/room.csv", ios::app);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << this->uid << "," << this->name << "," << this->type << "," << this->price << "," << this->capacity << "," << this->status << endl;
          outfile.close();

          if (allow_print) {
            cout << Sprintf::format(get_translated_string("model_room_all_success"), {get_translated_string("model_room_created")}) << endl;
          }
        }
      }
    };

    /**
     * @brief Find a room by uid
     * 
     * @param uid string
     * 
     * @return Room
     */
    const Room find(const string uid) {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/room.csv");

      Room room;
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
          room = Room(row[0], row[1], row[2], stoi(row[3]), stoi(row[4]), row[5]);
        }

        row.clear();
      }

      return room;
    };

    /**
     * @brief Update a room
     * 
     * @param uid string
     * 
     * @return void
     */
    const void update(const string uid) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/room.csv");

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
        cout << get_translated_string("model_room_notfound") << endl;
      } else {
        vector<Room> rooms = this->get();

        fstream outfile(Path::getPath() + "/room.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < rooms.size(); i++) {
            if (rooms[i].get_uid() == uid) {
              rooms[i].set_name(this->name);
              rooms[i].set_type(this->type);
              rooms[i].set_price(this->price);
              rooms[i].set_capacity(this->capacity);
              rooms[i].set_status(this->status);
            }

            rooms[i].create(false);
          }

          cout << Sprintf::format(get_translated_string("model_room_all_success"), {get_translated_string("model_room_updated")}) << endl;
        }
      }
    };

    /**
     * @brief Delete a room
     * 
     * @param uid string
     * 
     * @return void
     */
    const void delete_room(const string uid) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/room.csv");

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
        cout << get_translated_string("model_room_notfound") << endl;
      } else {
        vector<Room> rooms = this->get();

        fstream outfile(Path::getPath() + "/room.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < rooms.size(); i++) {
            if (rooms[i].get_uid() != uid) {
              rooms[i].create(false);
            }
          }

          cout << Sprintf::format(get_translated_string("model_room_all_success"), {get_translated_string("model_room_deleted")}) << endl;
        }
      }
    };

    /**
     * @brief Get the string representation of the room
     * 
     * @return string
     */
    const string toString() {
      using std::to_string;

      return "UID: " + this->uid + "\n"
            + "Name: " + this->name + "\n"
            + "Type: " + this->type + "\n"
            + "Price: " + to_string(this->price) + "\n"
            + "Capacity: " + to_string(this->capacity) + "\n"
            + "Status: " + this->status + "\n";
    };
};

#endif // MODEL_ROOM_HPP