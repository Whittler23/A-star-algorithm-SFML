#include "grid.hpp"

Grid::Grid(int width, int height, int tileSize)
	:mGridSizeX(width)
	,mGridSizeY(height)
	,mTileSize(tileSize)
{
	createGrid();
}

void Grid::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	for (auto& tile : mTiles)
		renderTarget.draw(*tile);
}

void Grid::createGrid()
{
	for (int i = 0; i < mGridSizeX; ++i)
		for (int ii = 0; ii < mGridSizeY; ++ii)
			mTiles.emplace_back(std::make_unique<Tile>(sf::Vector2f(i * mTileSize, ii * mTileSize), mTileSize));
}

