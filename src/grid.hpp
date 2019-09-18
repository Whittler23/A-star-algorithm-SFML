#pragma once

#include "tile.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

struct MousePositions;

class Grid : public sf::Drawable
{
public:
	Grid(int width, int height, int tileSize);
	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;

	void setStartingNode(Node* const startingNode);
	void setTargetedNode(Node* const targetedNode);

	Node* getStartingNode() { return mStartingNode; }
	void processEvents(sf::Event& event, MousePositions& mousePositions);

private:
	void createGrid();
	void restartGrid();
	Node* getPressedNode(const sf::Vector2f pressPosition);
	bool isPositionProper(const sf::Vector2f position);

private:
	int mGridSizeX;
	int mGridSizeY;
	int mTileSize;
	std::vector<std::unique_ptr<Node>> mNodes;
	Node* mStartingNode;
	Node* mTargetedNode;
};
