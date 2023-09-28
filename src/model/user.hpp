#include <sstream>
#include "../const/path.hpp"
#include "../handler/hash.hpp"
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
     * @param uid 
     * @param role 
     * @param username 
     * @param password 
     * @param forgot_question_id
     * @param forgot_answer
     * 
     * @return void
     */
    User(string uid, string role, string username, string password, int forgot_question_id = 0, string forgot_answer = "") {
      this->uid = uid;
      this->role = role;
      this->username = username;
      this->password = password;
      this->forgot_question_id = forgot_question_id;
      this->forgot_answer = forgot_answer;
    }

    /**
     * @brief Construct a new User object
     */
    User() {
      this->uid = "";
      this->role = "";
      this->username = "";
      this->password = "";
      this->forgot_question_id = 0;
      this->forgot_answer = "";
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
     * @brief Set the forgot question id object
     * 
     * @param forgot_question_id int
     * 
     * @return void
     */
    void set_forgot_question_id(int forgot_question_id) {
      this->forgot_question_id = forgot_question_id;
    }

    /**
     * @brief Set the forgot answer object
     * 
     * @param forgot_answer string
     * 
     * @return void
     */
    void set_forgot_answer(string forgot_answer) {
      this->forgot_answer = forgot_answer;
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
     * @brief Get the forgot question id object
     * 
     * @return int 
     */
    int get_forgot_question_id() {
      return this->forgot_question_id;
    }

    /**
     * @brief Get the forgot answer object
     * 
     * @return string 
     */
    string get_forgot_answer() {
      return this->forgot_answer;
    }

    /**
     * @brief Get all the user
     * 
     * @return vector<string> 
     */
    vector<User> get() {
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
    }

    /**
     * @brief Create the user
     * 
     * @return void
     */
    void create(bool allow_print = true) {
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
          outfile << this->uid << "," << this->role << "," << this->username << "," << this->password << "," << this->forgot_question_id << "," << this->forgot_answer << endl;
          outfile.close();

          if (allow_print) {
            cout << "User created successfully" << endl;
          }
        }
      }
    }

    /**
     * @brief Get the user object
     * 
     * @param username string
     * 
     * @return User
     */
    User find(string username) {
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
    }

    /**
     * @brief Update the user
     * 
     * @return void
     */
    void update(string username, string old_password, string new_password) {
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
          cerr << "Error opening file" << endl;
        } else {
          outfile << "";
          outfile.close();

          for (int i = 0; i < users.size(); i++) {
            if (users[i].get_username() == username) {
              users[i].set_password(new_password);
            }

            users[i].create(false);
          }

          cout << "User updated successfully" << endl;
        }
      } else {
        cout << "User not found" << endl;
      }
    }

    /**
     * @brief Delete the user
     * 
     * @return void
     */
    void delete_user(string username, string password) {
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

        if (row[2] == username && row[3] == password) {
          is_exist = true;
        }

        row.clear();
      }

      if (is_exist) {
        vector<User> users = this->get();

        fstream outfile(Path::getPath() + "/user.csv", ios::out | ios::trunc);

        if (!outfile) {
          outfile.close();
          cerr << "Error opening file" << endl;
        } else {
          outfile << "";
          outfile.close();

          for (int i = 0; i < users.size(); i++) {
            if (users[i].get_username() != username) {
              users[i].create(false);
            }
          }

          cout << "User deleted successfully" << endl;
        }
      } else {
        cout << "User not found" << endl;
      }
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
            + "Password: " + this->password + "\n"
            + "Forgot Question ID: " + to_string(this->forgot_question_id) + "\n"
            + "Forgot Answer: " + this->forgot_answer + "\n";
    }
};

#endif