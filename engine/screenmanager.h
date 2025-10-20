#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "ScreenManagerRemoteControl.h"


class ScreenManager : public ScreenManagerRemoteControl
{
    map<string, unique_ptr<Screen>> m_Screens;
protected:
    string m_CurrentScreen = "MainMenu";
public:
    ScreenManager(Vector2i res);
    void update(float fps, Vector2i res);
    void draw(RenderWindow& window);
    void handleInput(RenderWindow& window);

    // ScreenManagerRemoteControl interface
public:
    void switchScreen(string screenToSwitchTo) override;
    void playLevel(string level) override;
};

#endif // SCREENMANAGER_H
