#include "Gui/errorWindow.hpp"
#include <Windows.h>

void showErrorWindow(const std::string& title, const std::string& message)
{
	MessageBox(NULL, message.c_str(), title.c_str(), MB_OK | MB_ICONERROR);
}