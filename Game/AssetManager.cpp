#include "AssetManager.h"

void AssetManager::LoadTexture(std::string name, std::string fileName) {
    if (this->_textures.find(name) != this->_textures.end()) {
        std::cout << "Texture '" << name << "' already exist . Dont add again" << std::endl;
        return; 
    }

    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        this->_textures[name] = texture;
        std::cout << "Load texture '" << name << "' from file  '" << fileName << "'." << std::endl;
    } else {
        std::cout << "Couldn't load texture from file '" << fileName << "'." << std::endl;
    }
}


sf::Texture &AssetManager::GetTexture(std::string name) {
    return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName) {
    sf::Font font;
    if (font.loadFromFile(fileName)) {
        this->_fonts[name] = font;
    }
}

sf::Font &AssetManager::GetFont(std::string name) {
    return this->_fonts.at(name);
}

void AssetManager::clearAssets() {
    _textures.clear();
    _fonts.clear();
}


AssetManager::~AssetManager() {
   std::cout << "AssetManager destructor" << std::endl;
}