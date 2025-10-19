#include "screenmanager.h"

ScreenManager::ScreenManager(Vector2i res)
{
//    m_Screens["Game"] = make_unique<GameScreen>(this, res);
    m_Screens["Select"] = make_unique<SelectScreen>(this, res);
}

void ScreenManager::update(float fps, Vector2i res)
{
    m_Screens[m_CurrentScreen]->update(fps, res);
}

void ScreenManager::draw(RenderWindow &window)
{
    m_Screens[m_CurrentScreen]->draw(window);
}

void ScreenManager::handleInput(RenderWindow &window)
{
    m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::switchScreen(string screenToSwitchTo)
{
    m_CurrentScreen = screenToSwitchTo;
    m_Screens[m_CurrentScreen]->initialise();
}

void ScreenManager::playLevel(string level)
{
    switchScreen("Game");
}
