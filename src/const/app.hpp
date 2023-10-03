#pragma once

#ifndef CONST_APP_HPP
#define CONST_APP_HPP

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Language constant
 * 
 * @namespace Language
 */
bool debug = true;

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
   * @brief Application language
   * 
   * @var string
   */
  const void set_debug(bool value) {
    debug = value;
  };
};

#endif // CONST_APP_HPP