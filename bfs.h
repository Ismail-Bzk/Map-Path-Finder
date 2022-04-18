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

// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>

class Edge;
class Vertex;
using namespace std;


// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d

bool BFS(Graph &g, int src, int dest, map<int, int>&pred,map<int,int>&dist)
{
	// a queue to maintain queue of vertices
	list<int> queue;


	// boolean map<int, bool> visited which stores the
	// information whether ith vertex is reached
	// at least once in the Breadth first search
	map<int, bool>visited;

	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	for (auto i : g.getGraph() ) {
		visited[i.getStateID()] = false;
		dist[i.getStateID()] = INT_MAX;
		pred[i.getStateID()] = -1;
	}

	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);



	// standard BFS algorithm
	while (!queue.empty()) {

		int u = queue.front();
		queue.pop_front();
		//counter ++;
		for (int i = 0; i < (int)g.getNeigbors(u).size(); i++) {
			if (visited[g.getNeigbors(u)[i]] == false) {
				visited[g.getNeigbors(u)[i]] = true;
				dist[g.getNeigbors(u)[i]] = dist[u] + 1;
				pred[g.getNeigbors(u)[i]] = u;
				queue.push_back(g.getNeigbors(u)[i]);
				// We stop BFS when we find
				// destination.
				if (g.getNeigbors(u)[i] == dest)

					return true;
			}
		}

	}

	return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(Graph &g, int s,
						int dest)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s

	map<int,int>dist;
	map<int,int>pred;

	if (BFS( g, s, dest,pred, dist) == false) {
		cout << "Given source and destination"
			<< " are not connected";
		return;
	}

	// vector path stores the shortest path
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
		<< dist[dest] + 1;

	// printing path from source to destination
	cout << "\nPath is::\n";
	double length = g.getLenghtByID(s,path[path.size()-1]);
	int next = s;
	for (int i = path.size() - 1; i >= 0; i--){
		cout <<"Vertex[  "<< path.size() -i<<" ] =  "   <<path[i];
		cout << " ,length =  "   << length + g.getLenghtByID(next,path[i])   << endl;
		length =length + g.getLenghtByID(next,path[i])  ;
		next = path[i];

	}
}

