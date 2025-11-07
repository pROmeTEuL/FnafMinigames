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
    m_player = make_shared<Player>(sf::Vector2<float>(100, 100), make_unique<std::vector<std::string>>(sprite_paths));

    m_SMRC = smrc;
    auto tctcui = make_unique<TakeCakeToChildrenUIPanel>(res);
    auto tctcih = make_shared<TakeCakeToChildrenInputHandler>(m_player);
    addPanel(std::move(tctcui), smrc, tctcih);

    m_borders.push_back(Border(res.x - 100, 50, 50, res.y - 100));
    m_borders.push_back(Border(50, 50, res.x - 100, 50));
    m_borders.push_back(Border(50, 50, 50, res.y - 100));
    m_borders.push_back(Border(50, res.y - 100, res.x - 100, 50));

    m_children.push_back(Child(50, res.y / 4));
    m_children.push_back(Child(50, (res.y / 4) * 2));
    m_children.push_back(Child(50, (res.y / 4) * 3));

    m_children.push_back(Child(res.x - 160, res.y / 4));
    m_children.push_back(Child(res.x - 160, (res.y / 4) * 2));
    m_children.push_back(Child(res.x - 160, (res.y / 4) * 3));
}

void TakeCakeToChildrenScreen::update(float delta, Vector2i res)
{
    m_player->update(delta);
    for (auto &child : m_children)
        child.update(delta);
}

void TakeCakeToChildrenScreen::draw(RenderWindow &window, Shader *shader)
{
    window.setView(m_view);
    Screen::draw(window, nullptr);
    for (auto border : m_borders)
        border.draw(window);
    for(auto child : m_children)
        child.draw(window);
    m_player->draw(window);
}
