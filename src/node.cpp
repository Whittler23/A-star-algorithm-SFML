#include "node.hpp"

Tile::Tile(const sf::Vector2f& position, const int size)
	:mTileImage(sf::Vector2f(size, size))
{
	const float outlineThickness = size / 25.f;
	mTileImage.setPosition(position);
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

Node::Node(const sf::Vector2f& tilePosition, const int tileSize)
	:mTile(tilePosition, tileSize)
	,mNodeType(NodeType::None)
	,mParentNode(nullptr)
	,xGridPosition(tilePosition.x)
	,yGridPosition(tilePosition.y)
	,mHCost(0)
	,mFCost(0)
	,mGCost(0)
{
	mTile.reactToNodeType(mNodeType);
}

void Node::setType(NodeType nodeType)
{
	mNodeType = nodeType;
	mTile.reactToNodeType(mNodeType);
}