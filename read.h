#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include "edge.h"
#include "read.h"
#include <iomanip>
#include <chrono>

using namespace std;

class Edge;
class Vertex;

void read_record(Graph &g, const string fname)
{


	

	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";

	


	for(int i=0;i< (int)content.size();i++)
	{
	    Vertex v1;
	    if(content[i][0]=="V"){
            v1.setStateName(content[i][0]);
            v1.setID(stoi(content[i][1]));
            g.addVertex(v1);

	    }

	    else if(content[i][0]=="E"){

            g.addEdgeByID(stoi(content[i][1]), stoi(content[i][2]), stod(content[i][3]));
	    }



	}
	 cout << "\nPrint Graph Operation -" << endl;
}

