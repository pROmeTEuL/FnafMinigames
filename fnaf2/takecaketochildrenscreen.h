#ifndef TAKECAKETOCHILDRENSCREEN_H
#define TAKECAKETOCHILDRENSCREEN_H

#include <screen.h>
#include <player.h>
#include <border.h>

#include "takecaketochildrenchild.h"

using namespace tctc;

class TakeCakeToChildrenScreen : public Screen
{
public:
    TakeCakeToChildrenScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

    // Screen interface
public:
    void update(float delta, Vector2i res) override;
    void draw(RenderWindow &window, Shader *shader) override;

private:
    ScreenManagerRemoteControl* m_SMRC;
    std::shared_ptr<Player> m_player;
    std::vector<Child> m_children;
    std::vector<Border> m_borders;
};

#endif // TAKECAKETOCHILDRENSCREEN_H
