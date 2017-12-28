#include "07_recursive_circus.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>

Node RecursiveCircus::parseLine(const std::string& line) {
  std::string name, weight, token;
  Node n;
  std::istringstream iss(line);
  char c;
  iss >> n.name >> c >> n.weight >> c >> token;
  if (not token.empty()) {
    while (iss >> token) {
      if (*token.rbegin() == ',') {
        n.children.push_back(token.substr(0, token.size() - 1));
      }
      else {
        n.children.push_back(token);
      }
    }
  }
  return n;
}

void RecursiveCircus::buildTree(const std::string& input) {
  std::stringstream iss(input);
  std::string line;
  while (getline(iss, line)) {
    Node n       = parseLine(line);
    tree[n.name] = n;

    heap.push(n.name);
  }
}

void RecursiveCircus::buildLink() {
  while (not heap.empty()) {
    auto n = heap.front();
    heap.pop();
    for (auto child : tree[n].children) {
      tree[child].parent = n;
    }
  }
}

std::string RecursiveCircus::retrieveRoot(const std::string& item) {
  Node n = tree[item];
  if (n.parent.empty()) {
    return n.name;
  }
  return retrieveRoot(n.parent);
}

std::string RecursiveCircus::computeRootNode(const std::string& input) {
  buildTree(input);
  buildLink();
  return retrieveRoot(tree.begin()->first);
}

int RecursiveCircus::retrieveSubTreeWeight(const std::string& item) {
  Node n     = tree[item];
  int weight = n.weight;
  for (auto child : n.children) {
    weight += retrieveSubTreeWeight(child);
  }
  return weight;
}

std::tuple<int, bool> RecursiveCircus::retrieveBalanceWeight(const std::string& item) {
  Node n = tree[item];

  // base case: no children
  if (n.children.empty()) {
    return std::make_tuple(n.weight, true);
  }

  std::vector<int> weights(n.children.size(), 0);
  size_t i = 0;
  for (auto child : n.children) {
    int w        = retrieveSubTreeWeight(child);
    weights[i++] = w;
  }
  int minel = *std::min_element(weights.begin(), weights.end());
  int maxel = *std::max_element(weights.begin(), weights.end());

  // look for tree that differ
  int reference_weight = maxel;
  int delta            = maxel - minel;
  if (std::count(weights.begin(), weights.end(), maxel) == 1) {
    reference_weight = minel;
    delta *= -1;
  }

  i = 0;
  for (auto child : n.children) {
    // for the only tree that differ, we call the method recursively
    if (weights[i] != reference_weight) {
      auto wd = retrieveBalanceWeight(child);
      // the first time that we have a new value (i.e. the node which have balanced subtree)
      // we add the delta
      // for all other calls we just propagate below the computed value
      if (std::get<1>(wd)) {
        return std::make_tuple(std::get<0>(wd), true);
      }
      else {
        return std::make_tuple(std::get<0>(wd) + delta, true);
      }
    }
    i++;
  }

  // no diff found: the children subtree are balanced
  // returning the current weight
  return std::make_tuple(n.weight, false);
}

int RecursiveCircus::computeBalancedWeight(const std::string& input) {
  return std::get<0>(retrieveBalanceWeight(computeRootNode(input)));
}