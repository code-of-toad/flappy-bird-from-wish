#include "AssetManager.hpp"

namespace ToadCode {

    void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
        sf::Texture tex;
        if (tex.loadFromFile(filename)) {
            _textures[name] = tex;
        }
    }

    sf::Texture& AssetManager::getTexture(const std::string& name) {
        return _textures.at(name);
    }

    void AssetManager::loadFont(const std::string& name, const std::string& filename) {
        sf::Font font;
        if (font.loadFromFile(filename)) {
            _fonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont(const std::string& name) {
        return _fonts.at(name);
    }






}