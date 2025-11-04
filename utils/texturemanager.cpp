#include "texturemanager.h"

TextureManager &TextureManager::instance()
{
    static TextureManager tm;
    return tm;
}

sf::Texture &TextureManager::texture(std::string filename)
{
    auto it = m_textures.find(filename);
    if (it == m_textures.end()) {
        m_textures[filename].loadFromFile(filename);
        return m_textures[filename];
    }
    return it->second;
}
