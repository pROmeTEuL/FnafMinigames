#include "uipanel.h"
#include "shadermanager.h"

void UIPanel::addButton(float x, float y, float width, float height, unsigned int red, unsigned int green, unsigned int blue, string text, string font, bool rectangle)
{
    m_Buttons.push_back(make_shared<Button>(Vector2f(x, y),
                                    width, height,
                                    red, green, blue, text, font, rectangle));
}

UIPanel::UIPanel(Vector2i res, int x, int y,
                 float width, float height,
                 int alpha, int red, int green, int blue)
{
    m_panel.setFillColor(sf::Color(red, green, blue, alpha));

    // How big in pixels is the UI panel
    m_panel.setSize(Vector2f(width, height));

    // How big in pixels is the view
    m_View.setSize(Vector2f(width, height));

    m_View.setCenter(width / 2, height / 2);

    // Where in the window is the view positioned?
    float viewportStartX;
    float viewportStartY;
    if (x != 0)
        viewportStartX = 1.f / (res.x / x);
    else
        viewportStartX = 0.f;
    if (y != 0)
        viewportStartY = 1.f / (res.y / y);
    else
        viewportStartY = 0.f;
    float viewportSizeX = 1.f / (res.x / width);
    float viewportSizeY = 1.f / (res.y / height);

    // Params from left to right
    // StartX as a fraction of 1, startY as a fraction of 1
    // SizeX as a fraction of 1
    // SizeY as a fraction of 1
    m_View.setViewport(FloatRect(viewportStartX, viewportStartY,
                                 viewportSizeX, viewportSizeY));
}

vector<shared_ptr<Button> > UIPanel::getButtons()
{
    return m_Buttons;
}

void UIPanel::draw(RenderWindow &window, Shader* shader)
{
    window.setView(m_View);
    if (!m_hidden) {
        auto tmp = m_panel.getGlobalBounds();
        ShaderManager::instance().getFragment("assets/shaders/edge")->setUniform("vertTexCoord", Glsl::Vec4(tmp.left, tmp.top, tmp.width, tmp.height));
        window.draw(m_panel, ShaderManager::instance().getFragment("assets/shaders/edge"));
        for (auto& it : m_Buttons) {
            it->draw(window, shader);
        }
    }
}

void UIPanel::show()
{
    m_hidden = false;
}

void UIPanel::hide()
{
    m_hidden = true;
}
