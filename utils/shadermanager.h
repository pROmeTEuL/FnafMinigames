#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <SFML/Graphics/Shader.hpp>
#include <map>

class ShaderManager
{
    std::map<std::string, sf::Shader*> m_Shaders;
    ShaderManager() = default;
public:
    static ShaderManager& instance();
    sf::Shader* getShader(std::string filename);
    sf::Shader* getFragment(std::string filename);
};

#endif // SHADERMANAGER_H
