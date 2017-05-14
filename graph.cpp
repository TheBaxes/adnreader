#include "graph.h"
#include <map>
#include <string>
#include <vector>

Graph::Graph(int kmer) :
  nodeAmount(0),
  kmers(kmer)
{}

Graph::~Graph() {}

void Graph::addString(string text) {
  
}

string Graph::getString() {
  return "";
}

vector<string> Graph::chop(string text) {
  vector<string> segments;
  for (int i = 0; i < text.length()-kmers; ++i) {
    segments.push_back(text.substr(i, kmers));
  }
  return segments;
}

bool Graph::isSemiBalanced(int) {

}

bool Graph::isBalanced(int) {

}

void Graph::calculatePath() {

}
