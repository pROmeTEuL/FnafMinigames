#include "shadermanager.h"

ShaderManager &ShaderManager::instance()
{
    static ShaderManager sm;
    return sm;
}

sf::Shader *ShaderManager::getShader(std::string filename) /// USE WITHOUT .VERT OR .FRAG
{
    auto it = m_Shaders.find(filename);
    if (it == m_Shaders.end()) {
        m_Shaders[filename] = new sf::Shader;
        m_Shaders[filename]->loadFromFile(filename + ".vert", filename + ".frag");
        return m_Shaders[filename];
    }
    return it->second;
}

sf::Shader *ShaderManager::getFragment(std::string filename)
{
    auto it = m_Shaders.find(filename);
    if (it == m_Shaders.end()) {
        m_Shaders[filename] = new sf::Shader;
        m_Shaders[filename]->loadFromFile(filename + ".frag", sf::Shader::Fragment);
        return m_Shaders[filename];
    }
    return it->second;
}
