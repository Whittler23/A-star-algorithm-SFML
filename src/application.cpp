#include "application.hpp"

const int mWidthOfTheGrid = 16;
const int mHeightOfTheGrid = 9;
const int mSizeOfTheTiles = 10;

Application::Application()
	:mWindow(sf::VideoMode(1600, 900), "AStar")
	,mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles)
	,mExit(false)
{
	float sizeX = mSizeOfTheTiles * mWidthOfTheGrid;
	float sizeY = mSizeOfTheTiles * mHeightOfTheGrid;
	sf::FloatRect viewSize = { 0, 0, sizeX, sizeY};
	mWindow.setView(sf::View(viewSize));
}

void Application::run()
{
	while (mExit != true)
	{
		processEvents();
		update();
		draw();
	}
}

void Application::update()
{
	//mGrid.update();
}

void Application::draw()
{
	mWindow.clear();
	mWindow.draw(mGrid);
	mWindow.display();
}

void Application::processEvents()

{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		processApplicationEvents(event);
		mGrid.processEvents(event, mMousePositions);
		//mGui.processEvents(event);
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
	}
}