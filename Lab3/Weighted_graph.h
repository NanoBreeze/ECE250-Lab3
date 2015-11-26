#pragma once
	//ref class Weighted_graph
	//{
	//public:
	//	Weighted_graph();
	//};


/*****************************************
* Instructions
*  - Replace 'uwuserid' with your uWaterloo User ID
*  - Select the current calendar term and enter the year
*  - List students with whom you had discussions and who helped you
*
* uWaterloo User ID:  l43cheng @uwaterloo.ca
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  (Fall) 2015
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*
* The following is a list of uWaterloo User IDs of those students
* I had discussions with in preparing this project:
*    -
*
* The following is a list of uWaterloo User IDs of those students
* who helped me with this project (describe their help; e.g., debugging):
*    -
*****************************************/

//#ifndef WEIGHTED_GRAPH_H
//#define WEIGHTED_GRAPH_H
//
//#ifndef nullptr
//#define nullptr 0
//#endif

#include <iostream>
#include <limits>
#include "Exception.h"
#include <vector>
#include <map>

using namespace std;

class Weighted_graph {
private:
	static const double INF; 

	//first vector holds all vertices
	//map holds the adjacent vertex and the weight
	vector<map<int, double>> vertices;

	//total number of edges in graph
	int edge_number;

	//total number of nodes in graph. Used to compare to the number of nodes in MST to determine if graph is connected
	int node_number;

	//total number of nodes in MST. Used to compare with node_number
	int spanning_tree_node_number;

	void check_valid_vertices(const int&, const int&) const;

public:
	Weighted_graph(int = 50);
	~Weighted_graph();

	int degree(int) const;
	int edge_count() const;
	double adjacent(int, int) const;
	double minimum_spanning_tree(int) const;
	bool is_connected() const;

	void insert(int, int, double);

	// Friends

	friend std::ostream &operator<<(std::ostream &, Weighted_graph const &);
};


const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

//set edge number and first vector with vertices
Weighted_graph::Weighted_graph(int i) : edge_number(0), node_number(i), spanning_tree_node_number(0)
{
	for (int k = 0; k < i; k++)
	{
		vertices.push_back(map<int, double>());
	}
	node_number = i;
}

Weighted_graph::~Weighted_graph()
{
	
}

//returns the degree of the selected vertex
int Weighted_graph::degree(int v) const
{
	if (v > vertices.size() - 1)	
	{
		throw illegal_argument();
	}
	else
	{
		return vertices[v].size();
	}
}

//returns the total number of edges in the graph
int Weighted_graph::edge_count() const
{
	return edge_number;
}

//returns the weight of the edge connecting two vertices
//if the vertices are equal, return 0
//if the vertices are not adjacent, return infinity
//if arguments do not correspond to existing vertices, throw illegal exception
double Weighted_graph::adjacent(int v1, int v2) const
{
	check_valid_vertices(v1, v2);
	if (v1 == v2) { return 0; }
	else if (vertices[v1].count(v2) == 0) { return INF; }
	else { return vertices[v1].at(v2); }	
}

//return size of the MST connected to vertex
double Weighted_graph::minimum_spanning_tree(int v) const
{

}

//
////determines if the graph is connected
//bool Weighted_graph::is_connected() const 
//{
//}

//insert an edge incident to two vertices and specify its weight
//throws exception for invalid vertex1 and vertex2
//if the edge already exists, replace it
//else add it to both vectors
void Weighted_graph::insert(int v1, int v2, double weight)
{
	//invalid values throw exceptions
	if (weight < 0 || weight == std::numeric_limits<double>::infinity() ) 
	{
		throw illegal_argument();
	}

	check_valid_vertices(v1, v2);

	if (v1 == v2) throw illegal_argument();

	//if weight is 0, remove the edge, if it exists between the entered vertices
	//else add new edge or replace existing one
	if (weight == 0)
	{
		//currently exists, thus, remove
		if (vertices[v1].count(v2) == 1)		//|| vertices[v2].count(v1) == 1
		{
			vertices[v1].erase(v2);
			vertices[v2].erase(v1);
			edge_number--;
		}
	}
	else
	{
			vertices[v1][v2] = weight;
			vertices[v2][v1] = weight;
			edge_number++;
	}
}


std::ostream &operator<<(std::ostream &out, Weighted_graph const &graph) {
	// Your implementation

	return out;
}

//=============HELPER FUNCTIONS==================

//checks if the vertices exist
void Weighted_graph::check_valid_vertices(const int& v1, const int& v2) const
{
	if (v1 > vertices.size() - 1 || v2 > vertices.size() - 1 || v1 < 0 || v2 < 0)
	{
		throw illegal_argument();
	}

}
//
//
//#endif