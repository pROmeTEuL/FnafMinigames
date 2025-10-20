#include "mainmenuinputhandler.h"

void MainMenuInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
}

void MainMenuInputHandler::handleLeftClick(const string &buttonInteractedWith, RenderWindow &window)
{
    if (buttonInteractedWith == "Fnaf 2") {
        getPointerToSMRC()->switchScreen("Fnaf2Menu");
    }
    if (buttonInteractedWith == "Fnaf 3") {
        getPointerToSMRC()->switchScreen("Fnaf3Menu");
    }
    if (buttonInteractedWith == "Fnaf 4") {
        getPointerToSMRC()->switchScreen("Fnaf4Menu");
    }
    if (buttonInteractedWith == "Fnaf SL") {
        getPointerToSMRC()->switchScreen("FnafSLMenu");
    }
    if (buttonInteractedWith == "Quit") {
        window.close();
    }
}
