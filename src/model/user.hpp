#pragma once

#ifndef MODEL_USER_HPP
#define MODEL_USER_HPP

#include <vector>
#include <sstream>
#include "../const/path.hpp"
#include "../handler/hash.hpp"
#include "../storage/file.hpp"

using std::ios;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

/**
 * @brief User class to handle user
 * 
 * @struct User
 */
class User {
  private:
    /**
     * @brief User id
     * 
     * @var string
     */
    string uid;

    /**
     * @brief User role
     * 
     * @var string
     */
    string role;

    /**
     * @brief Username
     * 
     * @var string
     */
    string username;

    /**
     * @brief Password
     * 
     * @var string
     */
    string password;

    /**
     * @brief Forgot question id
     * 
     * @var int
     */
    int forgot_question_id;

    /**
     * @brief Forgot answer
     * 
     * @var string
     */
    string forgot_answer;

  public:
    /**
     * @brief Construct a new User object
     * 
     * @param uid string
     * @param role string
     * @param username string
     * @param password string
     * @param forgot_question_id int
     * @param forgot_answer string
     * 
     * @return void
     */
    User(string uid, string role, string username, string password, int forgot_question_id = 0, string forgot_answer = "") {
      set_uid(uid);
      set_role(role);
      set_username(username);
      set_password(password);
      set_forgot_question_id(forgot_question_id);
      set_forgot_answer(forgot_answer);
    };

    /**
     * @brief Construct a new User object
     * 
     * @return void
     */
    User() {
      set_uid("");
      set_role("");
      set_username("");
      set_password("");
      set_forgot_question_id(0);
      set_forgot_answer("");
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
     * @brief Set the role object
     * 
     * @param role string
     * 
     * @return void
     */
    const void set_role(const string role) {
      this->role = role;
    };

    /**
     * @brief Set the username object
     * 
     * @param username string
     * 
     * @return void
     */
    const void set_username(const string username) {
      this->username = username;
    };

    /**
     * @brief Set the password object
     * 
     * @param password string
     * 
     * @return void
     */
    const void set_password(const string password) {
      this->password = password;
    };

    /**
     * @brief Set the forgot question id object
     * 
     * @param forgot_question_id int
     * 
     * @return void
     */
    const void set_forgot_question_id(const int forgot_question_id) {
      this->forgot_question_id = forgot_question_id;
    }

    /**
     * @brief Set the forgot answer object
     * 
     * @param forgot_answer string
     * 
     * @return void
     */
    const void set_forgot_answer(const string forgot_answer) {
      this->forgot_answer = forgot_answer;
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
     * @brief Get the role object
     * 
     * @return string 
     */
    const string get_role() {
      return this->role;
    };

    /**
     * @brief Get the username object
     * 
     * @return string 
     */
    const string get_username() {
      return this->username;
    };

    /**
     * @brief Get the password object
     * 
     * @return string 
     */
    const string get_password() {
      return this->password;
    };

    /**
     * @brief Get the forgot question id object
     * 
     * @return int 
     */
    const int get_forgot_question_id() {
      return this->forgot_question_id;
    };

    /**
     * @brief Get the forgot answer object
     * 
     * @return string 
     */
    const string get_forgot_answer() {
      return this->forgot_answer;
    };

    /**
     * @brief Get all the user
     * 
     * @return vector<string> 
     */
    const vector<User> get() {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

      string line;
      vector<User> data;
      vector<string> row;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        data.push_back(User(row[0], row[1], row[2], row[3], stoi(row[4]), row[5]));

        row.clear();
      }

      return data;
    };

    /**
     * @brief Create the user
     * 
     * @return void
     */
    const void create(const bool allow_print = true) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

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

        if (row[2] == this->username) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        cout << get_translated_string("model_user_already_exist") << endl;
        return;
      } else {
        fstream outfile(Path::getPath() + "/user.csv", ios::app);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << this->uid << "," << this->role << "," << this->username << "," << this->password << "," << this->forgot_question_id << "," << this->forgot_answer << endl;
          outfile.close();

          if (allow_print) {
            cout << Sprintf::format(get_translated_string("model_user_all_success"), {get_translated_string("model_user_created")}) << endl;
          }
        }
      }
    };

    /**
     * @brief Get the user object
     * 
     * @param username string
     * 
     * @return User
     */
    const User find(const string username) {
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

      User user;
      string line;
      vector<string> row;
      stringstream ss(content);

      while (getline(ss, line, '\n')) {
        string word;
        stringstream s(line);

        while (getline(s, word, ',')) {
          row.push_back(word);
        }

        if (row[2] == username) {
          user = User(row[0], row[1], row[2], row[3], stoi(row[4]), row[5]);
        }

        row.clear();
      }

      return user;
    };

    /**
     * @brief Update the user
     * 
     * @return void
     */
    const void update(const string username, const string old_password, const string new_password) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

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

        if (row[2] == username && row[3] == old_password) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        vector<User> users = this->get();

        fstream outfile(Path::getPath() + "/user.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].get_username() == username) {
              users[i].set_password(new_password);
            }

            users[i].create(false);
          }

          cout << Sprintf::format(get_translated_string("model_user_all_success"), {get_translated_string("model_user_updated")}) << endl;
        }
      } else {
        cout << get_translated_string("model_user_notfound") << endl;
      }
    };

    /**
     * @brief Update the user
     * 
     * @param username string
     * @param role string
     * 
     * @return void
    */
    const void update_role(const string username, const string role) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

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

        if (row[2] == username) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        vector<User> users = this->get();

        fstream outfile(Path::getPath() + "/user.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].get_username() == username) {
              users[i].set_role(role);
            }

            users[i].create(false);
          }

          cout << Sprintf::format(get_translated_string("model_user_all_success"), {get_translated_string("model_user_updated")}) << endl;
        }
      } else {
        cout << get_translated_string("model_user_notfound") << endl;
      }
    };

    /**
     * @brief Delete the user
     * 
     * @return void
     */
    const void delete_user(const string username) {
      using std::fstream;
      using std::stringstream;

      string content = File::read(Path::getPath() + "/user.csv");

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

        if (row[2] == username) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        vector<User> users = this->get();

        fstream outfile(Path::getPath() + "/user.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();

          if (App::APP_DEBUG) {
            cerr << "Error opening file" << endl;
          }
        } else {
          outfile << "";
          outfile.close();

          for (unsigned int i = 0; i < users.size(); i++) {
            if (users[i].get_username() != username) {
              users[i].create(false);
            }
          }

          cout << Sprintf::format(get_translated_string("model_user_all_success"), {get_translated_string("model_user_deleted")}) << endl;
        }
      } else {
        cout << get_translated_string("model_user_notfound") << endl;
      }
    };

    /**
     * @brief Get the string object
     * 
     * @return string 
     */
    const string toString() {
      using std::to_string;

      return "UID: " + this->uid + "\n"
            + "Role: " + this->role + "\n"
            + "Username: " + this->username + "\n"
            + "Password: " + this->password + "\n"
            + "Forgot Question ID: " + to_string(this->forgot_question_id) + "\n"
            + "Forgot Answer: " + this->forgot_answer + "\n";
    };
};

#endif // MODEL_USER_HPP