//file:   graphUtes.cpp
//author: Cal Colistra
//desc.:  graph processing utilities

#include <iostream>  //import for input/output
#include  < limits.h >  //import for INT_MAX for sentinel value
#include <queue>  //import for queue

using namespace std;

#define N 10  //max no. of nodes in graph
//----------------------------------------------------------------------
// This function returns true if G has at least one self loop; false
// otherwise.
bool hasSelfLoops(bool G[N][N]) {
  for (int i = 0; i < N; i++) {  //loop from 0 to N - 1
    //check for value 1 in any spot where column = row:
    if (G[i][i] == 1) return true;  //if so return true and end function
  }
    return false;  //in this case there were none so return false
}
//----------------------------------------------------------------------
// This function returns true if G is empty (null graph); false otherwise.
bool isEmpty(bool G[N][N]) {
  for (int i = 0; i < N; i++) {  //loop from 0 to N - 1
    for (int j = 0; j < N; j++) {  //loop through each node of row i
      //check if any node has an edge:
      if (G[i][j] == 1) return false;  //if so, then graph is not empty
    }
  }
  return true;  //if function reaches this point then the graph is empty
}
//----------------------------------------------------------------------
// Define a digraph as a graph that has at least one asymmetry (i.e., it 
// contains at least one edge  but no corresponding edge 
// . (By this definition, a null or empty graph is not a 
// digraph, and a graph that only contains self loops is also not a 
// digraph.)
//
// This function returns true if the graph G is a digraph; false otherwise.
bool isDigraph(bool G[N][N]) {
  if (isEmpty(G) == true) return false;  //return false if G is empty
  for (int i = 0; i < N; i++) {  //loop from 0 to N - 1
    for (int j = 0; j < N; j++){  //loop through each node of row i
      //check for edges that are not self loops:
      if ((G[i][j] == 1) && (j != i)){
        //check if the corresponding edge does not exist:
        if (G[j][i] == 0)  return true;  //if so, then it is a digraph
      }
    }
  }
  return false;
}
//----------------------------------------------------------------------
// This function returns true if the graph G contains at least one cycle;
// false otherwise.
// (You are not required to output any or all of the cycles; you are not
// required to count them.)
bool hasCycle(bool G[N][N]) {
  //check if there are self loops
  //if so then there is a cycle so return true:
  if (hasSelfLoops(G) == true) return true;
  if (isEmpty(G) == true) return false;  //return false if G is empty
  //new array to hold Nodes and keep track whether they have been visited or not
  bool* visited = new bool[N];
  for (int i = 0; i < N; i++) {  //loop from 0 to N
    visited[i] = false;  //initialize all vertexes to not visited
  }
  bool* connected = new bool[N];
  for (int i = 0; i < N; i++) {  //loop from 0 to N
      connected[i] = false;  //initialize all vertexes to not visited
  }
  queue <int> q;  // Create a queue for BFS:
  int target;  //holds the target node to check for cycle
  int current_node;  //holds the node at the front of the queue
  for (int i = 0; i < N; i++) {  //loop through nodes
    target = i;  //set target to each node of the graph
    q.push(i);  //push target onto queue
    //reset connected array for next target:
    for (int i = 0; i < N; i++) {  //loop from 0 to N
        connected[i] = false;  //set all vertexes to not visited
    }
    //reset visited array for next target:
    for (int i = 0; i < N; i++) {  //loop from 0 to N
        visited[i] = false;  //set all vertexes to not visited
    }
    while (q.empty() == false) {
      current_node = q.front();  //set current node to front of q
      for (int o = 0; o < N; o++){  //loop through current node
        if (G[current_node][o] == 1) {  //check for connected nodes
            if (visited[o] == false) {  //check if node was already visited
            q.push(o);  //push node onto q if it is connected
            connected[o] = true;  //mark node as connected to target
            }
        }
      }
      visited[q.front()] = true;  //mark it as visited
      q.pop();  //pop previously evaluated node
    }
    
    for (int f = 0; f < N; f++) {  //loop from 0 to N
      if (connected[f] == true) {  //check for nodes connected to target
        //if the connected node has an edge pointing back to the target:
        if (G[f][target] == true) {
          return true;  //then the graph has a cycle
        }
      }
    }
  }
  return false;  //if the program reached here that means there is no cycle
}