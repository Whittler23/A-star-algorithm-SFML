#pragma once

#include <SFML/Graphics.hpp>

class InformationWindow : public sf::Drawable
{
public:
	InformationWindow();

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;
	void update(float time);
	sf::Vector2f getTextPosition();
private:
	sf::RectangleShape mBackground;
	sf::Text mInformationText;
	sf::Font mFont;
};