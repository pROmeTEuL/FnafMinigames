#ifndef FNAF2MENUINPUTHANDLER_H
#define FNAF2MENUINPUTHANDLER_H

#include "inputhandler.h"

class Fnaf2MenuInputHandler : public InputHandler
{
    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleLeftClick(const string &buttonInteractedWith, RenderWindow &window) override;
};

#endif // FNAF2MENUINPUTHANDLER_H
