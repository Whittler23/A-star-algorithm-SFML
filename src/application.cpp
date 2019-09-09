#include <iostream>
#include <SFML/Graphics.hpp>

#include "grid.hpp"

int main()
{
	sf::RenderWindow appWindow(sf::VideoMode(600, 400), "AStar");

	const int mWidthOfTheGrid = 20;
	const int mHeightOfTheGrid = 10;
	const int mSizeOfTheTiles = 20;

	Grid mGrid(mWidthOfTheGrid, mHeightOfTheGrid, mSizeOfTheTiles);

	while (true)
	{
		appWindow.clear();
		appWindow.draw(mGrid);
		appWindow.display();
	}
	
	std::cout << "Hello world!" << std::endl;
}