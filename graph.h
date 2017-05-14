#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class Graph {
 public:
  Graph(int);
  ~Graph();

  void addString(string);
  string getString();

 private:
  void calculatePath();
  vector<string> chop(string);
  
  int kmers;
  int nodeAmount;
  map<string, int> nodes;
  map<int, pair<int, int> > nodesData;
  vector< vector<int> > graph;
};
