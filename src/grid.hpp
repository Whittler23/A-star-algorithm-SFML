#pragma once

#include "tile.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

class Grid : public sf::Drawable
{
public:
	Grid(int width, int height, int tileSize);
	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;

private:
	void createGrid();

private:
	int mGridSizeX;
	int mGridSizeY;
	int mTileSize;
	std::vector<std::unique_ptr<Tile>> mTiles;
};
