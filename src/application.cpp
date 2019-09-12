#include "application.hpp"
#include "inputHandler.hpp"

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
	InputHandler::clear();
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mExit = true;
			break;

		case sf::Event::Resized:
		{
			sf::FloatRect fixedView(0, 0, event.size.width, event.size.height);
			mWindow.setView(sf::View(fixedView));
			break;
		}

		case sf::Event::MouseMoved:
		{
			sf::Vector2i mouseViewPosition = sf::Mouse::getPosition(mWindow);
			sf::Vector2f mouseWorldPosition = mWindow.mapPixelToCoords(mouseViewPosition);
			InputHandler::setMouseViewPosition(mouseViewPosition);
			InputHandler::setMouseWorldPosition(mouseWorldPosition);
			break;
		}

		case sf::Event::MouseButtonPressed:
			InputHandler::setLastMouseViewPressPosition();
			InputHandler::setLastMouseWindowPressPosition();
			break;

		case sf::Event::KeyPressed:
		{
			InputHandler::setLastPressedKey(event.key.code);
			break;
		}

		}
	}
}