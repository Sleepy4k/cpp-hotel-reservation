#include "../handler/hash.hpp"
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
    static void login(bool is_admin) {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Login Your Account" << endl;

      string username = Validation::string_validation("username");
      string password = Validation::string_validation("password");

      User user = user.get_user(username, password);

      if (user.get_username() == "") {
        cout << "Username not found" << endl;
        login(is_admin);
      } else {
        Hash hash;
        bool isAdmin = (user.get_role() == "admin");

        if (hash.verify(password, user.get_password())) {
          if (is_admin && isAdmin) {
            AdminDashboard::dashboard(user);
          } else if (!is_admin && !isAdmin) {
            UserDashboard::dashboard(user);
          } else {
            cout << "You are not admin" << endl;
            login(is_admin);
          }
        } else {
          cout << "Password is wrong" << endl;
          login(is_admin);
        }
      }
    }
};

#endif