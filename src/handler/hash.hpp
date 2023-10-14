#pragma once

#ifndef HANDLER_HASH_HPP
#define HANDLER_HASH_HPP

using std::string;

/**
 * @brief Hash class to encrypt and decrypt the password
 * 
 * @class Hash
 */
struct Hash {
  /**
   * @brief Encrypt the password
   * 
   * @param user_password string
   * 
   * @return string 
   */
  static string encrypt(const string user_password) {
    using std::to_string;

    int hash = 0;

    for (unsigned int i = 0; i < user_password.length(); i++) {
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
  static bool verify(const string password, const string hash) {
    return hash == encrypt(password);
  }
};

#endif // HANDLER_HASH_HPP