
#include <vector>
#include <map>
#include "Weighted_graph.h"
using namespace std;
int main()
{
	vector<map<int, double>> a(20);
	auto k  = a[3][5];

	Weighted_graph weighted_graph;

	weighted_graph.insert(3, 4, 6);

}