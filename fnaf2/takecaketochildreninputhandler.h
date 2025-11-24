#ifndef TAKECAKETOCHILDRENINPUTHANDLER_H
#define TAKECAKETOCHILDRENINPUTHANDLER_H

#include <inputhandler.h>
#include <player.h>
#include <memory>
#include <vector>

#include "takecaketochildrenchild.h"

enum class State {
    PLAYING,
    PAUSED,
    OVER
};

class TakeCakeToChildrenInputHandler : public InputHandler
{
public:
    TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player, State &state, bool &reset);

    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleKeyReleased(RenderWindow &window, Event &event) override;

private:
    std::shared_ptr<Player> m_player;
    State *m_state;
    bool *m_reset;
};

#endif // TAKECAKETOCHILDRENINPUTHANDLER_H
