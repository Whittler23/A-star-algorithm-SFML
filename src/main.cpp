#include <iostream>
#include <SFML/Graphics.hpp>

#include "application.hpp"

int main()
{
	try {
		Application app;

		app.run();
	}
	//TODO: Add popping error window
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
}