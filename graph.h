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
  string getString(bool = true);

 private:
  vector<string> chop(string);
  bool calculatePath();
  void eulerPath(int, vector<int>&, vector<bool>&);
  
  int kmers;
  int nodeAmount;
  int nsemi;
  int nbal;
  int nneither;
  int head;
  int tail;
  bool pathFound;
  map<string, int> nodes;
  map<int, string> reverseNodes;
  map<int, pair<int, int> > nodesData;
  vector< map<int, int> > graph;
  vector<int> path;
};
