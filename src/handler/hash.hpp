#include <string>

using namespace std;

#ifndef HANDLER_HASH_HPP
#define HANDLER_HASH_HPP

class Hash {
  private:
    int key = 3;
    char password[50];
    char encrypted_password[100];

  public:
    /**
     * @brief Encrypt the password
     * 
     * @param user_password string
     * 
     * @return string 
     */
    string encrypt(string user_password) {
      strcpy(password, user_password.c_str());

      for (int i = 0; (i < 100 && password[i] != '\0'); i++) {
        encrypted_password[i] = password[i] + key;
      }

      return encrypted_password;
    }

    /**
     * @brief Decrypt the password
     * 
     * @param hash_password string
     * 
     * @return string 
     */
    string decrypt(string hash_password) {
      strcpy(encrypted_password, hash_password.c_str());

      for (int i = 0; (i < 100 && encrypted_password[i] != '\0'); i++) {
        password[i] = encrypted_password[i] - key;
      }

      return password;
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
    bool verify(string password, string hash) {
      return (hash == encrypt(password));
    }
};

#endif