#include "screenmanager.h"

#include <mainmenuscreen.h>
#include <fnaf2menuscreen.h>
#include <takecaketochildrenscreen.h>

ScreenManager::ScreenManager(Vector2i res)
{
    m_Screens["MainMenu"] = make_unique<MainMenuScreen>(this, res);
    m_Screens["Fnaf2Menu"] = make_unique<Fnaf2MenuScreen>(this, res);
    m_Screens["TakeCakeToChildren"] = make_unique<TakeCakeToChildrenScreen>(this, res);
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
    switchScreen(level);
}
