#pragma once

#include "grid.hpp"
#include "pathSolver.hpp"
#include "gui.hpp"
#include "mousePositions.hpp"

#include <SFML/Graphics.hpp>

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
	Gui mGui;
	PathSolver mPathSolver;
	bool mExit;
};