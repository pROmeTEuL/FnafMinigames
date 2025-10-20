#include "fnaf2menuuipanel.h"
#include "shadermanager.h"

Fnaf2MenuUIPanel::Fnaf2MenuUIPanel(Vector2i res)
    : UIPanel(res,
            (res.x / 18), // Start 2/10 accross
            (res.y / 10), // 1/3 of the resolution from the top
            (res.x / 18) * 16, // as wide as 6/10 of the resolution
            (res.y / 10) * 8, // and as tall as 1/3 of the resolution
            100, 0, 0, 255) // a, r, g, b
{
    m_ButtonWidth = res.x / 19;
    m_ButtonHeight = res.y / 12;
    m_ButtonPadding = res.y / 10;
    m_HalfScreen.x = (res.x / 18) * 9;
    m_HalfScreen.y = (res.y / 10) * 5;

    m_Text.setFillColor(sf::Color(255, 255, 255, 255));
    m_Text.setString("Fnaf 2 Minigames");

    m_Font.loadFromFile("data/fonts/MoltenPaint.ttf");
    m_Text.setFont(m_Font);

    m_Text.setPosition(Vector2f(m_HalfScreen.x - 80 * 5, res.y / 10 + 10));

    m_Text.setCharacterSize(100);

    initializeButtons();
}

void Fnaf2MenuUIPanel::draw(RenderWindow &window, Shader *shader)
{
    show();
    UIPanel::draw(window, ShaderManager::instance().getFragment("data/shaders/static"));
    if (shader == nullptr)
        window.draw(m_Text);
    else
        window.draw(m_Text, shader);
}

void Fnaf2MenuUIPanel::initializeButtons()
{
    addButton(m_ButtonPadding,
              m_HalfScreen.y - m_ButtonHeight - m_ButtonPadding * 2,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 255, 255, "GO! GO! GO!", "data/fonts/Molten.ttf", false);
    addButton(m_ButtonPadding,
              m_HalfScreen.y - m_ButtonHeight - m_ButtonPadding,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 255, 255, "Feed The Kids", "data/fonts/Molten.ttf", false);
    addButton(m_ButtonPadding,
              m_HalfScreen.y - m_ButtonHeight,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 255, 255, "IDK", "data/fonts/Molten.ttf", false);
    addButton(m_ButtonPadding,
              m_HalfScreen.y - m_ButtonHeight + m_ButtonPadding,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 255, 255, "IDK2", "data/fonts/Molten.ttf", false);
    addButton(m_ButtonPadding,
              m_HalfScreen.y - m_ButtonHeight + m_ButtonPadding * 2,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 255, 255, "Back", "data/fonts/Molten.ttf", false);
}
