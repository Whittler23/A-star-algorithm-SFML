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

	void init();

private:
	sf::RenderTarget& mRenderTarget;
	std::vector<std::unique_ptr<Button>> mButtons;
};