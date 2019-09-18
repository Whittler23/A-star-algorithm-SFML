#include "grid.hpp"
#include "application.hpp"
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
	for (auto& tile : mNodes)
		renderTarget.draw(tile->getNodeImage());
}

void Grid::processEvents(sf::Event& event, MousePositions& mousePositions)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (!isPositionProper(mousePositions.mMouseWorldPosition))
			return;
		if (event.mouseButton.button == sf::Mouse::Left)
			setStartingNode(getPressedNode(mousePositions.mMouseWorldPosition));
		else if (event.mouseButton.button == sf::Mouse::Right)
			setTargetedNode(getPressedNode(mousePositions.mMouseWorldPosition));
		break;
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::R)
			restartGrid();
		break;
	}

}

void Grid::createGrid()
{
	for (int i = 0; i < mGridSizeX; ++i)
		for (int ii = 0; ii < mGridSizeY; ++ii)
			mNodes.emplace_back(std::make_unique<Node>(sf::Vector2f(i * mTileSize, ii * mTileSize), mTileSize));
}

void Grid::restartGrid()
{
	mStartingNode = nullptr;
	mTargetedNode = nullptr;
	mNodes.clear();
	createGrid();
}

bool Grid::isPositionProper(const sf::Vector2f position)
{
	if (static_cast<int>(position.x) / mTileSize > mGridSizeX ||
		static_cast<int>(position.y) / mTileSize > mGridSizeY)
		return false;
	else 
		return true;
}

Node* Grid::getPressedNode(const sf::Vector2f pressPosition)
{
	int xPosition = static_cast<int>(pressPosition.x) / mTileSize;
	int yPosition = static_cast<int>(pressPosition.y) / mTileSize;
	int tilePosition = mGridSizeY * xPosition + yPosition;
	return mNodes[tilePosition].get();
}

void Grid::setStartingNode(Node* const startingNode)
{
	if (mStartingNode != nullptr)
		mStartingNode->setType(NodeType::None);

	mStartingNode = startingNode;
	mStartingNode->setType(NodeType::StartingTile);
}

void Grid::setTargetedNode(Node* const targetedNode)
{
	if (mTargetedNode != nullptr)
		mTargetedNode->setType(NodeType::None);

	mTargetedNode = targetedNode;
	mTargetedNode->setType(NodeType::TargetedTile);
}

