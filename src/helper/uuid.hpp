#pragma once

#ifndef HANDLER_UUID_HPP
#define HANDLER_UUID_HPP

#include <set>
#include <ctime>
#include <random>

using std::set;
using std::ctime;
using std::string;
using std::mt19937;
using std::uniform_int_distribution;

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
      string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
      mt19937 gen(time(nullptr));
      uniform_int_distribution<> dis(0, characters.length() - 1);

      set<string> generatedUUIDs;
      
      while (true) {
        string uuid;
        int randomize = 2 + (dis(gen) % (5 - 2 + 1));

        for (int i = 0; i < 6 + randomize; i++) {
          uuid += characters[dis(gen)];
        }

        if (generatedUUIDs.find(uuid) == generatedUUIDs.end()) {
          generatedUUIDs.insert(uuid);
          return uuid;
        }
      }
    };
};

#endif // HANDLER_UUID_HPP