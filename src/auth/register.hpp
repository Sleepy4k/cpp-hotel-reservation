#include "../model/user.hpp"
#include "../handler/uuid.hpp"
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
    /**
     * @brief User
     * 
     * @var User
     */
    User user;

  public:
    /**
     * @brief Construct a new Register object
     */
    Register() {
      this->user = User();
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

      string username = Validation::string_validation("Please Enter Your Username: ", "username");
      string password = Validation::string_validation("Please Enter Your Password: ", "password");
      string confirm_password = Validation::string_validation("Please Enter Your Confirm Password: ", "password");

      if (password != confirm_password) {
        cout << "Password and confirm password must be same" << endl;
        register_user.register_user();
      } else {
        Hash hash;

        register_user.user.set_uid(UUID::generate_uuid());
        register_user.user.set_role("user");
        register_user.user.set_username(username);
        register_user.user.set_password(hash.encrypt(password));
        Forgot::create_forgot_question(register_user.user);
      }
    }
};

#endif