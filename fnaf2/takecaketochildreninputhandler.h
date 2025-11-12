#ifndef TAKECAKETOCHILDRENINPUTHANDLER_H
#define TAKECAKETOCHILDRENINPUTHANDLER_H

#include <inputhandler.h>
#include <player.h>

class TakeCakeToChildrenInputHandler : public InputHandler
{
public:
    TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player, bool &paused);

    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleKeyReleased(RenderWindow &window, Event &event) override;

private:
    std::shared_ptr<Player> m_player;
    bool *m_paused;
};

#endif // TAKECAKETOCHILDRENINPUTHANDLER_H
