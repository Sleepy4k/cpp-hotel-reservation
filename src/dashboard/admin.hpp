#include <string>
#include <iostream>
#include "../model/user.hpp"

using namespace std;

#ifndef DASHBOARD_ADMIN_HPP
#define DASHBOARD_ADMIN_HPP

class AdminDashboard {
  public:
    static void dashboard(User user) {
      cout << "Admin Dashboard" << endl;
      cout << "Welcome " << user.get_username() << endl;
    }
};

#endif