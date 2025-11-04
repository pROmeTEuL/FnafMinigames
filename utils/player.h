#ifndef PLAYER_H
#define PLAYER_H

#include "collidable.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include <memory>

enum class Movement {
    IDLE = 0b00000000,
    LEFT = 0b00001000,
    RIGHT = 0b00000001,
    UP = 0b00000100,
    DOWN = 0b00000010,
    FULL = 0b11111111 /// DO NOT USE
};

class Player : public Collidable
{
public:
    Player(sf::Vector2<float> pos, std::unique_ptr<std::vector<std::string> > sprite_paths);
    virtual void input_pressed(sf::Event &event);
    virtual void input_released(sf::Event &event);
    virtual void update(float delta);
    virtual void draw(sf::RenderWindow &window);
    void stopMovement(Movement direction);
    void forcedMovement(sf::Vector2<float> pos);
    void fullStop();

protected:
    bool movingTowards(Movement movement);
    void updateCollisionRect();

protected:
    float m_speed = 100.f;
    float m_trigger_animation = 0.50f;
    float m_animationTimer = 0.f;

private:
    sf::Sprite m_sprite1;
    sf::Sprite m_sprite2;
    sf::Vector2<float> m_pos;
    uint8_t m_movement = 0;
    std::unique_ptr<std::vector<std::string>> m_sprite_paths;
    bool  m_displayFirstSprite = true;
};

#endif // PLAYER_H
