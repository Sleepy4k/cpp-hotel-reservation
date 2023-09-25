#include <fstream>
#include "../handler/menu.hpp"

using namespace std;

#ifndef FILE_HPP
#define FILE_HPP

class File {
  public:
    /**
     * @brief Create file
     * 
     * @param filename string
     * 
     * @return void
     */
    void static create(string filename) {
      fstream outfile(filename, ios::app);

      if (!outfile) {
        outfile.close();

        if (App::APP_DEBUG) {
          cerr << "Error opening file" << endl;
        }

        Menu::main_menu();
      }
    }

    /**
     * @brief Read file
     * 
     * @param filename string
     * 
     * @return string 
     */
    string static read(string filename) {
      string line;
      string content = "";

      ifstream file(filename);

      if (file.is_open()) {
        while (getline(file, line)) {
          content += line + "\n";
        }

        file.close();
      } else {
        create(filename);
      }

      return content;
    }

    /**
     * @brief Write file
     * 
     * @param filename string
     * @param content string
     * 
     * @return void
     */
    void static write(string filename, string content) {
      ofstream file(filename);

      if (file.is_open()) {
        file << content;
        file.close();
      } else {
        create(filename);
      }
    }
};

#endif