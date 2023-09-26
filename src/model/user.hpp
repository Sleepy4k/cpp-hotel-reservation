#include <sstream>
#include "../const/path.hpp"
#include "../storage/file.hpp"

using namespace std;

#ifndef MODEL_USER_HPP
#define MODEL_USER_HPP

/**
 * @brief User struct to store the user data
 * 
 * @struct User
 */
struct User {
  string uid;
  string role;
  string username;
  string password;

  /**
   * @brief Construct a new User object
   * 
   * @param uid 
   * @param role 
   * @param username 
   * @param password 
   */
  User(string uid, string role, string username, string password) {
    this->uid = uid;
    this->role = role;
    this->username = username;
    this->password = password;
  }

  /**
   * @brief Construct a new User object
   */
  User() {
    this->uid = "";
    this->role = "";
    this->username = "";
    this->password = "";
  }

  /**
   * @brief Get the user object
   * 
   * @param username string
   * @param password string
   * 
   * @return User
   */
  User get_user(string username, string password) {
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
        user = User(row[0], row[1], row[2], row[3]);
      }

      row.clear();
    }

    return user;
  }

  /**
   * @brief Create the user
   * 
   * @return void
   */
  void create() {
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
      cout << "Username already exist" << endl;
      return;
    } else {
      fstream outfile(Path::getPath() + "/user.csv", ios::app);

      if (!outfile) {
        outfile.close();
        cerr << "Error opening file" << endl;
      } else {
        outfile << this->uid << "," << this->role << "," << this->username << "," << this->password << endl;
        outfile.close();
        cout << "User created successfully" << endl;
      }
    }
  }

  /**
   * @brief Set the uid object
   * 
   * @param uid string
   * 
   * @return void
   */
  void set_uid(string uid) {
    this->uid = uid;
  }

  /**
   * @brief Set the role object
   * 
   * @param role string
   * 
   * @return void
   */
  void set_role(string role) {
    this->role = role;
  }

  /**
   * @brief Set the username object
   * 
   * @param username string
   * 
   * @return void
   */
  void set_username(string username) {
    this->username = username;
  }

  /**
   * @brief Set the password object
   * 
   * @param password string
   * 
   * @return void
   */
  void set_password(string password) {
    this->password = password;
  }

  /**
   * @brief Get the uid object
   * 
   * @return string 
   */
  string get_uid() {
    return this->uid;
  }

  /**
   * @brief Get the role object
   * 
   * @return string 
   */
  string get_role() {
    return this->role;
  }

  /**
   * @brief Get the username object
   * 
   * @return string 
   */
  string get_username() {
    return this->username;
  }

  /**
   * @brief Get the password object
   * 
   * @return string 
   */
  string get_password() {
    return this->password;
  }

  /**
   * @brief Get the string object
   * 
   * @return string 
   */
  string toString() {
    return "UID: " + this->uid + "\n"
           + "Role: " + this->role + "\n"
           + "Username: " + this->username + "\n"
           + "Password: " + this->password;
  }
};


#endif