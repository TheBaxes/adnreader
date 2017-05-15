#include <fstream>
#include <string>
#include <iostream>
#include "scanner.h"

using namespace std;

Scanner::Scanner() :
  readFile(false),
  line("")
{}

Scanner::Scanner(string filetxt) :
  readFile(true),
  line("")
{
  file.open(filetxt.c_str());
}

Scanner::~Scanner() {
  file.close();
}

bool Scanner::readLine() {
  line = "";
  if (readFile) {
    while (line == "" && file.is_open() && !file.eof()) {
      file >> line;
    }
  } else {
    while (line == "" && cin >> line);
  }
  return line != "";
}

string Scanner::getLine() {
  return line;
}

int Scanner::nextInt() {
  int num = 0;
  if (readFile) {
    if (file.is_open()) {
      file >> num;
    }
  } else {
    cin >> num;
  }
  return num;
}
