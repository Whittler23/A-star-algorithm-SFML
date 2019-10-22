#pragma once

#include "button.hpp"

#include <SFML/Graphics.hpp>

struct MousePositions;

class Gui
{
public:
	Gui(sf::RenderTarget& renderTarget);

	void update();
	void draw() const;
	void processEvents(sf::Event& event, MousePositions& mousePositions);

	bool isButtonPressed(const std::string& buttonName);
	bool getButtonSwitchState(const std::string& buttonName);
	Button* getButton(const std::string& buttonName);
	bool getInteracted() { return mInteracted; }

	void init();

private:
	sf::RenderTarget& mRenderTarget;
	std::map<std::string, std::unique_ptr<Button>> mButtons;
	bool mInteracted;
};