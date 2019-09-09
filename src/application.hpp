#pragma once

#include "grid.hpp"

#include <SFML/Graphics.hpp>

class Application
{
public:
	Application();

	void run();

private:
	void update();
	void draw();
	void getInput();

	void processEvents();

private:
	sf::RenderWindow mWindow;
	Grid mGrid;
	bool mExit;
};