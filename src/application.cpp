#include "application.hpp"

const int mWidthOfTheGrid = 25;
const int mHeightOfTheGrid = 17;
const int mSizeOfTheTiles = 40;

Application::Application()
	:mWindow(sf::VideoMode(1600, 900), "AStar")
	,mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles)
	,mExit(false)
	,mGui(mWindow)
{
	float sizeX = mSizeOfTheTiles * mWidthOfTheGrid;
	float sizeY = mSizeOfTheTiles * mHeightOfTheGrid;
	sf::FloatRect viewSize = { 0, 0, sizeX, sizeY};
	mWindow.setView(sf::View(viewSize));
	mGui.init();
}

void Application::run()
{
	while (mExit != true)
	{
		processEvents();
		processButtons();
		update();
		draw();
	}
}

void Application::update()
{
	mPathSolver.update();
	mGui.update();
}

void Application::draw()
{
	mWindow.clear();
	mWindow.draw(mGrid);
	mGui.draw();
	mWindow.display();
}

void Application::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		processApplicationEvents(event);
		mGui.processEvents(event, mMousePositions);
		if(!mGui.getInteracted())
			mGrid.processEvents(event, mMousePositions);
	}
}

void Application::processButtons()
{
	if (mGui.isButtonPressed("EXIT"))
		mExit = true;
	else if (mGui.isButtonPressed("SOLVE"))
		mPathSolver.solveGrid(mGrid);
	else if (mGui.isButtonPressed("RESTART"))
		restart();
	else if (mGui.isButtonPressed("RESTART_OBSTACLES"))
		mGrid.restartObstacles();
}

void Application::processApplicationEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		mExit = true;
		break;

	case sf::Event::MouseMoved:
		mMousePositions.mMouseViewPosition = sf::Mouse::getPosition(mWindow);
		mMousePositions.mMouseWorldPosition = mWindow.mapPixelToCoords(mMousePositions.mMouseViewPosition);
		break;

	case sf::Event::MouseButtonPressed:
		if (mPathSolver.getSolved())
			restart();
	}
}

void Application::restart()
{
	mPathSolver.restartSolver();
	mGrid.restartGrid();
}