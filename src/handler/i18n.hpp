#pragma once

#include <stdexcept>
#include "../lang/en.hpp"
#include "../lang/id.hpp"

using namespace std;

#ifndef HANDLER_I18N_HPP
#define HANDLER_I18N_HPP

/**
 * @brief Language enum class
 * 
 * @enum Language
 */
enum class Language {
  ENGLISH,
  INDONESIA
};

/**
 * @brief Supported language
 * 
 * @var Language
 */
Language supported_language = Language::ENGLISH;

/**
 * @brief Get the translated string
 * 
 * @param key string
 * 
 * @return string
 */
string get_translated_string(const string& key) {
  switch (supported_language) {
    case Language::ENGLISH:
      return (english_translations.find(key) != english_translations.end()) ? english_translations.at(key) : key;
    case Language::INDONESIA:
      return (indonesian_translations.find(key) != indonesian_translations.end()) ? indonesian_translations.at(key) : key;
    default:
      throw runtime_error("Unsupported language");
  }
};

/**
 * @brief Set the language
 * 
 * @param language Language
 * 
 * @return string
 */
string set_language(Language language) {
  supported_language = language;
  return language == Language::ENGLISH ? "ENGLISH" : "INDONESIA";
};

#endif