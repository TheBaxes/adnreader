#include "graph.h"
#include <map>
#include <string>
#include <vector>
#include <cmath>

Graph::Graph(int kmer) :
  nodeAmount(0),
  kmers(kmer),
  nsemi(0),
  nbal(0),
  nneither(0),
  head(0),
  tail(0)
{}

Graph::~Graph() {}

void Graph::addString(string text) {
  vector<string> chops = chop(text);
  map<string, int>::iterator it;
  for (int i = 0; i < chops.size(); i+=2) {
    it = nodes.find(chops[i]);
    int left, right;
    if (it != nodes.end()) {
      left = nodes[chops[i]];
    } else {
      left = nodes[chops[i]] = nodeAmount++;
      reverseNodes[left] = chops[i];
      nodesData[left] = make_pair(0, 0);
      graph.push_back(vector<int>());
    }

    it = nodes.find(chops[i+1]);
    if (it != nodes.end()) {
      right = nodes[chops[i+1]];
    } else {
      left = nodes[chops[i+1]] = nodeAmount++;
      reverseNodes[right] = chops[i+1];
      nodesData[right] = make_pair(0, 0);
      graph.push_back(vector<int>());
    }

    nodesData[left].second++;
    nodesData[right].first++;
    graph[left].push_back(right);
  }
}

string Graph::getString() {
  return "";
}

vector<string> Graph::chop(string text) {
  vector<string> segments;
  for (int i = 0; i < text.length()-kmers; ++i) {
    segments.push_back(text.substr(i, kmers-1));
    segments.push_back(text.substr(i+1, kmers));
  }
  return segments;
}

void Graph::calculatePath() {
  nbal = 0;
  nsemi = 0;
  nneither = 0;
  for (map<int, pair<int,int> >::iterator it=nodesData.begin(); it != nodesData.end(); ++it) {
    int in = it->second.first;
    int out = it->second.out;
    if (in == out) nbal++;
    else if (abs(in - out) == 1) {
      if (in = out + 1) tail = it->first;
      if (im = out - 1) head = it->first;
      nsemi++;
    } else nneither++;
  }

  if(!nneither && (nsemi == 0 || nsemi == 2)) {
    return;
  }

  
  
}
