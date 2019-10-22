#pragma once

#include "grid.hpp"
#include "pathSolver.hpp"
#include "Gui/gui.hpp"
#include "mousePositions.hpp"
#include "Gui/informationWindow.hpp"

#include <SFML/Graphics.hpp>

class Application
{
public:
	Application();

	void run();

private:
	void init();

	void update();
	void draw();

	void processEvents();
	void processApplicationEvents(sf::Event& event);
	void processButtons();

	void restart();

private:
	sf::RenderWindow mWindow;
	Grid mGrid;
	Gui mGui;
	MousePositions mMousePositions;
	InformationWindow mInformationWindow;
	PathSolver mPathSolver;
	bool mExit;
};