#include <string>
#include <iostream>
#include "../model/user.hpp"

using namespace std;

#ifndef DASHBOARD_USER_HPP
#define DASHBOARD_USER_HPP

class UserDashboard {
  public:
    static void dashboard(User user) {
      cout << "User Dashboard" << endl;
      cout << "Welcome " << user.get_username() << endl;
    }
};

#endif