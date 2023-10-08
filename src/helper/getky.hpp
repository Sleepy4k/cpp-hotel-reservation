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
class Getky {
  public:
    /**
     * @brief Pause program until user press any key
     * 
     * @return void
    */
    static void pause() {
      #ifdef _WIN32
        return getch();
      #else
        int ch;
        struct termios oldt, newt;

        // Save terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // Disable canonical mode and echo
        newt.c_lflag &= ~(ICANON | ECHO);

        // Apply new settings
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // Read character
        ch = getchar();

        // Restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return;
      #endif
    };
};

#endif // HANDLER_GETKY_HPP