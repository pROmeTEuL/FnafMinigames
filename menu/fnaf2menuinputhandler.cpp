#include "fnaf2menuinputhandler.h"

void Fnaf2MenuInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        getPointerToSMRC()->switchScreen("MainMenu");
    }
}

void Fnaf2MenuInputHandler::handleLeftClick(const string &buttonInteractedWith, RenderWindow &window)
{
    if (buttonInteractedWith == "GO! GO! GO!") {
        // Start the game
    }
    if (buttonInteractedWith == "Back") {
        getPointerToSMRC()->switchScreen("MainMenu");
    }
}
