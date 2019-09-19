#include "gui.hpp"

Gui::Gui(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mInteracted(false)
{
}

void Gui::init()
{
	mButtons.insert(std::make_pair("SOLVE", std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 10.f), "SOLVE")));
	mButtons.insert(std::make_pair("RESTART", std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 30.f), "RESTART")));
	mButtons.insert(std::make_pair("RESTART_OBSTACLES", std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 50.f), "	RESTART\n OBSTACLES")));
	mButtons.insert(std::make_pair("EXIT", std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 70.f), "EXIT")));
}

void Gui::processEvents(sf::Event& event, MousePositions& mousePositions)
{
	mInteracted = false;
	for (auto& button : mButtons)
	{
		button.second->processEvents(event, mousePositions);
		if (button.second->isPressed())
			mInteracted = true;
	}
}

void Gui::update()
{
	for (auto& button : mButtons)
		button.second->update();
}

void Gui::draw() const
{
	for (auto& button : mButtons)
		mRenderTarget.draw(*button.second);
}

bool Gui::isButtonPressed(const std::string& buttonName)
{
	return mButtons[buttonName]->isPressed();
}

Button* Gui::getButton(const std::string& buttonName)
{
	return mButtons[buttonName].get();
}

