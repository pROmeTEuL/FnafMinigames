#ifndef SELECTINPUTHANDLER_H
#define SELECTINPUTHANDLER_H

#include "inputhandler.h"

class SelectInputHandler : public InputHandler
{
    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleLeftClick(const string &buttonInteractedWith, RenderWindow &window) override;
};

#endif // SELECTINPUTHANDLER_H
