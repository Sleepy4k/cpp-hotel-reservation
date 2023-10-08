#pragma once

#ifndef CONST_APP_HPP
#define CONST_APP_HPP

#include <string>

using std::string;

/**
 * @brief Application debug mode
 * 
 * @var bool
 */
bool debug = false;

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
  const bool APP_DEBUG = debug;

  /**
   * @brief Set application debug mode
   * 
   * @param value bool
   * 
   * @return void
   */
  const void set_debug(const bool value) {
    debug = value;
  };
};

#endif // CONST_APP_HPP