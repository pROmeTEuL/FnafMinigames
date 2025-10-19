#ifndef UIPANEL_H
#define UIPANEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "button.h"

using namespace sf;
using namespace std;

class UIPanel
{
    RectangleShape m_panel;
    bool m_hidden = false;
    vector<shared_ptr<Button>> m_Buttons;
protected:
    struct HalfScreen {
        float x;
        float y;
    } m_HalfScreen = {0.f, 0.f};
    float m_ButtonWidth = 0;
    float m_ButtonHeight = 0;
    float m_ButtonPadding = 0;
    Font m_Font;
    Text m_Text;
    void addButton(float x, float y,
                   float width, float height,
                   unsigned int red, unsigned int green, unsigned int blue,
                   string text, string font, bool rectangle);
public:
    View m_View;
    UIPanel(Vector2i res, int x, int y,
            float width, float height,
            int alpha, int red, int green, int blue);
    vector<shared_ptr<Button>> getButtons();
    virtual void draw(RenderWindow &window, Shader* shader);
    void show();
    void hide();
    //void addButton(float x, float y, unsigned int width, unsigned int height, unsigned int red, unsigned int green, unsigned int blue, string text, bool rectangle);
};

#endif // UIPANEL_H
