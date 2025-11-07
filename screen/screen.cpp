#include "screen.h"

void Screen::addPanel(unique_ptr<UIPanel> panel, ScreenManagerRemoteControl *smrc, shared_ptr<InputHandler> ih)
{
    ih->initializeInputHandler(smrc, panel->getButtons(), &panel->m_View, this);
    m_Panels.push_back(std::move(panel));
    m_InputHandlers.push_back(ih);
}

void Screen::initialise()
{

}

void Screen::update(float fps, Vector2i res)
{

}

void Screen::draw(RenderWindow &window, Shader* shader)
{
    for (auto& it : m_Panels) {
        it->draw(window, shader);
    }
}

void Screen::handleInput(RenderWindow &window)
{
    Event event;
    while (window.pollEvent(event)) {
        for (auto& it : m_InputHandlers) {
            it->handleInput(window, event);
        }
    }
}
