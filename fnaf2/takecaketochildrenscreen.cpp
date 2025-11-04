#include "takecaketochildrenscreen.h"
#include "takecaketochildrenuipanel.h"
#include "takecaketochildreninputhandler.h"

TakeCakeToChildrenScreen::TakeCakeToChildrenScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    m_SMRC = smrc;
    auto tctcui = make_unique<TakeCakeToChildrenUIPanel>(res);
    auto tctcih = make_shared<TakeCakeToChildrenInputHandler>();
    addPanel(std::move(tctcui), smrc, tctcih);
    std::vector<std::string> sprite_paths;
    m_player = make_unique<Player>(sf::Vector2<float>(100, 100), make_unique<std::vector<std::string>>(sprite_paths));
}

void TakeCakeToChildrenScreen::update(float fps, Vector2i res)
{

}

void TakeCakeToChildrenScreen::draw(RenderWindow &window, Shader *shader)
{

}
