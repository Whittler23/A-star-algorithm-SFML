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
			setStartingNode(getNodeInWorld(sf::Vector2i(mousePositions.mMouseWorldPosition)));
		else if (event.mouseButton.button == sf::Mouse::Right)
			setTargetedNode(getNodeInWorld(sf::Vector2i(mousePositions.mMouseWorldPosition)));
	} break;
	}
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
	mNodes.clear();
	createGrid();
}

bool Grid::isPositionProper(const sf::Vector2i position)
{

	int posX = static_cast<int>(position.x);
	int posY = static_cast<int>(position.y);

	if (posX > mTileSize * mGridSizeX || posX < 0 ||
		posY > mTileSize* mGridSizeY || posY < 0)
		return false;
	else 
		return true;
}

std::vector<Node*> Grid::getNeighbours(Node* const node)
{
	std::vector<Node*> neighbours;
	for(int i = -1; i <= 1; ++i)
		for (int b = -1; b <= 1; ++b)
		{
			if (i == 0 && b == 0) continue;
			int nodePositionX = node->getPosition().x + mTileSize * i;
			int nodePositionY = node->getPosition().y + mTileSize * b;
			if (!isPositionProper(sf::Vector2i(nodePositionX, nodePositionY)))
				continue;

			Node* neighbour = getNodeInWorld(sf::Vector2i(nodePositionX, nodePositionY));
			neighbours.emplace_back(neighbour);
		}
	return neighbours;
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

Node* Grid::getNodeInWorld(const sf::Vector2i position)
{
	int xPosition = position.x / mTileSize;
	int yPosition = position.y / mTileSize;
	int tilePosition = mGridSizeY * xPosition + yPosition;
	return mNodes[tilePosition].get();
}

