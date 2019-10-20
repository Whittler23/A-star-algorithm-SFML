#pragma once

#include <SFML/Graphics.hpp>

struct MousePositions;

class Button : public sf::Drawable
{
public:
	enum class ButtonState { Idle, Hover, Press };
	enum class ButtonType { Button, Switch };

	Button(const sf::Vector2f viewSize, const sf::Vector2f percentPosition, const std::string& text, ButtonType buttonType = ButtonType::Button);
	~Button();

	virtual void update();
	void processEvents(sf::Event& event, MousePositions& mousePositions);
	void draw(sf::RenderTarget& rt, sf::RenderStates) const override;

	bool isPressed();


private:
	void init(const sf::Vector2f percentPosition, const sf::Vector2f viewSize, ButtonType buttonType);
	sf::Vector2f getTextPosition();
	sf::Vector2f getPofV(const float percentX, const float percentY, const sf::Vector2f& size);

protected:
	ButtonState mButtonState;
	sf::RectangleShape mButtonBox;
	sf::Text mText;

private:
	sf::Font mFont;
	sf::Vector2f mPosition;
};