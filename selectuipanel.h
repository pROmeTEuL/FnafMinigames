#ifndef SELECTUIPANEL_H
#define SELECTUIPANEL_H

#include "uipanel.h"

class SelectUIPanel : public UIPanel
{
    void initializeButtons();
public:
    SelectUIPanel(Vector2i res);
    void draw(RenderWindow& window, Shader* shader) override;
};

#endif // SELECTUIPANEL_H
