#pragma once

#ifndef HANDLER_GETKY_HPP
#define HANDLER_GETKY_HPP

#ifdef _WIN32
  #include <conio.h>
#else
  #include <unistd.h>
  #include <termios.h>
#endif

/**
 * @brief Get keyboard input
 * 
 * @class Getky
 */
struct Getky {
  /**
   * @brief Pause program until user press any key
   * 
   * @return void
  */
  static void pause() {
    cout << '\n' << get_translated_string("press_any_key_to_continue") << endl;

    #ifdef _WIN32
      getch();
    #else
      struct termios oldt, newt;

      tcgetattr(STDIN_FILENO, &oldt);

      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);

      tcsetattr(STDIN_FILENO, TCSANOW, &newt);

      getchar();

      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #endif

    return;
  }
};

#endif // HANDLER_GETKY_HPP