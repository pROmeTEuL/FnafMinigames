#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SFML/Graphics/Rect.hpp>
#include <memory>

enum class Side {
    NONE = 0b00000000,
    LEFT = 0b00001000,
    RIGHT = 0b00000001,
    TOP = 0b00000100,
    BOTTOM = 0b00000010
};

class Collidable
{
public:
    Collidable() = default;
    Collidable(sf::Rect<float> rect);
    Collidable(int x, int y, int width, int height);
    template<typename T>
    T collidesWith(const std::shared_ptr<Collidable> &col);
    const sf::Rect<float> &self() const;
    const sf::Rect<float> &left() const;
    const sf::Rect<float> &right() const;
    const sf::Rect<float> &top() const;
    const sf::Rect<float> &bottom() const;


protected:
    void setBounds(sf::Rect<float> rect);
    void setBounds(float x, float y, float width, float height);

private:
    void setExtremes();
    bool collidesLeft(std::shared_ptr<Collidable> col);
    bool collidesRight(std::shared_ptr<Collidable> col);
    bool collidesTop(std::shared_ptr<Collidable> col);
    bool collidesBottom(std::shared_ptr<Collidable> col);
    bool isBetween(float me, float val1, float val2); /// use val1 and val2 as x/y (for left-right, and top-bottom)

private:
    sf::Rect<float> m_self;
    sf::Rect<float> m_left;
    sf::Rect<float> m_right;
    sf::Rect<float> m_top;
    sf::Rect<float> m_bottom;
};

#endif // COLLIDABLE_H
