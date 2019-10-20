#pragma once

#include "node.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

class Grid;
class Node;

class PathDrawer
{
public:
	PathDrawer()
		:mCurrentDrawNode(nullptr)
	{

	}

	void init(Node* start, Node* end)
	{
		mCurrentDrawNode = start;
		mTargetedNode = end;
	}

	bool draw()
	{
		if (mDrawClock.getElapsedTime().asSeconds() < 0.05f) return false;
		if (mCurrentDrawNode->getParent() != mTargetedNode)
		{
			mCurrentDrawNode = mCurrentDrawNode->getParent();
			mCurrentDrawNode->setType(NodeType::PathNode);
			mDrawClock.restart();
			return false;
		}
		else
		{
			mCurrentDrawNode = nullptr;
			mTargetedNode = nullptr;
			return true;
		}
	}


private:
	Node* mCurrentDrawNode;
	Node* mTargetedNode;
	sf::Clock mDrawClock;
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
	void drawPath();

	bool isInVector(const Node* const node, const std::vector<Node*>& nodeVector) const;
	int getDistance(Node* const nodeA, Node* const nodeB);

private:
	Grid* mGridToSolve;
	PathDrawer mP;
	std::vector<Node*> mOpenNodes;
	std::vector<Node*> mClosedNodes;
	Node* mCurrentNode;
	Node* mTargetNode;
	Node* mStartNode;
	bool mSolved;
	bool mDrawn;
};