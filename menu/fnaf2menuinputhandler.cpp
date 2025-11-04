#include "fnaf2menuinputhandler.h"

void Fnaf2MenuInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        getPointerToSMRC()->switchScreen("MainMenu");
    }
}

void Fnaf2MenuInputHandler::handleLeftClick(const string &buttonInteractedWith, RenderWindow &window)
{
    if (buttonInteractedWith == "Take Cake To Children") {
        getPointerToSMRC()->switchScreen("TakeCakeToChildren");
    }
    if (buttonInteractedWith == "Back") {
        getPointerToSMRC()->switchScreen("MainMenu");
    }
}
