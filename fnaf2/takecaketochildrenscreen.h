#ifndef TAKECAKETOCHILDRENSCREEN_H
#define TAKECAKETOCHILDRENSCREEN_H

#include <player.h>
#include <screen.h>

class TakeCakeToChildrenScreen : public Screen
{
public:
    TakeCakeToChildrenScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

    // Screen interface
public:
    void update(float fps, Vector2i res) override;
    void draw(RenderWindow &window, Shader *shader) override;

private:
    ScreenManagerRemoteControl* m_SMRC;
    std::unique_ptr<Player> m_player;
};

#endif // TAKECAKETOCHILDRENSCREEN_H
