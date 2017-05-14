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
  vector<string> chop(string);
  void calculatePath();
  
  int kmers;
  int nodeAmount;
  int nsemi;
  int nbal;
  int nneither;
  int head;
  int tail;
  map<string, int> nodes;
  map<int, string> reverseNodes;
  map<int, pair<int, int> > nodesData;
  vector< vector<int> > graph;
};
