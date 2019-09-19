#include "gui.hpp"

Gui::Gui(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
{
}

void Gui::init()
{
	mButtons.emplace_back(std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 20.f), "SOLVE"));
	mButtons.emplace_back(std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 40.f), "RESTART"));
	mButtons.emplace_back(std::make_unique<Button>(mRenderTarget.getView().getSize(), sf::Vector2f(79.f, 60.f), "EXIT"));
}

void Gui::processEvents(sf::Event& event, MousePositions& mousePositions)
{
	for (auto& button : mButtons)
		button->processEvents(event, mousePositions);
}

void Gui::update()
{
	for (auto& button : mButtons)
		button->update();
}

void Gui::draw() const
{
	for (auto& button : mButtons)
		mRenderTarget.draw(*button);
}

