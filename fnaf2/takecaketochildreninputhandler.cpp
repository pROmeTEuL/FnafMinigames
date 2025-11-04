#include "takecaketochildreninputhandler.h"

TakeCakeToChildrenInputHandler::TakeCakeToChildrenInputHandler() {}

void TakeCakeToChildrenInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        getPointerToSMRC()->switchScreen("Fnaf2Menu");
    }
    // HANDLE PLAYER INPUT
}

void TakeCakeToChildrenInputHandler::handleKeyReleased(RenderWindow &window, Event &event)
{
    // HANDLE PLAYER INPUT
}
