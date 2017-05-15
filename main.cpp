#include <getopt.h>
#include "graph.h"
#include "scanner.h"
#include <string>

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int avglength = 17000;
  int goal = 100;
  double avgcov = 0.6;
  int segments = 0;
  char c;
  bool file = false;
  string filedir;
  int kmers = 201;
  bool test = false;
  
  while((c = getopt(argc, argv, "c:l:f:k:t")) != -1) {
    string val;
    switch (c) {
      case 'c':
	val = optarg;
	avgcov = stof(val);
	break;
      case 'l':
	val = optarg;
	avglength = stoi(val);
      case 'f':
	file = true;
	filedir = optarg;
	break;
      case 'k':
	val = optarg;
	kmers = stoi(val);
	break;
      case 't':
	test = true;
	break;
      default:
	abort();
    }
  }

  //cout << avgcov << " " << file << " " << kmers << endl;

  Scanner read;
  if (file) new (&read) Scanner(filedir);

  Graph graph(kmers);

  if (test && file) {
    int finallength;
    read.readLine();
    finallength = stoi(read.getLine());
    while(read.readLine()) {
      graph.addString(read.getLine());
      if (++segments >= goal) {
	goal += segments / 2;
	//cout << graph.getString().size() << endl;
      }
    }
    cout << graph.getStr