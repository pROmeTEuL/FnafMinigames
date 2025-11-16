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
    TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player, State &state, std::shared_ptr<std::vector<tctc::Child>> children);

    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleKeyReleased(RenderWindow &window, Event &event) override;

private:
    std::shared_ptr<Player> m_player;
    std::shared_ptr<std::vector<tctc::Child>> m_children;
    State *m_state;
};

#endif // TAKECAKETOCHILDRENINPUTHANDLER_H
