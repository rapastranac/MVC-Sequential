#include "main.h"

std::vector<int> MVC(ParGreedy & gLeft, std::vector<int>& Visited, int depth, int left, int right) {
	size_t sze = gLeft.getGraphSize(); //Size of adjacency list, if sze = 0; then there is no more edges in graph
	if (sze == 0) {
		//mtx.lock();
		if (leaves == 0) {
			MVCSize = Visited.size();
			leaves++;
			//mtx.unlock();
			return Visited;	/*Terminal case*/
		}
		else {
			if (Visited.size() < MVCSize)
			{
				MVCSize = Visited.size();
			}
			leaves++;
			//mtx.unlock();
			return Visited;	/*Terminal case*/
		}
	}

	//-------------
	vector<int> VC1;
	vector<int> VC2;
	vector<int> C1 = Visited;
	vector<int> C2 = Visited;
	//ParGreedy gLeft = graph;	/*Let gLeft be a copy of graph*/
	ParGreedy gRight = gLeft; // graph;	/*Let gRight be a copy of graph*/

	int v = gLeft.getRandonVertex();	

	C1.push_back(v);
	if (C1.size() >= MVCSize) {
		VC1 = {};
	}
	else {
		gLeft.removeVertex(v);
		VC1 = MVC(gLeft, C1, depth++, left++, right);
	}

	gRight.removeNeiboursVertex(v,C2);
	if (C2.size() >= MVCSize) 
	{
		VC2 = {};
	}
	else {
		VC2 = MVC(gRight, C2, depth++, left, right++);
	}

	if (VC1.empty())	return VC2;
	else if (VC2.empty())	return VC1;
	else if (VC1.empty() && VC2.empty())	return {};
	else if (VC1.size() >= VC2.size())	return VC2;
	else return VC1;
}


