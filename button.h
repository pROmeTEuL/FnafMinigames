#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
public:
    Button(Vector2f position, float width, float height,
           unsigned int red, unsigned int green, unsigned blue,
           std::string text, std::string font, bool rectangle);
    void draw(RenderWindow &window, Shader* shader);
public:
    FloatRect m_Collider;
    std::string m_Text;
private:
    RectangleShape m_Button;
    Text m_ButtonText;
    Font m_Font;
};

#endif // BUTTON_H
