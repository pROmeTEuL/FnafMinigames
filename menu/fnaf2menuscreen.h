#ifndef FNAF2MENUSCREEN_H
#define FNAF2MENUSCREEN_H

#include "screen.h"

class Fnaf2MenuScreen : public Screen
{
public:
    Fnaf2MenuScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

    // Screen interface
public:
    void update(float fps, Vector2i res) override;
    void draw(RenderWindow &window, Shader *shader) override;

private:
    ScreenManagerRemoteControl* m_SMRC;
};

#endif // FNAF2MENUSCREEN_H
