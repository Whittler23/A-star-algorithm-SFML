#include "tile.hpp"

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
	case NodeType::StartingTile:
		mTileImage.setFillColor(sf::Color::Green);
		break;
	case NodeType::TargetedTile:
		mTileImage.setFillColor(sf::Color::Red);
		break;
	case NodeType::PathTile:
		mTileImage.setFillColor(sf::Color::Blue);
		break;
	case NodeType::HoverTile:
		mTileImage.setFillColor(sf::Color::Blue);
		break;
	case NodeType::None:
		mTileImage.setFillColor(sf::Color::White);
	}
}

Node::Node(const sf::Vector2f& tilePosition, const int tileSize)
	:mTile(tilePosition, tileSize)
	,mNodeType(NodeType::None)
{
	mTile.reactToNodeType(mNodeType);
}

void Node::setType(NodeType nodeType)
{
	mNodeType = nodeType;
	mTile.reactToNodeType(mNodeType);
}