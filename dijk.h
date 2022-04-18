#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include "edge.h"
#include <map>
#include <queue>
#include <limits.h>
#include <stdio.h>
// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Edge;
class Vertex;
using namespace std;

// Djikstra's algorithm to find the shortest path between two vertices
void Dijkstra(Graph &g, int start, int ende) {
  map<int, int> dist;
  map<int, int> prev;
  map<int, bool> visited;
  queue<int> q;
  int current;


  for (auto i : g.getGraph() ) {
		visited[i.getStateID()] = false;
		dist[i.getStateID()] = INT_MAX;
		prev[i.getStateID()] = -1;
	}


  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    current = q.front();
    q.pop();
    visited[current] = true;
    for (int i = 0; i < (int)g.getSize(); i++) {
      if (g.getGraph().at(i).getStateID() == current) {
        for (auto it = g.getGraph().at(i).edgeList.begin(); it != g.getGraph().at(i).edgeList.end(); it++) {
          if (visited[it -> getDestinationVertexID()] == false && dist[current] + it -> getWeight() < dist[it -> getDestinationVertexID()] ) {
            dist[it -> getDestinationVertexID() ] = dist[current] + it -> getWeight();
            prev[it -> getDestinationVertexID()] = current;
            q.push(it -> getDestinationVertexID());
          }
        }
      }
    }
  }
  cout << "Shortest Path between " << start << " and " << ende << " is: ";
  int temp = ende;
  while (temp != -1) {
    cout << temp << " ";
    temp = prev[temp];
  }
  cout << endl;
}

// Djisktra's algorithm to find the shortest path between two vertices
// Prints shortest paths from src to all other vertices
void shortestPathD(Graph &g,int src, int dest)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
     map<int, int> pred;
     map<int, int> dist;
     for (auto i : g.getGraph() ) {
		dist[i.getStateID()] = INF;
		pred[i.getStateID()] = -1;
	}

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        //list< pair<int, int> >::iterator i;
        for (int i = 0; i < (int)g.getNeigbors(u).size(); i++)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = g.getNeigbors(u)[i];
            double weight =  g.getLenghtByID(u,v);

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pred[v] = u;
                pq.push(make_pair(dist[v], v));
            }

        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
/*
    for (auto i : g.getGraph() ){
        if(i.getStateID()==dest){
            break;
        }
        printf("%d \t\t %d\n", i.getStateID(), dist[i.getStateID()]);
    }
    printf("%d \t\t %d\n", dest, dist[dest]);

 cout << "\nShortest Path between " << src << " and " << dest << " is: \n";
  int temp = dest;
  int i =1;
  while (temp != -1) {
    cout <<"Vertex[  "<<i<<"] =  " <<temp;
    cout << " ,length =  "   << dist[temp] << endl;
    //cout << temp << " ";
    temp = pred[temp];
    i++;
  }*/
  cout << endl;
  /////////////
  vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}
	//cout << "Total visited vertex =  " << vis << endl;
	// distance from source is in distance array
	cout << "Total vertex on path from start to end =  "
		<< path.size();
    // printing path from source to destination
	cout << "\nPath is::\n";
	double length = g.getLenghtByID(src,path[path.size() - 1]);
	int next = src;
	for (int i = path.size() - 1; i >= 0; i--){
		cout <<"Vertex[  "<< path.size() -i<<"] =  "   <<path[i];
		//printf("length  =   %.2lf ",length + g.getLenghtByID(next,path[i]));
		cout << " ,length =  "   << length + g.getLenghtByID(next,path[i])   << endl;
		length =length + g.getLenghtByID(next,path[i])  ;
		next = path[i];

	}
}




