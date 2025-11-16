#include "takecaketochildrenscreen.h"
#include "takecaketochildrenuipanel.h"
#include "takecaketochildreninputhandler.h"

namespace {
#define PATH_ROOT "assets/fnaf2/TakeCakeToChildren/"
}

TakeCakeToChildrenScreen::TakeCakeToChildrenScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    std::vector<std::string> sprite_paths;
    sprite_paths.push_back(PATH_ROOT"feddy_left_1.png");
    sprite_paths.push_back(PATH_ROOT"feddy_left_2.png");
    sprite_paths.push_back(PATH_ROOT"feddy_right_1.png");
    sprite_paths.push_back(PATH_ROOT"feddy_right_2.png");
    m_player = make_shared<Player>(sf::Vector2<float>(res.x / 2, res.y / 2), make_unique<std::vector<std::string>>(sprite_paths), res.x / 6.4);

    m_SMRC = smrc;
    auto tctcui = make_unique<TakeCakeToChildrenUIPanel>(res);
    auto tctcih = make_shared<TakeCakeToChildrenInputHandler>(m_player, m_state, make_shared<std::vector<Child>>(m_children));
    addPanel(std::move(tctcui), smrc, tctcih);

    m_borders.push_back(Border(res.x - 100, 50, 50, res.y - 100));
    m_borders.push_back(Border(50, 50, res.x - 100, 50));
    m_borders.push_back(Border(50, 50, 50, res.y - 100));
    m_borders.push_back(Border(50, res.y - 100, res.x - 100, 50));

    m_children.push_back(Child(res.x / 10 * 1, res.y / 4));
    m_children.push_back(Child(res.x / 10 * 1, (res.y / 4) * 2));
    m_children.push_back(Child(res.x / 10 * 1, (res.y / 4) * 3));

    m_children.push_back(Child(res.x / 10 * 8, res.y / 4));
    m_children.push_back(Child(res.x / 10 * 8, (res.y / 4) * 2));
    m_children.push_back(Child(res.x / 10 * 8, (res.y / 4) * 3));
}

void TakeCakeToChildrenScreen::update(float delta, Vector2i res)
{
    if (m_state != State::PLAYING)
        return;
    uint8_t cnt = 0;
    for (auto &child : m_children)
        if (child.crying())
            ++cnt;
    if (cnt == 6) {
        m_state = State::OVER;
        return;
    }
    m_player->update(delta);
    for (auto &child : m_children) {
        child.update(delta);
        if (m_player->collidesWith<Side>(std::make_shared<Collidable>(child)) != Side::NONE)
            child.calmDown();
    }
    if (m_player->collidesWith<uint8_t>(std::make_shared<Collidable>(m_borders[0])) & static_cast<uint8_t>(Side::RIGHT))
        m_player->stopMovement(Movement::RIGHT);
    if (m_player->collidesWith<uint8_t>(std::make_shared<Collidable>(m_borders[1])) & static_cast<uint8_t>(Side::TOP))
        m_player->stopMovement(Movement::UP);
    if (m_player->collidesWith<uint8_t>(std::make_shared<Collidable>(m_borders[2])) & static_cast<uint8_t>(Side::LEFT))
        m_player->stopMovement(Movement::LEFT);
    if (m_player->collidesWith<uint8_t>(std::make_shared<Collidable>(m_borders[3])) & static_cast<uint8_t>(Side::BOTTOM))
        m_player->stopMovement(Movement::DOWN);
}

void TakeCakeToChildrenScreen::draw(RenderWindow &window, Shader *shader)
{
    window.setView(m_view);
    Screen::draw(window, nullptr);
    for (auto border : m_borders)
        border.draw(window);
    for(auto child : m_children)
        child.draw(window);
    switch(m_state) {
    case State::PAUSED:
        // Paused text
        break;
    case State::OVER:
        // Over text
        break;
    default:
        break;
    }
    m_player->draw(window);
}
