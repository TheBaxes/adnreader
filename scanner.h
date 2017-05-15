#pragma once

#include <fstream>
#include <string>

using namespace std;

class Scanner {
 public:
  Scanner();
  Scanner(string filetxt);
  ~Scanner();

  bool readLine();
  string getLine();
  int nextInt();
 private:
  string line;
  bool readFile;
  ifstream file;
};
