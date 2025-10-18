#include "inputhandler.h"
#include "screen.h"
#include <iostream>

void InputHandler::initializeInputHandler(ScreenManagerRemoteControl *smrc, vector<shared_ptr<Button> > buttons, View *uiview, Screen *screen)
{
    m_SMRC = smrc;
    m_Buttons = buttons;
    m_UIPanelView = uiview;
    m_parentScreen = screen;
}

void InputHandler::handleInput(RenderWindow &window, Event &event)
{
    if (event.type == Event::KeyPressed)
        handleKeyPressed(window, event);
    if (event.type == Event::KeyReleased)
        handleKeyReleased(window, event);
    if (event.type == Event::MouseButtonReleased) {
        for (auto& it : m_Buttons) {
            const auto pp = window.mapPixelToCoords(Mouse::getPosition(), *getPointerToView());
            if (it->m_Collider.contains(pp)) {
                handleLeftClick(it->m_Text, window);
                break;
            }
        }
    }
}

void InputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{

}

void InputHandler::handleKeyReleased(RenderWindow &window, Event &event)
{

}

void InputHandler::handleLeftClick(const string &buttonInteractedWith, RenderWindow &window)
{

}

View *InputHandler::getPointerToView()
{
    return m_UIPanelView;
}

ScreenManagerRemoteControl *InputHandler::getPointerToSMRC()
{
    return m_SMRC;
}

Screen *InputHandler::getPointerToScreen()
{
    return m_parentScreen;
}
