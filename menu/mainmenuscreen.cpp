#include "mainmenuscreen.h"
#include "mainmenuuipanel.h"
#include "mainmenuinputhandler.h"
#include "shadermanager.h"

MainMenuScreen::MainMenuScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    m_SMRC = smrc;
    auto mmuip = make_unique<MainMenuUIPanel>(res);
    auto mmih = make_shared<MainMenuInputHandler>();
    addPanel(move(mmuip), smrc, mmih);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("speed", 1.f);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("resolution", Glsl::Vec2(res.x, res.y));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("graininess", Glsl::Vec2(1, 80));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("intense", 1.f);
    ShaderManager::instance().getFragment("data/shaders/edge")->setUniform("texOffset", 50);
}

void MainMenuScreen::draw(RenderWindow &window, Shader* shader)
{
    window.setView(m_view);
    Screen::draw(window, ShaderManager::instance().getFragment("data/shaders/bug"));
}

void MainMenuScreen::update(float fps, Vector2i res)
{
    ShaderManager::instance().getFragment("data/shaders/static")->setUniform("u_time", fps);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("time", fps);
}
