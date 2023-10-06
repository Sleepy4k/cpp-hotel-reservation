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

  cout << "Running hash tests..." << endl;
  run_hash_test();
  cout << "Hash tests passed!" << endl;

  cout << "Running validation tests..." << endl;
  run_validation_test();
  cout << "Validation tests passed!" << endl;

  cout << "Running sprintf tests..." << endl;
  run_sprintf_test();
  cout << "Sprintf tests passed!" << endl;

  cout << "Running uuid tests..." << endl;
  run_uuid_test();
  cout << "Uuid tests passed!" << endl;

  cout << "Running file tests..." << endl;
  run_file_test();
  cout << "File tests passed!" << endl;

  cout << "All tests passed!" << endl;
  return 0;
}