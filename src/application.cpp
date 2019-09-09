#include "application.hpp"

const int mWidthOfTheGrid = 20;
const int mHeightOfTheGrid = 10;
const int mSizeOfTheTiles = 20;

Application::Application()
	:mWindow(sf::VideoMode::getDesktopMode(), "AStar")
	,mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles)
	,mExit(false)
{
}

void Application::run()
{
	while (mExit != true)
	{
		processEvents();
		getInput();
		update();
		draw();
	}
}

void Application::update()
{
	//mGrid.update();
}

void Application::getInput()
{
	//eventsHandling();
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
		switch (event.type)
		{
		case sf::Event::Closed:
			mExit = true;
			break;
		case sf::Event::Resized:
			sf::FloatRect fixedView(0, 0, event.size.width, event.size.height);
			mWindow.setView(sf::View(fixedView));
		}
	}
}