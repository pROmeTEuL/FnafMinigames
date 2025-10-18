#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "uipanel.h"
#include "inputhandler.h"
#include "ScreenManagerRemoteControl.h"

using namespace std;

class Screen
{
    vector<shared_ptr<InputHandler>> m_InputHandlers;
    vector<unique_ptr<UIPanel>> m_Panels;
protected:
    void addPanel(unique_ptr<UIPanel> panel,
                  ScreenManagerRemoteControl* smrc,
                  shared_ptr<InputHandler> ih);
public:
    virtual void initialise();
    virtual void update(float fps, Vector2i res);
    virtual void draw(RenderWindow& window, Shader *shader = nullptr);
    void handleInput(RenderWindow& window);
    View m_view;
};

#endif // SCREEN_H
