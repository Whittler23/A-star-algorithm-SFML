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
	void addTargetedNode();

private:
	Grid* mGridToSolve;
	Node* mCurrent;
	std::vector<Node*> mOpenNodes;
	std::vector<Node*> mCloseNodes;
	bool mSolved;
};