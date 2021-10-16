#include "../include/Task5.h"

Task5 :: Task5() = default;

Task5 :: Task5(string fileName): fileName{fileName} {} // constructor using initialization list.

// As we have a pointer as a data member, a user made copy constructor is necessary for doing deep copy as the implicit copy constructor will perform shallow copy.
Task5 :: Task5(const Task5 &source) { // Copy constructor for performing deep copy.
  graph = new UpdatedGraph(source.graph->getUpdatedNumberOfVertices(), source.graph->getUpdatedNumberOfEdges());
  graph = source.graph;
}

// Function to extract the value of n from the first line of the file (format already specified).
unsigned long long Task5 :: getNumberOfVertices(string numberOfVertices) {
  string nValue;
  for (size_t i = 0; i < numberOfVertices.length(); i++)
    if (numberOfVertices.at(i) >= '0' && numberOfVertices.at(i) <= '9')
      nValue += numberOfVertices.at(i);
  return stoi(nValue);
}
       
void Task5 :: read(string filename) {
  fileName = filename;
  ifstream edgeListFormat1;
  unsigned long long nVertices = 0, nEdges = 0;
  bool foundData = false;
  vector<string> fileContent, edges, parts;
  string part;
  edgeListFormat1.open(filename); // Open the file with the given file name.
  if (!edgeListFormat1.fail()) { // Assure that the file has opened safely.
    string lineContent;
    while (getline(edgeListFormat1, lineContent)) 
      fileContent.push_back(lineContent); // make a vector of all the lines in the file.
    for (size_t i = 0; i < fileContent.size(); i++) {
      if (fileContent.at(i).find("n=") != string::npos && fileContent.at(i).find("DL") != string::npos) 
        nVertices = getNumberOfVertices(fileContent.at(i));
      else if (fileContent.at(i).find("Data") != string::npos || fileContent.at(i).find("data") != string::npos) {
        nEdges = fileContent.size() - i - 1; // the number of edges is the number of lines in the file from the line containing data to the end of the file.
        foundData = true;
      }
      else if (foundData)
        edges.push_back(fileContent.at(i));
    }      
  }
  edgeListFormat1.close();
  graph = new UpdatedGraph(nVertices, nEdges); // allocate memory to the pointer to the object of a graph
  for (size_t i = 0; i < edges.size(); i++) {
    stringstream segment(edges.at(i));
    while (getline(segment, part, ' '))
      parts.push_back(part);
    graph->addNewEdge(parts.front(), parts.at(1), stold(parts.back())); // Add the edge to the graph.
    parts.clear();
  }
  return;
} 

UpdatedGraph* Task5 :: getGraph() const {
  return graph;
}

void Task5 :: write() {
  ofstream edgeListFormat2; 
  edgeListFormat2.open("DL/" + fileName, ofstream::out | ofstream::trunc);
  edgeListFormat2 << "DL n=" << graph->getUpdatedNumberOfVertices() << endl <<"format = edgelist1\nlabels embedded:\ndata:"; // the specified format in the question paper.
  list<Edge> edgeList = graph->getUpdatedEdgeList(); // get the updated edge list of the new graph.
  list<Edge> :: iterator listItr;
  for (listItr = edgeList.begin(); listItr != edgeList.end(); listItr++)
    edgeListFormat2 << endl << listItr->getVertex1() << " " << listItr->getVertex2() << " " << listItr->getEdgeWeight();
  edgeListFormat2.close();
  return;
}

Task5 :: ~Task5() {
  delete graph;
}
