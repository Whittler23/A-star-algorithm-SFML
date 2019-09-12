#include "inputHandler.hpp"

 void InputHandler::setLastPressedKey(sf::Keyboard::Key lastPressedKey)
 {
	 mLastPressedKey = lastPressedKey; 
 }

 void InputHandler::setMouseWorldPosition(const sf::Vector2f& mouseWorldPosition)
 {
	 mMouseWorldPosition = mouseWorldPosition;
 }
 void InputHandler::setMouseViewPosition(const sf::Vector2i& mouseViewPosition)
 {
	 mMouseViewPosition = mouseViewPosition;
 }

 void InputHandler::setLastMouseViewPressPosition()
 {
	 mLastMouseViewPress = mMouseViewPosition;
 }
 void InputHandler::setLastMouseWindowPressPosition()
 {
	 mLastMouseWorldPress = mMouseWorldPosition;
 }

 bool InputHandler::isKeyPressed(sf::Keyboard::Key key)
 {
	 if (mLastPressedKey == key)
		 return true;
	 else
		 return false;
 }

 sf::Vector2i InputHandler::getMouseViewPosition()
 {
	 return mMouseViewPosition; 
 }
 sf::Vector2i InputHandler::getLastMouseViewPress()
 {
	 return mLastMouseViewPress; 
 }

 sf::Vector2f InputHandler::getMouseWorldPosition()
 {
	 return mMouseWorldPosition;
 }
 sf::Vector2f InputHandler::getLastMouseWorldPress()
 {
	 return mLastMouseWorldPress; 
 }

 void InputHandler::clear()
 {
	 mLastPressedKey = sf::Keyboard::Key::Unknown;
 }