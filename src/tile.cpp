#include "tile.hpp"

Tile::Tile(const sf::Vector2f& position, const int size)
	:mTileSize(size)
	,mTileImage(sf::Vector2f(mTileSize, mTileSize))
{
	mTileImage.setPosition(position);
	mTileImage.setOutlineColor(sf::Color::Black);
	mTileImage.setOutlineThickness(1.f);
	mTileImage.setFillColor(sf::Color::Red);
}

void Tile::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(mTileImage);
}