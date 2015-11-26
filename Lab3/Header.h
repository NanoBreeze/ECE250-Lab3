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
//
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
	//second vector holds maps for each vertex
	//map holds the adjacent vertex and the weight
	vector<vector<map<int, double>>> vertices;
	int edge_number;


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

Weighted_graph::Weighted_graph(int n = 50)
{
	// DO we need to save all spots? vertices.reserve(n);
	edge_number = 0;

	for (auto &v : vertices)
	{
		//vector<int> vertex;
		// v = vector<map<int,double>>();
	}

	/*for (vector<vector<int>>::iterator it = vertices.begin(); it != vertices.end(); ++it)
	{

	}*/
}

Weighted_graph::~Weighted_graph()
{

}

int Weighted_graph::degree(int v) const
{
	if (v > vertices.size())
	{
		throw illegal_argument();
	}
	else
	{
		return vertices[v].size();
	}
}

int Weighted_graph::edge_count() const
{
	return edge_number;
}

double Weighted_graph::adjacent(int vertex1, int vertex2) const
{

}

double Weighted_graph::minimum_spanning_tree(int) const
{

}

bool Weighted_graph::is_connected() const
{
}

//throws exception for invalide vertex1 and vertex2
//if the edge already exists, replace it
//else add it to both vectors
void Weighted_graph::insert(int vertex1, int vertex2, double weight)
{
	//invalid values throw exceptions
	if (weight < 0 || weight == std::numeric_limits<double>::infinity())
	{
		throw illegal_argument();
	}

	//check if edge exists

	vertices[vertex1].
}


std::ostream &operator<<(std::ostream &out, Weighted_graph const &graph) {
	// Your implementation

	return out;
}
//
//
//#endif