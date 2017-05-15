#include "graph.h"
#include <map>
#include <string>
#include <vector>
#include <cmath>

#include <iostream>

Graph::Graph(int kmer) :
  nodeAmount(0),
  kmers(kmer),
  nsemi(0),
  nbal(0),
  nneither(0),
  head(0),
  tail(0),
  pathFound(false)
{}

Graph::~Graph() {}

void Graph::addString(string text) {
  vector<string> chops = chop(text);
  map<string, int>::iterator it;
  for (int i = 0; i < chops.size()-1; ++i) {
    int left, right;

    it = nodes.find(chops[i]);
    if (it != nodes.end()) {
      left = nodes[chops[i]];
    } else {
      left = nodes[chops[i]] = nodeAmount++;
      reverseNodes[left] = chops[i];
      nodesData[left] = make_pair(0, 0);
      graph.push_back(map<int, int>());
    }

    it = nodes.find(chops[i+1]);
    if (it != nodes.end()) {
      right = nodes[chops[i+1]];
    } else {
      right = nodes[chops[i+1]] = nodeAmount++;
      reverseNodes[right] = chops[i+1];
      nodesData[right] = make_pair(0, 0);
      graph.push_back(map<int, int>());
    }

    nodesData[left].second++;
    nodesData[right].first++;
    ++graph[left][right];
  }
}

string Graph::getString(bool recalc) {
  if (!pathFound || recalc) pathFound = calculatePath();
  if (!pathFound) return "";

  string result = "";
  for (int i = path.size()-1; i > 0; --i) {
    result += reverseNodes[path[i]][0];
  }
  result += reverseNodes[path[0]];
  return result;
}

vector<string> Graph::chop(string text) {
  vector<string> segments;
  for (int i = 0; i < text.length()-kmers+1; ++i) {
    segments.push_back(text.substr(i, kmers-1));
  }
  return segments;
}

bool Graph::calculatePath() {
  nbal = 0;
  nsemi = 0;
  nneither = 0;
  
  for (map<int, pair<int,int> >::iterator it=nodesData.begin();
       it != nodesData.end(); ++it) {
    #ifdef debug
    cout << it->first << " " << it->second.first << " "<< it->second.second << endl;
    #endif
    int in = it->second.first;
    int out = it->second.second;
    if (in == out) nbal++;
    else if (abs(in - out) == 1) {
      if (in = out + 1) tail = it->first;
      else if (in = out - 1) head = it->first;
      nsemi++;
    } else nneither++;
  }

  if(!nneither && (nsemi != 0 && nsemi != 2)) {
    return false;
  }

  if (nsemi == 0) {
    head = 0;
  }
  
  vector<int> circuit;
  map<int, bool> visited;
  eulerPath(head, circuit, visited);
  path = circuit;
  
  return true;
}

void Graph::eulerPath(int n, vector<int>& circuit, map<int, bool>& visited) {
  #ifdef debug
  cout << n << endl;
  cout << graph[n].size() << endl;
  #endif
  visited[n] = true;
  for (map<int, int>::iterator it=graph[n].begin(); it != graph[n].end();
       ++it) {
    if (!visited[it->first])
      eulerPath(it->first, circuit, visited);
  }
  circuit.push_back(n);
}