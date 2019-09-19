#pragma once

#include <SFML/Graphics.hpp>

enum class NodeType
{
	StartingNode, TargetedNode, PathNode, ObstacleNode, None
};

class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile(const sf::Vector2i& tilePosition, const int tileSize);

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;
	void reactToNodeType(NodeType nodeType);

private:
	sf::RectangleShape mTileImage;

};

class Node
{
public:
	Node(const sf::Vector2i& tilePosition, const int tileSize);

	void setType(NodeType nodeType);

	void setParentNode(Node* const parentNode) { mParentNode = parentNode; }
	void setGCost(const int gcost) { mGCost = gcost; }
	void setHCost(const int hcost) { mHCost = hcost; }

	int getFCost() { return mGCost + mHCost; }
	int getGCost() { return mGCost; }
	int getHCost() { return mHCost; }
	sf::Vector2i getPosition() { return sf::Vector2i(xGridPosition, yGridPosition); }

	Tile& getNodeImage() { return mTile; }

private:
	NodeType mNodeType;
	Node* mParentNode;
	Tile mTile;
	int xGridPosition;
	int yGridPosition;
	int mGCost;
	int mHCost;
};