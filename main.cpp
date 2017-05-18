#include <getopt.h>
#include "graph.h"
#include "scanner.h"
#include "gen.h"
#include <string>

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int avglength = 17000;
  int goal = 1000;
  double avgcov = 0.6;
  int segments = 0;
  char c;
  bool file = false;
  string filedir;
  int kmers = 201;
  bool test = false;
  
  while((c = getopt(argc, argv, "g:f:k:t")) != -1) {
    string val;
    switch (c) {
      case 'g':
	val = optarg;
        goal = stoi(val);
	break;
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
	break;
    }
  }

  //cout << avgcov << " " << file << " " << kmers << endl;

  Scanner read;
  if (file) new (&read) Scanner(filedir);

  Graph graph(kmers);
  Gen genes;

  if (test && file) {
    while(read.readLine()) {
      graph.addString(read.getLine());
    }
    genes.leergenes(graph.getString());
  }
  
  while(read.readLine()) {
    graph.addString(read.getLine());
    if (goal > 0) {
      goal--;
    } else {
      genes.leergenes(graph.getString());
    }
  }
  
  return 0;
}
