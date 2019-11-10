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

void Tile::changeColor(NodeType nodeType)
{
	switch (nodeType)
	{
	case NodeType::StartingNode:
		mTileImage.setFillColor(sf::Color(0, 177, 89)); //green
		break;
	case NodeType::TargetedNode:
		mTileImage.setFillColor(sf::Color(209, 17, 65)); //red
		break;
	case NodeType::PathNode:
		mTileImage.setFillColor(sf::Color(0, 174, 219)); //cyan
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
	,mParentNode(nullptr)
	,mNodeType(NodeType::None)
	,xGridPosition(tilePosition.x)
	,yGridPosition(tilePosition.y)
	,mGCost(0)
	,mHCost(0)
{
	mTile.changeColor(mNodeType);
}

void Node::setType(NodeType nodeType)
{
	mNodeType = nodeType;
	mTile.changeColor(mNodeType);
}

void Node::setParentNode(Node* const parentNode)
{
	mParentNode = parentNode; 
}

void Node::setGCost(const int gcost)
{ 
	mGCost = gcost; 
}

void Node::setHCost(const int hcost)
{
	mHCost = hcost;
}

int Node::getFCost()
{
	return mGCost + mHCost;
}

int Node::getGCost()
{
	return mGCost;
}

int Node::getHCost()
{
	return mHCost;
}

NodeType Node::getType()
{ 
	return mNodeType;
}

Node* Node::getParent()
{
	return mParentNode;
}

bool Node::isWalkable()
{ 
	return mNodeType != NodeType::ObstacleNode; 
}

sf::Vector2i Node::getPosition() const
{ 
	return sf::Vector2i(xGridPosition, yGridPosition);
}

Tile& Node::getNodeImage()
{
	return mTile;
}