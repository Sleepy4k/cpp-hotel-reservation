#pragma once

#ifndef HANDLER_UUID_HPP
#define HANDLER_UUID_HPP

#include <ctime>
#include <random>
#include <unordered_set>

using std::ctime;
using std::string;

/**
 * @brief UUID class to generate UUID
 * 
 * @class UUID
 */
class UUID {
  private:
    /**
     * @brief Characters to generate UUID
     * 
     * @var char[]
     */
    static constexpr char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    /**
     * @brief Length of characters
     * 
     * @var size_t
     */
    static constexpr size_t charArrayLength = sizeof(characters) - 1;

  public:
    /**
     * @brief Generate UUID
     * 
     * @return string
     */
    static string generate_uuid() {
      using std::mt19937;
      using std::unordered_set;

      static mt19937 gen(time(nullptr));
      static unordered_set<string> generatedUUIDs;

      int maxAttempts = 10000;
      
      while (maxAttempts--) {
        string uuid;
        int randomize = 2 + (gen() % (5 - 2 + 1));

        for (int i = 0; i < 6 + randomize; i++) {
          uuid += characters[gen() % charArrayLength];
        }

        if (generatedUUIDs.find(uuid) == generatedUUIDs.end()) {
          generatedUUIDs.insert(uuid);
          return uuid;
        }
      }

      return "";
    };
};

/**
 * @brief Characters to generate UUID
 * 
 * @var char[]
 */
constexpr char UUID::characters[];

#endif // HANDLER_UUID_HPP