#include "button.hpp"
#include "../mousePositions.hpp"

Button::Button(const sf::Vector2f viewSize, const sf::Vector2f percentPosition, const std::string& text, ButtonType buttonType)
	:mButtonState(ButtonState::Idle)
	,mText(text, sf::Font())
{
	init(percentPosition, viewSize, buttonType);
}

Button::~Button()
{
}

void Button::init(const sf::Vector2f percentPosition, const sf::Vector2f viewSize, ButtonType buttonType)
{
	mFont.loadFromFile("font/defaultFont.ttf");
	mText.setFont(mFont);

	switch (buttonType)
	{
	case ButtonType::Button:
		mButtonBox.setPosition(getPofV(percentPosition.x, percentPosition.y, viewSize));
		mButtonBox.setSize(getPofV(20, 15, viewSize));
		mButtonBox.setOutlineThickness(mButtonBox.getSize().x / 40.f);
		mButtonBox.setOutlineColor(sf::Color::Black);
		mText.setCharacterSize(35);
		break;
	case ButtonType::Switch:
		mButtonBox.setPosition(getPofV(percentPosition.x, percentPosition.y, viewSize));
		mButtonBox.setSize(getPofV(10, 7, viewSize));
		mButtonBox.setOutlineThickness(mButtonBox.getSize().x / 40.f);
		mButtonBox.setOutlineColor(sf::Color::Black);
		mText.setCharacterSize(23);
		break;
	}

	mText.setPosition(getTextPosition());
}

sf::Vector2f Button::getTextPosition()
{
	auto textBounds(mText.getGlobalBounds());
	auto buttonBox(mButtonBox.getSize());
	mText.setOrigin((textBounds.width - buttonBox.x) / 2 + textBounds.left,
		(textBounds.height - buttonBox.y) / 2 + textBounds.top);

	return sf::Vector2f(mButtonBox.getPosition().x,
		mButtonBox.getPosition().y);
}

void Button::update()
{
	switch (mButtonState)
	{
	case ButtonState::Idle:
		mButtonBox.setFillColor(sf::Color(97, 97, 97, 100)); //light-grey
		break;
	case ButtonState::Hover:
		mButtonBox.setFillColor(sf::Color(161, 159, 159, 150)); //stronger ligh-grey
		break;
	case ButtonState::Press:
		mButtonBox.setFillColor(sf::Color(55, 128, 74, 150)); //dark-green
		break;
	}
}

void Button::processEvents(sf::Event& event, MousePositions& mousePositions)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
	{
		if (mButtonBox.getGlobalBounds().contains(mousePositions.mMouseWorldPosition))
			mButtonState = ButtonState::Hover;
		else
			mButtonState = ButtonState::Idle;
	} break;

	case sf::Event::MouseButtonPressed:
	{
		if (mButtonState == ButtonState::Hover)
			mButtonState = ButtonState::Press;
	} break;
	default:
	{
		mButtonState = ButtonState::Idle;
	}	break;
	}
}

void Button::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	rt.draw(mButtonBox);
	rt.draw(mText);
}

bool Button::isPressed()
{
	return (mButtonState == ButtonState::Press);
}

sf::Vector2f Button::getPofV(const float percentX, const float percentY, const sf::Vector2f& size)
{
	return sf::Vector2f(
		size.x * (percentX / 100),
		size.y * (percentY / 100)
	);
}