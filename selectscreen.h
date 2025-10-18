#ifndef SELECTSCREEN_H
#define SELECTSCREEN_H

#include "screen.h"
#include "selectuipanel.h"
#include "selectinputhandler.h"

class SelectScreen : public Screen
{
    ScreenManagerRemoteControl* m_SMRC;
public:
    SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
    void draw(RenderWindow& window, Shader* shader = nullptr) override;
    void update(float fps, Vector2i res) override;
};

#endif // SELECTSCREEN_H
