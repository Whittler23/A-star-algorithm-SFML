////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_DRAWABLE_HPP
#define SFML_DRAWABLE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>


namespace sf
{
class RenderTarget;

////////////////////////////////////////////////////////////
/// \brief Abstract base class for objects that can be drawn
///        to a render target
///
////////////////////////////////////////////////////////////
class SFML_GRAPHICS_API Drawable
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Virtual destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~Drawable() {}

protected:

    friend class RenderTarget;

    ////////////////////////////////////////////////////////////
    /// \brief Draw the object to a render target
    ///
    /// This is a pure virtual function that has to be implemented
    /// by the derived class to define how the drawable should be
    /// drawn.
    ///
    /// \param target Render target to draw to
    /// \param mStates Current render mStates
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
};

} // namespace sf


#endif // SFML_DRAWABLE_HPP


////////////////////////////////////////////////////////////
/// \class sf::Drawable
/// \ingroup graphics
///
/// sf::Drawable is a very simple base class that allows objects
/// of derived classes to be drawn to a sf::RenderTarget.
///
/// All you have to do in your derived class is to override the
/// draw virtual function.
///
/// Note that inheriting from sf::Drawable is not mandatory,
/// but it allows this nice syntax "window.draw(object)" rather
/// than "object.draw(window)", which is more consistent with other
/// SFML classes.
///
/// Example:
/// \code
/// class MyDrawable : public sf::Drawable
/// {
/// public:
///
///    ...
///
/// private:
///
///     virtual void draw(sf::RenderTarget& target, sf::RenderStates mStates) const
///     {
///         // You can draw other high-level objects
///         target.draw(m_sprite, mStates);
///
///         // ... or use the low-level API
///         mStates.texture = &m_texture;
///         target.draw(m_vertices, mStates);
///
///         // ... or draw with OpenGL directly
///         glBegin(GL_QUADS);
///         ...
///         glEnd();
///     }
///
///     sf::Sprite m_sprite;
///     sf::Texture m_texture;
///     sf::VertexArray m_vertices;
/// };
/// \endcode
///
/// \see sf::RenderTarget
///
////////////////////////////////////////////////////////////
