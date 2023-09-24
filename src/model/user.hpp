#include <string>
#include <iostream>

using namespace std;

#ifndef USER_HPP
#define USER_HPP

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