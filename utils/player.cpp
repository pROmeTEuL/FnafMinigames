#include "player.h"
#include "texturemanager.h"

Player::Player(sf::Vector2<float> pos, std::unique_ptr<std::vector<std::string>> sprite_paths)
    : m_pos(pos)
{
    m_sprite_paths = std::move(sprite_paths);

    m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths->at(0)));
    m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths->at(1)));

    m_sprite1.setPosition(m_pos);
    m_sprite2.setPosition(m_pos);

    updateCollisionRect();
}

Player::Player(sf::Vector2<float> pos, std::unique_ptr<std::vector<std::string> > sprite_paths, float speed)
    : m_pos(pos)
    , m_speed(speed)
{
    m_sprite_paths = std::move(sprite_paths);

    m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths->at(0)));
    m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths->at(1)));

    m_sprite1.setPosition(m_pos);
    m_sprite2.setPosition(m_pos);

    updateCollisionRect();
}

void Player::input_pressed(sf::Event &event)
{
    if (event.key.code == sf::Keyboard::Up) {
        m_movement |= static_cast<uint8_t>(Movement::UP);
    }
    if (event.key.code == sf::Keyboard::Down) {
        m_movement |= static_cast<uint8_t>(Movement::DOWN);
    }
    if (event.key.code == sf::Keyboard::Right) {
        m_movement |= static_cast<uint8_t>(Movement::RIGHT);
    }
    if (event.key.code == sf::Keyboard::Left) {
        m_movement |= static_cast<uint8_t>(Movement::LEFT);
    }
}

void Player::input_released(sf::Event &event)
{
    if (event.key.code == sf::Keyboard::Up) {
        stopMovement(Movement::UP);
    }
    if (event.key.code == sf::Keyboard::Down) {
        stopMovement(Movement::DOWN);
    }
    if (event.key.code == sf::Keyboard::Right) {
        stopMovement(Movement::RIGHT);
    }
    if (event.key.code == sf::Keyboard::Left) {
        stopMovement(Movement::LEFT);
    }
}

void Player::update(float delta)
{
    m_animationTimer += delta;

    if (movingTowards(Movement::UP)) {
        m_pos.y -= delta * m_speed;
    }
    if (movingTowards(Movement::DOWN)) {
        m_pos.y += delta * m_speed;
    }
    if (movingTowards(Movement::LEFT)) {
        m_pos.x -= delta * m_speed;
        m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths->at(0)));
        m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths->at(1)));
    }
    if (movingTowards(Movement::RIGHT)) {
        m_pos.x += delta * m_speed;
        m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths->at(2)));
        m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths->at(3)));
    }

    if(m_animationTimer >= m_trigger_animation) {
        m_displayFirstSprite = !m_displayFirstSprite;
        m_animationTimer -= m_trigger_animation;
    }

    m_sprite1.setPosition(m_pos);
    m_sprite2.setPosition(m_pos);
    updateCollisionRect();
}

void Player::draw(sf::RenderWindow &window)
{
    if (m_displayFirstSprite)
        window.draw(m_sprite1);
    else
        window.draw(m_sprite2);
}

void Player::stopMovement(Movement direction)
{
    m_movement &= static_cast<uint8_t>(direction) ^ static_cast<uint8_t>(Movement::FULL);
}

void Player::forcedMovement(sf::Vector2<float> pos)
{
    m_pos = pos;
    m_sprite1.setPosition(m_pos);
    m_sprite2.setPosition(m_pos);
    updateCollisionRect();
}

void Player::fullStop()
{
    m_movement = static_cast<uint8_t>(Movement::IDLE);
}

bool Player::movingTowards(Movement movement)
{
    return m_movement & static_cast<uint8_t>(movement);
}

void Player::updateCollisionRect()
{
    if (m_displayFirstSprite)
        setBounds(m_sprite1.getGlobalBounds());
    else
        setBounds(m_sprite2.getGlobalBounds());
}
