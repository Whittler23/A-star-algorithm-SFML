#pragma once

#include "button.hpp"

class SwitchButton : public Button
{
public:
	SwitchButton(const sf::Vector2f viewSize, const sf::Vector2f percentPosition, const std::string& text);
	void update() override;

	bool getState();

private:
	sf::Clock mSwitchClock;
	bool mSwitchState;
};