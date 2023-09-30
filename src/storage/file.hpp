#include <cstdio>
#include <fstream>
#include <iostream>
#include "../const/app.hpp"

using namespace std;

#ifndef STORAGE_FILE_HPP
#define STORAGE_FILE_HPP

/**
 * @brief File class to handle file
 * 
 * @class File
 */
class File {
  public:
    /**
     * @brief Create file
     * 
     * @param filename string
     * 
     * @return void
     */
    static void create(string filename) {
      fstream outfile(filename, ios::app);

      if (!outfile) {
        outfile.close();

        if (App::APP_DEBUG) {
          cerr << "Error opening file" << endl;
        }
      }
    }

    /**
     * @brief Read file
     * 
     * @param filename string
     * 
     * @return string 
     */
    static string read(string filename) {
      string line;
      string content = "";
      ifstream file(filename);

      if (!file) {
        file.close();
        create(filename);
        return content;
      }

      while (getline(file, line)) {
        content += line + "\n";
      }

      file.close();

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
    static void write(string filename, string content) {
      ofstream file(filename);

      if (!file) {
        file.close();
        return create(filename);
      }

      file << content;
      file.close();
    }

    /**
     * @brief Delete file
     * 
     * @param filename string
     * 
     * @return void
     */
    static void delete_file(const string filename) {
      int result = remove(filename.c_str());

      if (App::APP_DEBUG) {
        if (result != 0) {
          cerr << "Error deleting file" << endl;
        } else {
          cout << "File successfully deleted" << endl;
        }
      }
    }

    /**
     * @brief Check if file exists
     * 
     * @param filename string
     * 
     * @return bool
     */
    static bool exists(string filename) {
      ifstream file(filename);

      if (!file) {
        file.close();
        return false;
      }

      file.close();

      return true;
    }
};

#endif