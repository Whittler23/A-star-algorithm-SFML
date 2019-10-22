#pragma once

#include "node.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

class Grid;
class Node;

class PathDrawer
{
public:
	PathDrawer();
	void init(Node* targetNode, Node* startNode);
	bool drawStep();
	bool isDrawn();

private:
	std::vector<Node*> mDrawPath;
	sf::Clock mDrawClock;
	int mCounter;
	bool mDrawn;
};

class PathSolver
{
public:
	PathSolver();

	void update();

	void solveGrid(Grid& grid);
	void restartSolver();
	bool getSolved() { return mSolved; }

private:
	void handleNeighbour(Node* const neighbourNode);

	bool isInVector(const Node* const node, const std::vector<Node*>& nodeVector) const;
	int getDistance(Node* const nodeA, Node* const nodeB);

private:
	Grid* mGridToSolve;
	PathDrawer mPathDrawer;
	std::vector<Node*> mOpenNodes;
	std::vector<Node*> mClosedNodes;
	Node* mCurrentNode;
	Node* mTargetNode;
	Node* mStartNode;
	bool mSolved;
};