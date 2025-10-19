#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ScreenManagerRemoteControl.h"
#include "button.h"

using namespace sf;
using namespace std;

class Screen;

class InputHandler
{
    Screen* m_parentScreen;
    vector<shared_ptr<Button>> m_Buttons;
    View* m_UIPanelView;
    ScreenManagerRemoteControl* m_SMRC;
public:
    void initializeInputHandler(ScreenManagerRemoteControl* smrc,
                                vector<shared_ptr<Button>> buttons,
                                View* uiview,
                                Screen* screen);
    void handleInput(RenderWindow& window, Event& event);
    virtual void handleKeyPressed(RenderWindow& window, Event& event);
    virtual void handleKeyReleased(RenderWindow& window, Event& event);
    virtual void handleLeftClick(const string& buttonInteractedWith, RenderWindow& window);
    View* getPointerToView();
    ScreenManagerRemoteControl* getPointerToSMRC();
    Screen* getPointerToScreen();
};

#endif // INPUTHANDLER_H
