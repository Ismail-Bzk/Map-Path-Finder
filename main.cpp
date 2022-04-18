#include <iostream>
#include "edge.h"
#include "read.h"
#include "bfs.h"
#include"dijk.h"
int main() {


    Graph g;
    read_record(g,"graph.txt");

    cout << "Print Graph Operation -" << endl;
    g.printGraph();

    int source =86771, dest =110636;
    printShortestDistance(g, source, dest); // for BfS algorithm
    //shortestPathD(g,  73964,110636); // Dijkstra algorithm


  return 0;
}




