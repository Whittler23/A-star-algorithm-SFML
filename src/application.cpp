#include "application.hpp"

const int mWidthOfTheGrid = 20;
const int mHeightOfTheGrid = 10;
const int mSizeOfTheTiles = 20;

Application::Application()
	:mWindow(sf::VideoMode(1600, 900), "AStar")
	,mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles)
	,mExit(false)
{
	sf::FloatRect viewSize = { 0, 0, mSizeOfTheTiles * mWidthOfTheGrid, mSizeOfTheTiles * mHeightOfTheGrid};
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