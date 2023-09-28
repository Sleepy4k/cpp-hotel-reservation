#include "../model/user.hpp"
#include "../handler/uuid.hpp"
#include "../const/menu_list.hpp"
#include "../handler/validation.hpp"

using namespace std;

#ifndef AUTH_FORGOT_HPP
#define AUTH_FORGOT_HPP

/**
 * @brief Forgot class to forgot the password
 * 
 * @class Forgot
 */
class Forgot {
  public:
    /**
     * @brief Create forgot question
     * 
     * @param user User
     * 
     * @return void
     */
    static void create_forgot_question(User user) {
      vector<string> menu_list = MenuList::FORGOT_MENU;

      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Create Forgot Question" << endl;

      for (int i = 0; i < menu_list.size(); i++) {
        cout << "Press " << i + 1 << " --> " << menu_list[i] << endl;
      }

      Hash hash;
      int menu = Validation::integer_validation(1, menu_list.size());
      string answer = Validation::string_validation("Please Enter Your Answer: ", "forgot_answer");
      answer = hash.encrypt(answer);

      switch (menu) {
        case 1:
          user.set_forgot_question_id(1);
          user.set_forgot_answer(answer);
          break;
        case 2:
          user.set_forgot_question_id(2);
          user.set_forgot_answer(answer);
          break;
        case 3:
          user.set_forgot_question_id(3);
          user.set_forgot_answer(answer);
          break;
        case 4:
          user.set_forgot_question_id(4);
          user.set_forgot_answer(answer);
          break;
        default:
          cout << "Invalid menu" << endl;
          break;
      }

      user.create();
    }

    static void validate_forgot_question(User user) {
      cout << "\n\n--------------------------------------------------------------------" << endl;
      cout << "               " << App::APP_NAME << "                  " << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Validate Forgot Question" << endl;

      switch (user.get_forgot_question_id()) {
        case 1:
          cout << "What was your favorite pet's name?" << endl;
          break;
        case 2:
          cout << "What is your favorite color?" << endl;
          break;
        case 3:
          cout << "What is your favorite food?" << endl;
          break;
        case 4:
          cout << "Who is your favorite person?" << endl;
          break;
      } 

      Hash hash;
      string answer = Validation::string_validation("Please Enter Your Answer: ", "forgot_answer");

      if (hash.decrypt(user.get_forgot_answer()) == answer) {
        string password = Validation::string_validation("Please Enter Your New Password: ", "password");
        string confirm_password = Validation::string_validation("Please Enter Your Confirm New Password: ", "password");

        if (password != confirm_password) {
          cout << "Password and confirm password must be same" << endl;
          return validate_forgot_question(user);
        } else {
          if (hash.verify(password, user.get_password())) {
            cout << "Password must be different from the old password" << endl;
            return validate_forgot_question(user);
          } else {
            user.update(user.get_username(), user.get_password(), hash.encrypt(password));
          }
        }
      } else {
        cout << "Answer is wrong" << endl;
        return validate_forgot_question(user);
      }
    }

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

      string username = Validation::string_validation("Please Enter Your Username: ", "username");

      User user = user.find(username);
      validate_forgot_question(user);
    }
};

#endif