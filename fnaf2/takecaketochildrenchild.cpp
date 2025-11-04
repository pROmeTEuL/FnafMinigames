#include "takecaketochildrenchild.h"
#include "texturemanager.h"

namespace{
#define ROOT_PATH "assets/fnaf2/TakeCakeToChildren/"
}

namespace tctc {

#define ANIMATION_CALM_TRIGGER 1.f
#define ANIMATION_UPSET_TRIGGER 0.5f
#define ANIMATION_MAD_TRIGGER 0.25f

Child::Child(int x, int y)
{
    // Calm
    m_sprite_paths.push_back(ROOT_PATH"child_calm_1.png");
    m_sprite_paths.push_back(ROOT_PATH"child_calm_2.png");

    // Upset
    m_sprite_paths.push_back(ROOT_PATH"child_upset_1.png");
    m_sprite_paths.push_back(ROOT_PATH"child_upset_2.png");

    // Mad
    m_sprite_paths.push_back(ROOT_PATH"child_mad_1.png");
    m_sprite_paths.push_back(ROOT_PATH"child_mad_2.png");

    // Crying
    m_sprite_paths.push_back(ROOT_PATH"child_crying.png");

    m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[0]));
    m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[1]));
    m_sprite1.setPosition(x, y);
    m_sprite2.setPosition(x, y);
    setBounds(m_sprite1.getGlobalBounds());
}

void Child::update(float delta)
{
    m_agitationTimer += delta;
    m_animationTimer += delta;
    if (m_agitationTimer >= m_trigger_agitate) {
        m_agitationTimer -= m_trigger_agitate;
        agitate();
    }
    if(m_animationTimer >= m_trigger_animation) {
        m_displayFirstSprite = !m_displayFirstSprite;
        m_animationTimer -= m_trigger_animation;
    }
}

void Child::draw(sf::RenderWindow &window)
{
    window.draw((m_displayFirstSprite ? m_sprite1 : m_sprite2));
}

void Child::calmDown()
{
    if (m_state == ChildState::CRYING)
        return;
    m_state = ChildState::CALM;
    m_trigger_animation = ANIMATION_CALM_TRIGGER;
    m_agitationTimer = 0.f;
    m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[0]));
    m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[1]));
}

void Child::reset()
{
    m_state = ChildState::CALM;
    m_trigger_animation = ANIMATION_CALM_TRIGGER;
    m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[0]));
    m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[1]));
    m_agitationTimer = 0.f;
    m_animationTimer = 0.f;
    m_displayFirstSprite = true;
}

bool Child::crying()
{
    return m_state == ChildState::CRYING;
}

void Child::agitate()
{
    switch(m_state) {
    case ChildState::CALM:
        m_state = ChildState::UPSET;
        m_trigger_animation = ANIMATION_UPSET_TRIGGER;
        m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[2]));
        m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[3]));
        return;
    case ChildState::UPSET:
        m_state = ChildState::MAD;
        m_trigger_animation = ANIMATION_MAD_TRIGGER;
        m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[4]));
        m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[5]));
        return;
    case ChildState::MAD:
        m_state = ChildState::CRYING;
        m_trigger_animation = ANIMATION_CALM_TRIGGER;
        m_sprite1.setTexture(TextureManager::instance().texture(m_sprite_paths[6]));
        m_sprite2.setTexture(TextureManager::instance().texture(m_sprite_paths[6]));
        return;
    default:
        return;
    }
}
}
