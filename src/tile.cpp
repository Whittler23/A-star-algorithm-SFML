#include "tile.hpp"

Tile::Tile(const sf::Vector2f& position, const int size)
	:mTileSize(size)
	,mTileImage(sf::Vector2f(mTileSize, mTileSize))
	,mTileType(TileType::None)
{
	mTileImage.setPosition(position);
	mTileImage.setOutlineColor(sf::Color::Black);
	mTileImage.setOutlineThickness(mTileSize/25.f);
}

void Tile::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(mTileImage);
}

void Tile::setType(TileType tileType)
{
	mTileType = tileType;
	switch (mTileType)
	{
	case TileType::StartingTile:
		mTileImage.setFillColor(sf::Color::Green);
		break;
	case TileType::TargetedTile:
		mTileImage.setFillColor(sf::Color::Red);
		break;
	case TileType::PathTile:
		mTileImage.setFillColor(sf::Color::Blue);
		break;
	case TileType::HoverTile:
		mTileImage.setFillColor(sf::Color::Blue);
		break;
	case TileType::None:
		mTileImage.setFillColor(sf::Color::White);
		break;
	default:
		break;
	}
}