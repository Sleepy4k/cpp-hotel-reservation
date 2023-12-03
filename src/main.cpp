#include "./const/path.hpp"
#include "./handler/i18n.hpp"
#include "./handler/menu.hpp"

/**
 * @brief Main function of the program
 * 
 * @param argc int
 * @param argv char
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {
  Path::setPath(argv[0]);
  init_language();
  Menu::init();

  return 0;
};