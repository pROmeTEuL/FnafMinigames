#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "screen.h"

class MainMenuScreen : public Screen
{
    ScreenManagerRemoteControl* m_SMRC;
public:
    MainMenuScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
    void draw(RenderWindow& window, Shader* shader = nullptr) override;
    void update(float fps, Vector2i res) override;
};

#endif // MAINMENUSCREEN_H
