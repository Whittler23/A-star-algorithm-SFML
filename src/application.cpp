#include <iostream>
#include <SFML/Graphics.hpp>

#include "grid.hpp"

int main()
{
	sf::RenderWindow appWindow(sf::VideoMode(600, 400), "AStar");
	Grid mGrid(20, 20, 50);

	while (true)
	{
		appWindow.clear();
		appWindow.draw(mGrid);
		appWindow.display();
	}
	
	std::cout << "Hello world!" << std::endl;
}