#include <string>
#include <iostream>
#include "../model/user.hpp"

using namespace std;

#ifndef DASHBOARD_USER_HPP
#define DASHBOARD_USER_HPP

/**
 * @brief UserDashboard class to handle user dashboard
 * 
 * @class UserDashboard
 */
class UserDashboard {
  public:
    /**
     * @brief Show the user dashboard
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      cout << "User Dashboard" << endl;
      cout << "Welcome " << user.get_username() << endl;
    }
};

#endif