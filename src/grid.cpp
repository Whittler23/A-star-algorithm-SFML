#include "grid.hpp"
#include "application.hpp"
#include "node.hpp"
#include <iostream>

Grid::Grid(int width, int height, int tileSize)
	:mGridSizeX(width)
	,mGridSizeY(height)
	,mTileSize(tileSize)
	,mStartingNode(nullptr)
	,mTargetedNode(nullptr)
	,mDiagonalSearch(false)
{
	createGrid();
}

void Grid::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	for (auto& node : mNodes)
		renderTarget.draw(node->getNodeImage());
}

void Grid::processEvents(sf::Event& event, MousePositions& mousePositions)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		if (!isPositionProper(sf::Vector2i(mousePositions.mMouseWorldPosition)))
			return;
		if (event.mouseButton.button == sf::Mouse::Left)
			if(getNodeToSet())
				setStartingNode(getNodeInWorld(sf::Vector2i(mousePositions.mMouseWorldPosition)));
			else
				setTargetedNode(getNodeInWorld(sf::Vector2i(mousePositions.mMouseWorldPosition)));
		else if (event.mouseButton.button == sf::Mouse::Right)
			handleObstacle(getNodeInWorld(sf::Vector2i(mousePositions.mMouseWorldPosition)));

	} break;
	}
}

bool Grid::getNodeToSet()
{
	static bool shouldSetStartingNode;
	if (!mStartingNode)
		shouldSetStartingNode = true;
	else if (!mTargetedNode)
		shouldSetStartingNode = false;
	else if (mStartingNode && mTargetedNode)
		shouldSetStartingNode = !shouldSetStartingNode;

	return shouldSetStartingNode;
}

void Grid::createGrid()
{
	for (int i = 0; i < mGridSizeX; ++i)
		for (int ii = 0; ii < mGridSizeY; ++ii)
			mNodes.emplace_back(std::make_unique<Node>(sf::Vector2i(i * mTileSize, ii * mTileSize), mTileSize));
}

void Grid::restartGrid()
{
	mStartingNode = nullptr;
	mTargetedNode = nullptr;
	for (auto& node : mNodes)
		if (node->getType() != NodeType::ObstacleNode)
			node->setType(NodeType::None);
}

void Grid::restartObstacles()
{
	for (auto& node : mNodes)
		if (node->getType() == NodeType::ObstacleNode)
			node->setType(NodeType::None);
}

void Grid::setDiagonal(bool set)
{
	mDiagonalSearch = set;
}

bool Grid::isPositionProper(const sf::Vector2i position)
{

	int posX = static_cast<int>(position.x);
	int posY = static_cast<int>(position.y);

	if (posX > mTileSize * mGridSizeX + mTileSize|| posX < 0 ||
		posY > mTileSize* mGridSizeY + mTileSize || posY < 0)
		return false;
	else 
		return true;
}

std::vector<Node*> Grid::getNeighbours(Node* const node)
{
	std::vector<Node*> neighbours;

	neighbours.reserve(9);
	for(int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
		{
			if(shouldIgnore(i, j)) 
				continue;
			int nodePositionX = node->getPosition().x + mTileSize * i;
			int nodePositionY = node->getPosition().y + mTileSize * j;
			if (!isPositionProper(sf::Vector2i(nodePositionX, nodePositionY)))
				continue;
			Node* neighbour = getNodeInWorld(sf::Vector2i(nodePositionX, nodePositionY));
			neighbours.emplace_back(neighbour);
		}
	return neighbours;
}

bool Grid::shouldIgnore(int val1, int val2)
{
	std::vector<std::pair<int, int> > mIgnoredTiles = { {0,0} };
	if (!mDiagonalSearch)
		mIgnoredTiles = { {0,0},{-1,-1},{-1,1},{1,1},{1,-1} };
	for (auto tilePosition : mIgnoredTiles)
		if (val1 == tilePosition.first && val2 == tilePosition.second)
			return true;
	return false;
}

void Grid::setStartingNode(Node* const startingNode)
{
	if (mStartingNode != nullptr)
		mStartingNode->setType(NodeType::None);

	mStartingNode = startingNode;
	mStartingNode->setType(NodeType::StartingNode);
}

void Grid::setTargetedNode(Node* const targetedNode)
{
	if (mTargetedNode != nullptr)
		mTargetedNode->setType(NodeType::None);

	mTargetedNode = targetedNode;
	mTargetedNode->setType(NodeType::TargetedNode);
}

void Grid::handleObstacle(Node* const obstacleNode)
{
	if (obstacleNode->getType() != NodeType::StartingNode && obstacleNode->getType() != NodeType::TargetedNode)
	{
		if (obstacleNode->getType() != NodeType::ObstacleNode)
			setObstacle(obstacleNode);
		else if (obstacleNode->getType() == NodeType::ObstacleNode)
			removeObstacle(obstacleNode);
	}
}

void Grid::setObstacle(Node* const obstacleNode)
{
	obstacleNode->setType(NodeType::ObstacleNode);
}

void Grid::removeObstacle(Node* const obstacleNode)
{
	obstacleNode->setType(NodeType::None);
}

Node* Grid::getNodeInWorld(const sf::Vector2i position)
{
	int xPosition = position.x / mTileSize;
	int yPosition = position.y / mTileSize;
	int tilePosition = mGridSizeY * xPosition + yPosition;
	return mNodes[tilePosition].get();
}

