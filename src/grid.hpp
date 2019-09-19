#pragma once

#include <SFML/Graphics.hpp>
#include "node.hpp"

#include <vector>
#include <memory>

struct MousePositions;
class Node;

class Grid : public sf::Drawable
{
public:
	Grid(int width, int height, int tileSize);
	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;
	void processEvents(sf::Event& event, MousePositions& mousePositions);
	void restartGrid();

	void setStartingNode(Node* const startingNode);
	void setTargetedNode(Node* const targetedNode);
	void setObstacle(Node* const targetedNode);

	Node* getStartingNode() { return mStartingNode; }
	Node* getTargetedNode() { return mTargetedNode; }
	std::vector<Node*> getNeighbours(Node* const node);
	Node* getNodeInWorld(const sf::Vector2i);

private:
	void createGrid();
	bool isPositionProper(const sf::Vector2i position);

private:
	int mGridSizeX;
	int mGridSizeY;
	int mTileSize;
	std::vector<std::unique_ptr<Node>> mNodes;
	Node* mStartingNode;
	Node* mTargetedNode;
};
