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
      cout << "Forgot your password? (y/n)" << endl;
      string confirmation = Validation::string_validation("Please Enter Your Confirmation: ", "confirmation");

      if (confirmation == "y") {
        Forgot::forgot_password();
      } else if (confirmation == "n") {
        return login(is_admin);
      } else {
        cout << "Confirmation must be y or n" << endl;
        return confirm(is_admin);
      }
    }

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
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Login Your Account" << endl;

      string username = Validation::string_validation("Please Enter Your Username: ", "username");
      string password = Validation::string_validation("Please Enter Your Password: ", "password");

      Hash hash;
      User user = user.find(username);
      bool isAdmin = (user.get_role() == "admin");

      if (hash.verify(password, user.get_password())) {
        if (is_admin && isAdmin) {
          return AdminDashboard::dashboard(user);
        } else if (!is_admin && !isAdmin) {
          return UserDashboard::dashboard(user);
        } else {
          cout << "You are not admin" << endl;
          return login(is_admin);
        }
      } else {
        cout << "Password is wrong" << endl;

        if (error < 2) {
          return login(is_admin, error + 1);
        } else {
          return confirm(is_admin);
        }
      }
    }
};

#endif