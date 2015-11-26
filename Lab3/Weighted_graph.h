/*****************************************
* Instructions
*  - Replace 'uwuserid' with your uWaterloo User ID
*  - Select the current calendar term and enter the year
*  - List students with whom you had discussions and who helped you
*
* uWaterloo User ID:  uwuserid @uwaterloo.ca
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  (Winter|Spring|Fall) 201N
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

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#ifndef nullptr
#define nullptr 0
#endif

#include <iostream>
#include <limits>
#include "Exception.h"

class Weighted_graph {
private:
	static const double INF;
	// your choice

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

// Enter definitions for all public functions here

std::ostream &operator<<(std::ostream &out, Weighted_graph const &graph) {
	// Your implementation

	return out;
}

#endif