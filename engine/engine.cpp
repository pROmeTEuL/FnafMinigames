#include "engine.h"
#include <iostream>

Engine::Engine()
{
    m_resolution.x = VideoMode::getDesktopMode().width;
    m_resolution.y = VideoMode::getDesktopMode().height;
    m_window.create(VideoMode(m_resolution.x, m_resolution.y), "The Mislead", Style::Fullscreen);
    m_SM = make_unique<ScreenManager>(Vector2i(m_resolution.x, m_resolution.y));
    if (Shader::isAvailable())
        std::cout << "shaders work" << std::endl;
    else
        std::cout << "no shader" << std::endl;
}

void Engine::run()
{
    while (m_window.isOpen()) {
        m_dt = m_clock.restart();
        m_FPS = m_dt.asSeconds();
        input();
        update(m_FPS);
        draw();
    }
}

void Engine::input()
{
    m_SM->handleInput(m_window);
}

void Engine::update(float fps)
{
    m_SM->update(fps, Vector2i(m_resolution.x, m_resolution.y));
}

void Engine::draw()
{
    m_window.clear(Color::Black);
    m_SM->draw(m_window);
    m_window.display();
}
