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
     * @brief Forgot password
     * 
     * @return void
     */
    static void forgot_password() {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Forgot Your Password" << endl;

      string username = Validation::string_validation("username");
      string password = Validation::string_validation("password");
      string confirm_password = Validation::string_validation("password_confirmation");

      if (password != confirm_password) {
        cout << "Password and confirm password must be same" << endl;
        return forgot_password();
      } else {
        User user = user.find(username);

        if (user.get_username() == "") {
          cout << "Username not found" << endl;
          return forgot_password();
        } else {
          Hash hash;

          if (hash.verify(password, user.get_password())) {
            cout << "Password must be different from the old password" << endl;
            return forgot_password();
          } else {
            user.update(username, user.get_password(), hash.encrypt(password));
          }
        }
      }
    }

    /**
     * @brief Confirm forgot password
     * 
     * @param is_admin bool
     * 
     * @return void
     */
    static void confirm(bool is_admin) {
      cout << "Forgot your password? (y/n)" << endl;
      string confirmation = Validation::string_validation("confirmation");

      if (confirmation == "y") {
        return forgot_password();
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
     * 
     * @return void
     */
    static void login(bool is_admin) {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Login Your Account" << endl;

      string username = Validation::string_validation("username");
      string password = Validation::string_validation("password");

      User user = user.find(username);

      if (user.get_username() == "") {
        cout << "Username not found" << endl;
      } else {
        Hash hash;
        bool isAdmin = (user.get_role() == "admin");

        if (hash.verify(password, user.get_password())) {
          if (is_admin && isAdmin) {
            return AdminDashboard::dashboard(user);
          } else if (!is_admin && !isAdmin) {
            return UserDashboard::dashboard(user);
          } else {
            cout << "You are not admin" << endl;
          }
        } else {
          cout << "Password is wrong" << endl;
          return confirm(is_admin);
        }
      }

      return login(is_admin);
    }
};

#endif