#include "pathSolver.hpp"
#include "grid.hpp"

PathSolver::PathSolver()
	:mGridToSolve(nullptr)
	,mCurrentNode(nullptr)
	,mTargetNode(nullptr)
	,mStartNode(nullptr)
	,mSolved(false)
{
}

void PathSolver::update()
{
	if (mSolved)
		drawPath();
}

void PathSolver::drawPath()
{
	for (auto& node : mClosedNodes)
	{
		if (node != mTargetNode && node != mStartNode)
			node->setType(NodeType::PathNode);
	}
}

void PathSolver::processEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::R)
			restartSolver();
	}
	}
}

void PathSolver::solveGrid(Grid& grid)
{

	mGridToSolve = &grid;
	mTargetNode = mGridToSolve->getTargetedNode();
	mStartNode = mGridToSolve->getStartingNode();
	mOpenNodes.emplace_back(mStartNode);

	while (mCurrentNode != mTargetNode)
	{
		mCurrentNode = mOpenNodes.front();

		for (int i = 1; i < mOpenNodes.size(); ++i)
			if (mOpenNodes[i]->getFCost() < mCurrentNode->getFCost())
				mCurrentNode = mOpenNodes[i];

		for (int i = 0; i < mOpenNodes.size(); ++i)
			if (mOpenNodes[i] == mCurrentNode)
			{
				mOpenNodes.erase(mOpenNodes.begin() + i);
				continue;
			}

		mClosedNodes.emplace_back(mCurrentNode);

		if (mCurrentNode == mTargetNode)
		{
			mSolved = true;
			return;
		}

		std::vector<Node*> neighbourNodes = mGridToSolve->getNeighbours(mCurrentNode);
		for (auto& neighbourNode : neighbourNodes)
			if (!isInVector(neighbourNode, mClosedNodes))
				handleNeighbour(neighbourNode);
	}
}

void PathSolver::handleNeighbour(Node* const neighbourNode)
{
	int movementCostToNeighbour = mCurrentNode->getGCost() + getDistance(neighbourNode, mCurrentNode);
	if (movementCostToNeighbour < neighbourNode->getGCost() || !isInVector(neighbourNode, mOpenNodes))
	{
		neighbourNode->setGCost(movementCostToNeighbour);
		neighbourNode->setHCost(getDistance(neighbourNode, mTargetNode));
		neighbourNode->setFCost();
		neighbourNode->setParentNode(mCurrentNode);
		if (!isInVector(neighbourNode, mOpenNodes))
			mOpenNodes.emplace_back(neighbourNode);
	}

}

bool PathSolver::isInVector(const Node* const node, const std::vector<Node*>& nodeVector) const
{
	for (int i = 0; i < nodeVector.size(); ++i)
	{
		if (nodeVector[i] == node)
			return true;
	}
	return false;
}

int PathSolver::getDistance(Node* const nodeA, Node* const nodeB)
{
	sf::Vector2f nodeAPos = nodeA->getPosition();
	sf::Vector2f nodeBPos = nodeB->getPosition();

	int xDist = static_cast<int>(std::abs(nodeAPos.x - nodeBPos.x));
	int yDist = static_cast<int>(std::abs(nodeAPos.y - nodeBPos.y));

	xDist *= xDist;
	yDist *= yDist;

	return static_cast<int>(std::hypot(xDist, yDist));
}


void PathSolver::restartSolver()
{
	mCurrentNode = nullptr;
	mTargetNode = nullptr;
	mStartNode = nullptr;
	mGridToSolve = nullptr;
	mClosedNodes.clear();
	mOpenNodes.clear();
}