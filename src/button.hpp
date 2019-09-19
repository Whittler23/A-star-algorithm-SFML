#pragma once

#include <SFML/Graphics.hpp>

struct MousePositions;

class Button : public sf::Drawable
{
public:
	Button(const sf::Vector2f viewSize, const sf::Vector2f percentPosition, const std::string& text);
	~Button();

	void update();
	void processEvents(sf::Event& event, MousePositions& mousePositions);
	void draw(sf::RenderTarget& rt, sf::RenderStates) const override;

	bool isPressed();
	bool getActive();
	void setActive(const bool active);

private:
	void init(const sf::Vector2f percentPosition, const sf::Vector2f viewSize);

	sf::Vector2f getTextPosition();
	sf::Vector2f getPofV(const float percentX, const float percentY, const sf::Vector2f& size);

	enum class ButtonState { Idle, Hover, Press };

private:
	sf::RectangleShape mButtonBox;
	sf::Text mText;
	sf::Font mFont;
	sf::Vector2f mPosition;
	ButtonState mButtonState;
	bool mActive;
};