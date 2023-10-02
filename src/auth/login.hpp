#include "forgot.hpp"
#include "../dashboard/user.hpp"
#include "../dashboard/admin.hpp"
#include "../handler/validation.hpp"

using namespace std;

#ifndef AUTH_LOGIN_HPP
#define AUTH_LOGIN_HPP

/**
 * @brief Login class to login the user
 * 
 * @class Login
 */
class Login {
  public:
    /**
     * @brief Confirm forgot password
     * 
     * @param is_admin bool
     * 
     * @return void
     */
    static void confirm(bool is_admin) {
      cout << get_translated_string("login_confirm_question") << endl;
      string confirmation = Validation::string_validation(get_translated_string("login_confirm_input_confirm"), "confirmation");

      if (confirmation == "y") {
        Forgot::forgot_password();
      } else if (confirmation == "n") {
        return login(is_admin);
      } else {
        cout << get_translated_string("login_confirm_input_invalid") << endl;
        return confirm(is_admin);
      }
    };

    /**
     * @brief Login user
     * 
     * @param is_admin bool
     * @param error int
     * 
     * @return void
     */
    static void login(bool is_admin, int error = 0) {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << get_translated_string(App::APP_NAME) << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << get_translated_string("login_title") << endl;

      string username = Validation::string_validation(get_translated_string("login_input_username"), "username");
      string password = Validation::string_validation(get_translated_string("login_input_password"), "password");

      User user = user.find(username);
      bool isAdmin = (user.get_role() == "admin");

      if (Hash::verify(password, user.get_password())) {
        if (is_admin && isAdmin) {
          return AdminDashboard::dashboard(user);
        } else if (!is_admin && !isAdmin) {
          return UserDashboard::dashboard(user);
        } else {
          cout << get_translated_string("login_not_admin") << endl;
          return login(is_admin);
        }
      } else {
        cout << get_translated_string("login_invalid_password") << endl;

        if (error < 2) {
          return login(is_admin, error + 1);
        } else {
          return confirm(is_admin);
        }
      }
    };
};

#endif