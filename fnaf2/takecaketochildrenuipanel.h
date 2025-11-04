#ifndef TAKECAKETOCHILDRENUIPANEL_H
#define TAKECAKETOCHILDRENUIPANEL_H

#include <uipanel.h>

class TakeCakeToChildrenUIPanel : public UIPanel
{
public:
    TakeCakeToChildrenUIPanel(Vector2i res);

    // UIPanel interface
public:
    void draw(RenderWindow &window, Shader *shader) override;
};

#endif // TAKECAKETOCHILDRENUIPANEL_H
