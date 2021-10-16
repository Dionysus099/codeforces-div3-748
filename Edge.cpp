#include "Edge.h"

Edge :: Edge() = default;

Edge :: Edge(string vertex1, string vertex2, long double weight): vertex1{vertex1}, vertex2{vertex2}, weight{weight} {} // Initialization list copy constructor.

Edge :: Edge(const Edge &source): Edge(source.vertex1, source.vertex2, source.weight) {} // Deligated copy constructor.

Edge& Edge :: operator= (const Edge &rhs) { // Overloaded "=" operator.
  if (this != &rhs) {
    vertex1 = rhs.vertex1;
    vertex2 = rhs.vertex2;
    weight = rhs.weight;
  }
  return *this;
}

// Any function which does not change the state of the object shoulf have "const" keyword in their prototype.
long double Edge :: getEdgeWeight() const {
  return weight;
}

string Edge :: getVertex1() const {
  return vertex1;
}

string Edge :: getVertex2() const {
  return vertex2; 
}

void Edge :: setEdgeWeight(long double weight) {
  this->weight = weight;
} 
    
void Edge :: setVertex1(string vertex1) {
  this->vertex1 = vertex1;
}

void Edge :: setVertex2(string vertex2) {
  this->vertex2 = vertex2;
}
    
Edge :: ~Edge() = default;
