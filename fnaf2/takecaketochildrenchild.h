#ifndef CHILD_H
#define CHILD_H

#include "collidable.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace tctc {
enum class ChildState
{
    CALM = 0,
    UPSET,
    MAD,
    CRYING
};

class Child : public Collidable
{
public:
    Child(int x, int y);
    void update(float delta);
    void draw(sf::RenderWindow &window);
    void calmDown();
    void reset();
    bool crying();

private:
    void agitate();

private:
    const float m_trigger_agitate = 5.f;
    float m_trigger_animation = 1.f;

    sf::Sprite m_sprite1;
    sf::Sprite m_sprite2;
    std::vector<std::string> m_sprite_paths;
    bool m_displayFirstSprite = true;
    float m_agitationTimer = 0.f;
    float m_animationTimer = 0.f;
    ChildState m_state = ChildState::CALM;
};
}

#endif // CHILD_H
