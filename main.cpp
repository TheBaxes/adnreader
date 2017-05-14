#include <getopt.h>
#include <string>

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int avgcov = 0;
  char c;
  bool file = false;
  string filedir;

  while((c = getopt(argc, argv, "a:f:")) != -1) {
    string val;
    switch (c) {
      case 'a':
	val = optarg;
	avgcov = stoi(val);
	break;
      case 'f':
	file = true;
	filedir = optarg;
	break;
      default:
	abort();
    }
  }

  cout << avgcov << " " << file << endl;

  return 0;
}
