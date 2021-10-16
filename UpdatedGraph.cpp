#include "UpdatedGraph.h"

UpdatedGraph :: UpdatedGraph() = default;

// Using static_cast is more efficient than using the normal type casting done in C programming language.
UpdatedGraph :: UpdatedGraph(unsigned long long nVertices, unsigned long long nEdges): Graph(nVertices, nEdges) {
  // The remaining number of vertices in the new graph is 50 % of those in the original graph.
  nRemainingVertices = static_cast<unsigned long long> (ceil(Graph::getNumberOfVertices() / 2.0));
}

UpdatedGraph :: UpdatedGraph(const UpdatedGraph &source): Graph(source) {} // Copy constructor

/* This is the function which is used for comparison between the vertices and sort the adjacency list.
   The vertex whose sum of weights of all outgoing edges from that vertex is the greatest should be at index 0 in the sorted adjacency list. */
bool compareByRank(const pair<string, vector<pair<string, long double>>> &vertex1, const pair<string, vector<pair<string, long double>>> &vertex2) {
  // Fetch all the adjacent edges of the 2 vertices first. Then calculate the sum of weight of these edges for comparison.
  vector<pair<string, long double>> vertex1List = vertex1.second;
  vector<pair<string, long double>> vertex2List = vertex2.second;
  long double rank1 = 0, rank2 = 0;
  for (size_t i = 0; i < vertex1List.size(); i++)
    rank1 += vertex1List.at(i).second; // Sum of the weights of all outgoing edges from vertex1. 
  for (size_t i = 0; i < vertex2List.size(); i++)
    rank2 += vertex2List.at(i).second; // Sum of the weights of all outgoing edges from vertex2.
  return rank1 > rank2;
}

vector<pair<string, vector<pair<string, long double>>>> UpdatedGraph :: sortedAdjacencyList() const {
  unordered_map<string, vector<pair<string, long double>>>* adjList = Graph::getAdjacencyList();
  vector<pair<string, vector<pair<string, long double>>>> adjVector(Graph::getNumberOfVertices());
  // An unordered map cannot be sorted directly. It needs to be converted into a vector first.
  copy(adjList->begin(), adjList->end(), adjVector.begin()); // Copying the contents of the unordered map into a vector of pairs so that sorting becomes possible. 
  sort(adjVector.begin(), adjVector.end(), compareByRank);
  return adjVector;
}

list<Edge> UpdatedGraph :: getUpdatedEdgeList() {
  vector<pair<string, vector<pair<string, long double>>>> sortedAdjVector = sortedAdjacencyList();
  for (size_t i = 0; i < nRemainingVertices; i++)
    remainingVertices.insert(sortedAdjVector.at(i).first); // Exactly half the number of vectors remain.
    
  // Iterate the old edge list and add all the edges into the new edge list which exist between any 2 vertices present in the remaining set of vertices.
  list<Edge> edgeList = Graph::getEdgeList(); // The original edge list.
  list<Edge> :: iterator listItr;
  for (listItr = edgeList.begin(); listItr != edgeList.end(); listItr++) 
    if (remainingVertices.find(listItr->getVertex1()) != remainingVertices.end() && remainingVertices.find(listItr->getVertex2()) != remainingVertices.end()) 
      updatedEdgeList.push_front(*listItr);
  nRemainingEdges = updatedEdgeList.size();
  return updatedEdgeList;
}

// Functions which do not change the state to the object should have const keyword in their prototype.
unsigned long long UpdatedGraph :: getUpdatedNumberOfVertices() const {
  return nRemainingVertices;
}

unsigned long long UpdatedGraph :: getUpdatedNumberOfEdges() const {
  return nRemainingEdges;
}

void UpdatedGraph :: setUpdatedEdgelist(list<Edge> updatedEdgeList) {
  this->updatedEdgeList = updatedEdgeList;
}

UpdatedGraph :: ~UpdatedGraph() = default;
