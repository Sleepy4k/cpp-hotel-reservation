#include "../model/user.hpp"
#include "../helper/uuid.hpp"
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
     * @param role string
     * 
     * @return void
     */
    static void register_user(string role = "user") {
      Register register_user = Register();

      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("register_title") << endl;

      string username = Validation::string_validation(get_translated_string("register_input_username"), "username");
      string password = Validation::string_validation(get_translated_string("register_input_password"), "password");
      string confirm_password = Validation::string_validation(get_translated_string("register_input_confirm_password"), "password");

      if (password != confirm_password) {
        cout << get_translated_string("register_input_password_not_same") << endl;
        register_user.register_user();
      } else {
        Hash hash;

        register_user.user.set_uid(UUID::generate_uuid());
        register_user.user.set_role(role);
        register_user.user.set_username(username);
        register_user.user.set_password(hash.encrypt(password));
        Forgot::create_forgot_question(register_user.user);
      }
    }
};

#endif