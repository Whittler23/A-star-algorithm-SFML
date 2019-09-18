#pragma once

#include <SFML/Graphics.hpp>

enum class NodeType
{
	StartingTile, TargetedTile, PathTile, HoverTile, None
};

class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile(const sf::Vector2f& tilePosition, const int tileSize);

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;
	void reactToNodeType(NodeType nodeType);

private:
	sf::RectangleShape mTileImage;

};

class Node
{
public:
	Node(const sf::Vector2f& tilePosition, const int tileSize);

	void setType(NodeType nodeType);
	Tile& getNodeImage() { return mTile; }

private:
	Tile mTile;
	NodeType mNodeType;
};