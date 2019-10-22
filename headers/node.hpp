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
	void changeColor(NodeType nodeType);

private:
	sf::RectangleShape mTileImage;

};

class Node
{
public:
	Node(const sf::Vector2i& tilePosition, const int tileSize);

	void setType(NodeType nodeType);
	void setParentNode(Node* const parentNode);
	void setGCost(const int gcost);
	void setHCost(const int hcost);

	int getFCost();
	int getGCost();
	int getHCost();
	NodeType getType();
	Node* getParent();

	bool isWalkable();
	sf::Vector2i getPosition() const;
	Tile& getNodeImage();

private:
	Tile mTile;
	Node* mParentNode;
	NodeType mNodeType;
	int xGridPosition;
	int yGridPosition;
	int mGCost;
	int mHCost;

};