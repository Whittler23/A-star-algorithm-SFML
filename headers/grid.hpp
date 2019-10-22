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
	void restartObstacles();

	void setDiagonal(bool set);

	Node* getStartingNode();
	Node* getTargetedNode();
	std::vector<Node*> getNeighbours(Node* const node);
	Node* getNodeInWorld(int posX, int posY);

private:
	void createGrid();
	void setStartingNode(Node* const startingNode);
	void setTargetedNode(Node* const targetedNode);
	void handleObstacle(Node* const obstacleNode);
	void setObstacle(Node* const obstacleNode);
	void removeObstacle(Node* const obstacleNode);

	bool isPositionProper(int posX, int posY);
	bool shouldIgnore(int val1, int val2);
	bool getNodeToSet();

private:
	std::vector<std::unique_ptr<Node>> mNodes;
	Node* mStartingNode;
	Node* mTargetedNode;
	int mGridSizeX;
	int mGridSizeY;
	int mTileSize;
	bool mDiagonalSearch;
};
