#include "fnaf2menuscreen.h"
#include "shadermanager.h"
#include "fnaf2menuinputhandler.h"
#include "fnaf2menuuipanel.h"

Fnaf2MenuScreen::Fnaf2MenuScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    m_SMRC = smrc;
    auto f2muip = make_unique<Fnaf2MenuUIPanel>(res);
    auto f2mih = make_shared<Fnaf2MenuInputHandler>();
    addPanel(move(f2muip), smrc, f2mih);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("speed", 1.f);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("resolution", Glsl::Vec2(res.x, res.y));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("graininess", Glsl::Vec2(1, 80));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("intense", 1.f);
    ShaderManager::instance().getFragment("data/shaders/edge")->setUniform("texOffset", 50);
}

void Fnaf2MenuScreen::update(float fps, Vector2i res)
{
    ShaderManager::instance().getFragment("data/shaders/static")->setUniform("u_time", fps);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("time", fps);
}

void Fnaf2MenuScreen::draw(RenderWindow &window, Shader *shader)
{
    window.setView(m_view);
    Screen::draw(window, ShaderManager::instance().getFragment("data/shaders/bug"));
}
