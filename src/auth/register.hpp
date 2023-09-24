#include "../model/user.hpp"

using namespace std;

#ifndef REGISTER_HPP
#define REGISTER_HPP

class Register {
  private:
    User user;
  public:
    /**
     * @brief Construct a new Register object
     */
    Register() {
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
     * @brief Register user
     * 
     * @return void
     */
    void static register_user() {
      cout << "Register" << endl;
    }
};

#endif