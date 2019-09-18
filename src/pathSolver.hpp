#pragma once

#include <vector>

class Grid;
class Node;

class PathSolver
{
public:
	PathSolver();

	void solveGrid(Grid& grid);

private:
	void addStartingNode();
	void addClosingNode();

private:
	Grid* mGridToSolve;
	std::vector<Node*> mOpenNodes;
	std::vector<Node*> mCloseNodes;
	bool mSolved;
};