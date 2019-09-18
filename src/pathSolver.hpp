#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class Grid;
class Node;

class PathSolver
{
public:
	PathSolver();

	void update();
	void processEvents(sf::Event& event);

	void solveGrid(Grid& grid);

private:
	void handleNeighbour(Node* const neighbourNode);
	void drawPath();
	void restartSolver();

	bool isInVector(const Node* const node, const std::vector<Node*>& nodeVector) const;
	int getDistance(Node* const nodeA, Node* const nodeB);

private:
	Grid* mGridToSolve;
	std::vector<Node*> mOpenNodes;
	std::vector<Node*> mClosedNodes;
	Node* mCurrentNode;
	Node* mTargetNode;
	Node* mStartNode;
	bool mSolved;
	sf::Clock mT;
};