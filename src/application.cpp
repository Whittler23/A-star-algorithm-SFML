#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow appWindow(sf::VideoMode(1920, 1080), "AStar");

	while (true)
	{
		appWindow.clear();
		appWindow.display();
	}

	std::cout << "Hello world!" << std::endl;
}