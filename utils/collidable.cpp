#include "collidable.h"

Collidable::Collidable(sf::Rect<float> rect)
{
    setBounds(rect);
}

Collidable::Collidable(int x, int y, int width, int height)
{
    setBounds(x, y, width, height);
}

const sf::Rect<float> &Collidable::self() const
{
    return m_self;
}

const sf::Rect<float> &Collidable::left() const
{
    return m_left;
}

const sf::Rect<float> &Collidable::right() const
{
    return m_right;
}

const sf::Rect<float> &Collidable::top() const
{
    return m_top;
}

const sf::Rect<float> &Collidable::bottom() const
{
    return m_bottom;
}

void Collidable::setBounds(sf::Rect<float> rect)
{
    m_self = rect;
    setExtremes();
}

void Collidable::setBounds(float x, float y, float width, float height)
{
    m_self.left = x;
    m_self.top = y;
    m_self.width = width;
    m_self.height = height;
    setExtremes();
}

void Collidable::setExtremes()
{
    m_left.left = m_self.left;
    m_left.width = 1.f;
    m_left.top = m_self.top;
    m_left.height = m_self.height;

    m_right.left = m_self.left + m_self.width - 1;
    m_right.width = 1;
    m_right.top = m_self.top;
    m_right.height = m_self.height;

    m_top.left = m_self.top;
    m_top.width = m_self.width;
    m_top.top = m_self.top;
    m_top.height = 1;

    m_bottom.left = m_self.top;
    m_bottom.width = m_self.width;
    m_bottom.top = m_self.top + m_self.height - 1;
    m_bottom.height = 1;
}

bool Collidable::collidesLeft(std::shared_ptr<Collidable> col)
{
    if (isBetween(m_left.left, col->left().left, col->right().left))
        if (isBetween(m_top.top, col->top().top, col->bottom().top) || isBetween(m_bottom.top + 1, col->top().top, col->bottom().top))
            return true;
    return false;
}

bool Collidable::collidesRight(std::shared_ptr<Collidable> col)
{
    if (isBetween(m_right.left + 1, col->left().left, col->right().left))
        if (isBetween(m_top.top, col->top().top, col->bottom().top) || isBetween(m_bottom.top + 1, col->top().top, col->bottom().top))
            return true;
    return false;
}

bool Collidable::collidesTop(std::shared_ptr<Collidable> col)
{
    if (isBetween(m_top.top, col->top().top, col->bottom().top))
        if (isBetween(m_left.left, col->left().left, col->right().left) || isBetween(m_right.left + 1, col->left().left, col->right().left))
            return true;
    return false;
}

bool Collidable::collidesBottom(std::shared_ptr<Collidable> col)
{
    if (isBetween(m_bottom.top + 1, col->top().top, col->bottom().top))
        if (isBetween(m_left.left, col->left().left, col->right().left) || isBetween(m_right.left + 1, col->left().left, col->right().left))
            return true;
    return false;
}

bool Collidable::isBetween(float me, float val1, float val2)
{
    if (me >= val1 && me <= val2 + 1)
        return true;
    return false;
}

template<typename T>
T Collidable::collidesWith(const std::shared_ptr<Collidable> &col)
{
    T ret = static_cast<T>(Side::NONE);
    if (collidesLeft(col))
        ret |= static_cast<T>(Side::LEFT);
    if (collidesTop(col))
        ret |= static_cast<T>(Side::TOP);
    if (collidesRight(col))
        ret |= static_cast<T>(Side::RIGHT);
    if (collidesBottom(col))
        ret |= static_cast<T>(Side::BOTTOM);
    return ret;
}

template<>
uint8_t Collidable::collidesWith(const std::shared_ptr<Collidable> &col)
{
    uint8_t ret = 0b00000000;
    if (collidesLeft(col))
        ret |= static_cast<uint8_t>(Side::LEFT);
    if (collidesTop(col))
        ret |= static_cast<uint8_t>(Side::TOP);
    if (collidesRight(col))
        ret |= static_cast<uint8_t>(Side::RIGHT);
    if (collidesBottom(col))
        ret |= static_cast<uint8_t>(Side::BOTTOM);
    return ret;
}

template<>
Side Collidable::collidesWith(const std::shared_ptr<Collidable> &col)
{
    int8_t ret = 0b00000000;
    if (collidesLeft(col))
        ret |= static_cast<uint8_t>(Side::LEFT);
    if (collidesTop(col))
        ret |= static_cast<uint8_t>(Side::TOP);
    if (collidesRight(col))
        ret |= static_cast<uint8_t>(Side::RIGHT);
    if (collidesBottom(col))
        ret |= static_cast<uint8_t>(Side::BOTTOM);
    return static_cast<Side>(ret);
}
