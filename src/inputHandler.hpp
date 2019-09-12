#pragma once

#include <SFML/Graphics.hpp>

class InputHandler
{
public:
	static void setLastPressedKey(sf::Keyboard::Key lastPressedKey);

	static void setMouseWorldPosition(const sf::Vector2f& mouseWorldPosition);
	static void setMouseViewPosition(const sf::Vector2i& mouseViewPosition);

	static void setLastMouseViewPressPosition();
	static void setLastMouseWindowPressPosition();

	static bool isKeyPressed(sf::Keyboard::Key key);

	static sf::Vector2i getMouseViewPosition();
	static sf::Vector2i getLastMouseViewPress();

	static sf::Vector2f getMouseWorldPosition();
	static sf::Vector2f getLastMouseWorldPress();

	static void clear();

private:
	inline static sf::Keyboard::Key mLastPressedKey;

	inline static sf::Vector2i mLastMouseViewPress;
	inline static sf::Vector2f mLastMouseWorldPress;

	inline static sf::Vector2i mMouseViewPosition;
	inline static sf::Vector2f mMouseWorldPosition;
};