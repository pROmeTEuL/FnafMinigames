#ifndef FNAF2MENUUIPANEL_H
#define FNAF2MENUUIPANEL_H

#include <uipanel.h>

class Fnaf2MenuUIPanel : public UIPanel
{
public:
    Fnaf2MenuUIPanel(Vector2i res);

    // UIPanel interface
public:
    void draw(RenderWindow &window, Shader *shader) override;
private:
    void initializeButtons();
};

#endif // FNAF2MENUUIPANEL_H
