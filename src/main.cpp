#include "application.hpp"
#include "Gui/errorWindow.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	try {
		Application app;

		app.run();
	}
	catch (std::runtime_error& e)
	{
		showErrorWindow("Error!", e.what());
	}
}