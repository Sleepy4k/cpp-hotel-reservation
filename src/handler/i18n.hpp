#pragma once

#include <stdexcept>
#include "../lang/en.hpp"
#include "../lang/id.hpp"
#include "../storage/file.hpp"
#include "../enum/language.hpp"

using namespace std;

#ifndef HANDLER_I18N_HPP
#define HANDLER_I18N_HPP

/**
 * @brief Supported language
 * 
 * @var Language
 */
Language supported_language;

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
 * @brief Change the language
 * 
 * @return void
 */
void change_language() {
  File::write(Path::getPath() + "/language.txt", (supported_language == Language::ENGLISH) ? "ENGLISH" : "INDONESIA");
}

/**
 * @brief Set the language
 * 
 * @param language Language
 * 
 * @return string
 */
string set_language(Language language) {
  supported_language = language;
  change_language();
  return language == Language::ENGLISH ? "ENGLISH" : "INDONESIA";
};

/**
 * @brief Get the language
 * 
 * @return Language
 */
void init_language() {
  string language = File::read(Path::getPath() + "/language.txt");
  language = language.substr(0, language.length() - 1);

  if (language == "ENGLISH") {
    supported_language = Language::ENGLISH;
  } else if (language == "INDONESIA") {
    supported_language = Language::INDONESIA;
  } else {
    supported_language = Language::ENGLISH;
  }

  change_language();
}

#endif