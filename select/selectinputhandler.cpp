#include "selectinputhandler.h"
#include <fstream>

void SelectInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
}

void SelectInputHandler::handleLeftClick(const string &buttonInteractedWith, RenderWindow &window)
{
    if (buttonInteractedWith == "Play") {
        string level;
        ifstream f("progress.lvl");
        f >> level;
        getPointerToSMRC()->playLevel(level);
    }
    if (buttonInteractedWith == "Quit") {
        window.close();
    }
}
