#pragma once

#include <SFML/Graphics.hpp>

enum class NodeType
{
	StartingNode, TargetedNode, PathNode, ObstacleNode, HoverNode, None
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

	sf::Vector2f getPosition() { return sf::Vector2f(xGridPosition, yGridPosition); }
	Tile& getNodeImage() { return mTile; }

private:
	NodeType mNodeType;
	Tile mTile;
	int xGridPosition;
	int yGridPosition;
	int gCost;
	int hCost;
	int fCost;
};