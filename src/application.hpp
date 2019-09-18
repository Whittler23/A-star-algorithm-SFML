#pragma once

#include "grid.hpp"
#include "pathSolver.hpp"

#include <SFML/Graphics.hpp>

struct MousePositions
{
	sf::Vector2f mMouseWorldPosition;
	sf::Vector2i mMouseViewPosition;
};

class Application
{
public:
	Application();

	void run();

private:
	void update();
	void draw();

	void processEvents();
	void processApplicationEvents(sf::Event& event);

private:
	sf::RenderWindow mWindow;
	MousePositions mMousePositions;
	Grid mGrid;
	PathSolver mPathSolver;
	bool mExit;
};