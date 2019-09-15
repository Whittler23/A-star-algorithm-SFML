#pragma once

#include <SFML/Graphics.hpp>

enum class TileType
{
	StartingTile, TargetedTile, PathTile, HoverTile, None
};

class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile(const sf::Vector2f& tilePosition, const int tileSize);

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;
	void setType(TileType tileType);

private:
	int mTileSize;
	sf::RectangleShape mTileImage;
	TileType mTileType;
};