#ifndef BORDER_H
#define BORDER_H

#include "collidable.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Border : public Collidable
{
public:
    Border(int x, int y, int width, int height);
    void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape m_rs;
};

#endif // BORDER_H
