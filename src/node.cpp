#include "node.hpp"

Tile::Tile(const sf::Vector2i& position, const int size)
	:mTileImage(sf::Vector2f(size, size))
{
	const float outlineThickness = size / 25.f;
	mTileImage.setPosition(sf::Vector2f(position));
	mTileImage.setOutlineColor(sf::Color::Black);
	mTileImage.setOutlineThickness(outlineThickness);
}

void Tile::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(mTileImage);
}

void Tile::reactToNodeType(NodeType nodeType)
{
	switch (nodeType)
	{
	case NodeType::StartingNode:
		mTileImage.setFillColor(sf::Color(84, 184, 94)); //green
		break;
	case NodeType::TargetedNode:
		mTileImage.setFillColor(sf::Color(112, 43, 181)); //purple
		break;
	case NodeType::PathNode:
		mTileImage.setFillColor(sf::Color(12, 162, 204)); //cyan
		break;
	case NodeType::ObstacleNode:
		mTileImage.setFillColor(sf::Color::Black);
		break;
	case NodeType::None:
		mTileImage.setFillColor(sf::Color::White);
	}
}

Node::Node(const sf::Vector2i& tilePosition, const int tileSize)
	:mTile(tilePosition, tileSize)
	,mNodeType(NodeType::None)
	,mParentNode(nullptr)
	,xGridPosition(tilePosition.x+tileSize/2) //setting center of the tile on XAxis
	,yGridPosition(tilePosition.y+tileSize/2) //setting center of the tile on YAxis
	,mHCost(0)
	,mGCost(0)
{
	mTile.reactToNodeType(mNodeType);
}

void Node::setType(NodeType nodeType)
{
	mNodeType = nodeType;
	mTile.reactToNodeType(mNodeType);
}