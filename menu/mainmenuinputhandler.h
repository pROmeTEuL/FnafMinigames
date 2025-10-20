#ifndef MAINMENUINPUTHANDLER_H
#define MAINMENUINPUTHANDLER_H

#include "inputhandler.h"

class MainMenuInputHandler : public InputHandler
{
    // InputHandler interface
public:
    void handleKeyPressed(RenderWindow &window, Event &event) override;
    void handleLeftClick(const string &buttonInteractedWith, RenderWindow &window) override;
};

#endif // MAINMENUINPUTHANDLER_H
