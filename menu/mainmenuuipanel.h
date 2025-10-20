#ifndef MAINMENUUIPANEL_H
#define MAINMENUUIPANEL_H

#include "uipanel.h"

class MainMenuUIPanel : public UIPanel
{
    void initializeButtons();
public:
    MainMenuUIPanel(Vector2i res);
    void draw(RenderWindow& window, Shader* shader) override;
};

#endif // MAINMENUUIPANEL_H
