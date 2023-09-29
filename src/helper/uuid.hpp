#include <ctime>
#include <string>

using namespace std;

#ifndef HANDLER_UUID_HPP
#define HANDLER_UUID_HPP

/**
 * @brief UUID class to generate UUID
 * 
 * @class UUID
 */
class UUID {
  public:
    /**
     * @brief Generate UUID
     * 
     * @return string
     */
    static string generate_uuid() {
      string uuid = "";
      srand(time(NULL));
      string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

      int randomize = 2 + (std::rand() % (5 - 2 + 1));

      for (int i = 0; i < 6 + randomize; i++) {
        uuid += characters[rand() % characters.length()];
      }

      return uuid;
    }
};

#endif