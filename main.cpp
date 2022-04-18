#include <iostream>
#include "edge.h"
#include "read.h"
#include "bfs.h"
#include"dijk.h"
int main() {


    Graph g;
    read_record(g,"f1.txt");//g.readGraphFromFile("f1.txt");

    cout << "Print Graph Operation -" << endl;
    g.printGraph();

    int source =0, dest =20;
    printShortestDistance(g, source, dest); // for BfS algorithm
    //shortestPathD(g,  73964,110636); // Dijkstra algorithm
     //  86771,110636

  return 0;
}




