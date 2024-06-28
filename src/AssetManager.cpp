#include "AssetManager.hpp"

namespace cot {

    void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
        if (sf::Texture tex; tex.loadFromFile(filename))
            _textures[name] = tex;
    }

    sf::Texture& AssetManager::getTexture(const std::string& name) {
        return _textures.at(name);
    }

    void AssetManager::loadFont(const std::string& name, const std::string& filename) {
        if (sf::Font font; font.loadFromFile(filename))
            _fonts[name] = font;
    }

    sf::Font& AssetManager::getFont(const std::string& name) {
        return _fonts.at(name);
    }

}