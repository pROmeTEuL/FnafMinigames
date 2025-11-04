#include "border.h"

Border::Border(int x, int y, int width, int height)
    : Collidable(x, y, width, height)
{
    m_rs.setPosition(x, y);
    m_rs.setSize(sf::Vector2<float>(width, height));
    m_rs.setFillColor(sf::Color::White);
}

void Border::draw(sf::RenderWindow &window)
{
    window.draw(m_rs);
}
