#include "application.hpp"
#include "Gui/switchButton.hpp"

namespace {
const int mWidthOfTheGrid = 32;
const int mHeightOfTheGrid = 18;
const int mSizeOfTheTiles = 40;
}

Application::Application()
	:mWindow(sf::VideoMode(1600, 900), "AStar")
	,mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles)
	,mExit(false)
	,mGui(mWindow)
{
	init();
	mGui.init();
}

void Application::init()
{
	float sizeX = mSizeOfTheTiles * mWidthOfTheGrid;
	float sizeY = mSizeOfTheTiles * mHeightOfTheGrid;
	sf::FloatRect viewSize = { 0, 0, sizeX, sizeY };
	mWindow.setView(sf::View(viewSize));
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

void Application::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mGui.processEvents(event, mMousePositions);
		processApplicationEvents(event);
		if (!mGui.getInteracted())
			mGrid.processEvents(event, mMousePositions);
	}
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
		if (mPathSolver.getSolved() && !mGui.getInteracted())
			restart();
	}
}

void Application::processButtons()
{
	if (!mGui.getInteracted())
		return;
	if (mGui.isButtonPressed("EXIT"))
		mExit = true;
	else if (mGui.isButtonPressed("SOLVE"))
		mPathSolver.solveGrid(mGrid);
	else if (mGui.isButtonPressed("RESTART"))
		restart();
	else if (mGui.isButtonPressed("RESTART_OBSTACLES"))
		mGrid.restartObstacles();
	//TODO: Bump so it's not updated every cycle
	mGrid.setDiagonal(mGui.getButtonSwitchState("DIAG"));
}

void Application::update()
{
	mPathSolver.update();
	mGui.update();
	if(mPathSolver.getSolved())
		mInformationWindow.update(mPathSolver.getSolveTime());
}

void Application::draw()
{
	mWindow.clear();
	mWindow.draw(mGrid);
	mWindow.draw(mInformationWindow);
	mGui.draw();
	mWindow.display();
}

void Application::restart()
{
	mPathSolver.restartSolver();
	mGrid.restartGrid();
}