#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "screenmanager.h"

using namespace sf;
using namespace std;

class Engine
{
public:
    unique_ptr<ScreenManager> m_SM;
    Shader shader;
    Engine();
    void run();
private:
    void input();
    void update(float fps);
    void draw();
private:
    RenderWindow m_window;
    Vector2f m_resolution;
    Clock m_clock;
    Time m_dt;
    float m_FPS = 0;
};

#endif // ENGINE_H
