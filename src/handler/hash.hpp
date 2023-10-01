#include <string>

using namespace std;

#ifndef HANDLER_HASH_HPP
#define HANDLER_HASH_HPP

/**
 * @brief Hash class to encrypt and decrypt the password
 * 
 * @class Hash
 */
class Hash {
  public:
    /**
     * @brief Encrypt the password
     * 
     * @param user_password string
     * 
     * @return string 
     */
    static string encrypt(string user_password) {
      unsigned int hash = 0;

      for (int i = 0; i < user_password.length(); i++) {
        hash ^= (hash << 5) + (hash >> 2) + user_password[i];
      }

      return to_string(hash);
    }

    /**
     * @brief Verify the password
     * 
     * @param password string 
     * @param hash stirng
     * 
     * @return true 
     * @return false 
     */
    static bool verify(string password, string hash) {
      return hash == encrypt(password);
    }
};

#endif