#include <string>
#include <iostream>
#include "../handler/i18n.hpp"

using namespace std;

#ifndef CONST_APP_HPP
#define CONST_APP_HPP

/**
 * @brief Application constant
 * 
 * @namespace App
 */
namespace App {
  /**
   * @brief Application name, dont edit this
   * 
   * @var string
   */
  const string APP_NAME = "app_name";

  /**
   * @brief Application debug mode
   * 
   * @var bool
   */
  const bool APP_DEBUG = true;

  /**
   * @brief Application language
   * 
   * @var string
   */
  const string APP_LANGUAGE = set_language(Language::INDONESIA);
};

#endif