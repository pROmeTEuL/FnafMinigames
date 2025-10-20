#include "button.h"

Button::Button(Vector2f position, float width, float height, unsigned int red, unsigned int green, unsigned int blue, std::string text, std::string font, bool rectangle)
{
    m_Font.loadFromFile(font);
    m_Text = text;
    m_ButtonText.setFont(m_Font);
    m_ButtonText.setString(text);
    if (!rectangle) {
        m_ButtonText.setFillColor(Color(red, green, blue));
        m_Button.setFillColor(Color(0, 0, 0, 0));
    } else {
        m_ButtonText.setFillColor(Color::White);
        m_Button.setFillColor(Color(red, green, blue));
    }
    m_ButtonText.setFillColor(Color::Black);
    m_Button.setPosition(position);
    m_ButtonText.setPosition(Vector2f(position.x + 10, position.y + 10));
    m_ButtonText.setCharacterSize(width - 20);
    m_Collider = m_ButtonText.getGlobalBounds();
    m_Button.setSize(Vector2f(m_Collider.getSize().x, height));
}

void Button::draw(RenderWindow &window, Shader* shader)
{
    if (shader == nullptr) {
        window.draw(m_Button);
        window.draw(m_ButtonText);
    } else {
        window.draw(m_Button);
        window.draw(m_ButtonText, shader);
    }
}
