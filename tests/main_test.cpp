#include "../src/const/path.hpp"
#include "./helper/uuid_test.hpp"
#include "./storage/file_test.hpp"
#include "./handler/hash_test.hpp"
#include "./helper/sprintf_test.hpp"
#include "./handler/validation_test.hpp"

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

  run_hash_test();
  run_validation_test();
  run_sprintf_test();
  run_uuid_test();
  run_file_test();

  cout << "All tests passed!" << endl;
  return 0;
}