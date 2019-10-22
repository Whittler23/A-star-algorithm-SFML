#include "Gui/switchButton.hpp"
#include "mousePositions.hpp"

SwitchButton::SwitchButton(const sf::Vector2f viewSize, const sf::Vector2f percentPosition, const std::string& text)
	:Button(viewSize, percentPosition, text, ButtonType::Switch)
	,mSwitchState(false)
{
	mButtonBox.setFillColor(sf::Color(97, 0, 11, 190)); //dark-red
	mText.setString("DIAG\n OFF");
}

void SwitchButton::update()
{
	if (mSwitchClock.getElapsedTime().asMilliseconds() < 350.f) return;

	if (mButtonState == ButtonState::Press)
	{
		mSwitchState = !mSwitchState;
		mSwitchClock.restart();
	}

	if (mSwitchState)
	{
		mButtonBox.setFillColor(sf::Color(55, 128, 74, 190)); //dark-green
		mText.setString("DIAG ON");
	}
	else
	{
		mButtonBox.setFillColor(sf::Color(97, 0, 11, 190)); //dark-red
		mText.setString("DIAG OFF");
	}
}

bool SwitchButton::getState()
{
	return mSwitchState;
}