#include "selectscreen.h"
#include "shadermanager.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    m_SMRC = smrc;
    auto suip = make_unique<SelectUIPanel>(res);
    auto sih = make_shared<SelectInputHandler>();
    addPanel(move(suip), smrc, sih);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("speed", 1.f);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("resolution", Glsl::Vec2(res.x, res.y));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("graininess", Glsl::Vec2(1, 80));
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("intense", 1.f);
    ShaderManager::instance().getFragment("data/shaders/edge")->setUniform("texOffset", 50);
}

void SelectScreen::draw(RenderWindow &window, Shader* shader)
{
    window.setView(m_view);
    Screen::draw(window, ShaderManager::instance().getFragment("data/shaders/bug"));
}

void SelectScreen::update(float fps, Vector2i res)
{
    ShaderManager::instance().getFragment("data/shaders/static")->setUniform("u_time", fps);
    ShaderManager::instance().getFragment("data/shaders/bug")->setUniform("time", fps);
}
