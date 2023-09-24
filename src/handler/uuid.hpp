#include <ctime>
#include <string>

using namespace std;

#ifndef UUID_HPP
#define UUID_HPP

class UUID {
  public:
    /**
     * @brief Generate UUID
     * 
     * @return string
     */
    string static generate_uuid() {
      string uuid;
      srand(time(NULL));
      string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

      int randomize = 2 + ( std::rand() % ( 5 - 2 + 1 ) );

      for (int i = 0; i < 6 + randomize; i++) {
        uuid += characters[rand() % characters.length()];
      }

      return uuid;
    }
};

#endif