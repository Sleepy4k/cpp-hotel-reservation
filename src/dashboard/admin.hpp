#include <string>
#include <iostream>
#include "../model/user.hpp"

using namespace std;

#ifndef DASHBOARD_ADMIN_HPP
#define DASHBOARD_ADMIN_HPP

/**
 * @brief AdminDashboard class to handle admin dashboard
 * 
 * @class AdminDashboard
 */
class AdminDashboard {
  public:
    /**
     * @brief Show the admin dashboard
     * 
     * @param user User
     * 
     * @return void
     */
    static void dashboard(User user) {
      cout << "Admin Dashboard" << endl;
      cout << "Welcome " << user.get_username() << endl;
    }
};

#endif