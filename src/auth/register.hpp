#include "../model/user.hpp"
#include "../handler/uuid.hpp"
#include "../handler/hash.hpp"
#include "../handler/validation.hpp"

using namespace std;

#ifndef AUTH_REGISTER_HPP
#define AUTH_REGISTER_HPP

/**
 * @brief Register class to register the user
 * 
 * @class Register
 */
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
    static void register_user() {
      Register register_user = Register();

      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Register Your Account" << endl;

      string username = Validation::string_validation("username");
      string password = Validation::string_validation("password");
      string confirm_password = Validation::string_validation("password_confirmation");

      if (password != confirm_password) {
        cout << "Password and confirm password must be same" << endl;
        register_user.register_user();
      } else {
        Hash hash;

        register_user.user.uid = UUID::generate_uuid();
        register_user.user.role = "user";
        register_user.user.username = username;
        register_user.user.password = hash.encrypt(password);
        register_user.user.create();

        cout << "Register success" << endl;
        Login::login(false);
      }
    }
};

#endif