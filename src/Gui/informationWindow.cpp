#include "Gui/informationWindow.hpp"

InformationWindow::InformationWindow()
	:mBackground(sf::Vector2f(370.f, 60.f))
	,mInformationText("Computation time taken: no performed", sf::Font())
{
	mBackground.setFillColor(sf::Color(20, 18, 18, 150));
	mBackground.setOutlineThickness(3.f);
	mBackground.setOutlineColor(sf::Color::Black);
	mFont.loadFromFile("resources/defaultFont.ttf");
	mInformationText.setFont(mFont);
	mInformationText.setFillColor(sf::Color::White);
	mInformationText.setPosition(getTextPosition());
}

void InformationWindow::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(mBackground);
	renderTarget.draw(mInformationText);
}

sf::Vector2f InformationWindow::getTextPosition()
{
	auto textBounds(mInformationText.getGlobalBounds());
	auto buttonBox(mBackground.getSize());
	mInformationText.setOrigin((textBounds.width - buttonBox.x) / 2 + textBounds.left,
		(textBounds.height - buttonBox.y) / 2 + textBounds.top);

	return sf::Vector2f(mBackground.getPosition().x,
		mBackground.getPosition().y);
}

void InformationWindow::update(float time)
{
	std::string timeElapsed = std::to_string(static_cast<int>(time));
	mInformationText.setString("Computation time taken: " + timeElapsed + " ms");
}