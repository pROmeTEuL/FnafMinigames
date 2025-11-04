#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <SFML/Graphics/Texture.hpp>

class TextureManager
{
public:
    static TextureManager &instance();
    sf::Texture &texture(std::string filename);

private:
    TextureManager() = default;

private:
    std::map<std::string, sf::Texture> m_textures;
};

#endif // TEXTUREMANAGER_H
