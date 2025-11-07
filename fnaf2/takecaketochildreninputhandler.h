#ifndef TAKECAKETOCHILDRENINPUTHANDLER_H
#define TAKECAKETOCHILDRENINPUTHANDLER_H

#include <inputhandler.h>
#include <player.h>

class TakeCakeToChildrenInputHandler : public InputHandler
{
public:
    TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player);

    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleKeyReleased(RenderWindow &window, Event &event) override;

private:
    std::shared_ptr<Player> m_player;
};

#endif // TAKECAKETOCHILDRENINPUTHANDLER_H
