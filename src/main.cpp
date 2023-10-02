//=================================================================================
// Hotel Reservation System
//--------------------------------------------------------------------------------
// By:
// 1. Apri Pandu Wicaksono (NIM: 2311102081)
//=================================================================================

#include "./const/path.hpp"
#include "./handler/i18n.hpp"
#include "./handler/menu.hpp"

using namespace std;

/**
 * @brief Main function of the program
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {
  Path::setPath(argv[0]);
  init_language();
  Menu::main_menu();

  return 0;
};