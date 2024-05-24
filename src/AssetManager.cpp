#include "AssetManager.hpp"

namespace ToadCoad {

    void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
        sf::Texture tex;
        if (tex.loadFromFile(filename)) {
            this->_textures[name] = tex;
        }
    }

    sf::Texture& AssetManager::getTexture(const std::string& name) {
        return this->_textures.at(name);
    }

    void AssetManager::loadFont(const std::string& name, const std::string& filename) {
        sf::Font font;
        if (font.loadFromFile(filename)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont(const std::string& name) {
        return this->_fonts.at(name);
    }






}