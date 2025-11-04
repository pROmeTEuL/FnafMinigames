#ifndef TAKECAKETOCHILDRENINPUTHANDLER_H
#define TAKECAKETOCHILDRENINPUTHANDLER_H

#include <inputhandler.h>

class TakeCakeToChildrenInputHandler : public InputHandler
{
public:
    TakeCakeToChildrenInputHandler();

    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleKeyReleased(RenderWindow &window, Event &event) override;
};

#endif // TAKECAKETOCHILDRENINPUTHANDLER_H
