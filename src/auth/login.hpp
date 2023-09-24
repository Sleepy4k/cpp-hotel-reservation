#include "../model/user.hpp"

using namespace std;

#ifndef LOGIN_HPP
#define LOGIN_HPP

class Login {
  private:
    User user;
  public:
    /**
     * @brief Construct a new Login object
     */
    Login() {
      this->user = User();
    }

    /**
     * @brief Set the user object
     * 
     * @param user User
     * 
     * @return void
     */
    void set_user(User user) {
      this->user = user;
    }

    /**
     * @brief Get the user object
     * 
     * @return User
     */
    User get_user() {
      return this->user;
    }

    /**
     * @brief Login user
     * 
     * @param is_admin bool
     * 
     * @return void
     */
    void static login(bool is_admin) {
      if (is_admin) {
        cout << "Admin Login" << endl;
      } else {
        cout << "User Login" << endl;
      }
    }
};

#endif