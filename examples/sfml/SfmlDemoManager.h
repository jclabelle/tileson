//
// Created by robin on 22.09.2019.
//

#ifndef TILESON_SFMLDEMOMANAGER_H
#define TILESON_SFMLDEMOMANAGER_H


#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include <map>
#include "vera_font.h"
#include "../../include/tileson.h"

#if __clang__
#include <mach-o/dyld.h>
#endif

class SfmlDemoManager
{
    public:
        SfmlDemoManager() = default;

        void initialize( const sf::Vector2i &windowSize, const sf::Vector2i &resolution = {400, 240},
                         const std::string &title = "SFML Tileson demo",
                         const fs::path &basePath = fs::path("../../../content/test-maps/"));
        bool parseMap(const std::string &filename = "ultimate_test.json");
        void run();

    private:
        #if __clang__
        fs::path getMacApplicationFolder(bool isAppPath);
        #endif
        
        void drawMap();

        static constexpr int CURRENT_VERSION = 120; //v1.2.0

        void drawLayer(tson::Layer& layer);
        void drawTileLayer(const tson::Layer& layer);//, tson::Tileset* tileset);
        void drawImageLayer(tson::Layer& layer);
        void drawObjectLayer(tson::Layer& layer);

        sf::Vector2f getTileOffset(int tileId);

        sf::Sprite * storeAndLoadImage(const std::string &image, const sf::Vector2f &position);

        fs::path m_basePath {};
        sf::RenderWindow m_window;
        std::unique_ptr<tson::Map> m_map;

        sf::Font m_font;
        sf::Text m_demoText;

        std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
        std::map<std::string, std::unique_ptr<sf::Sprite>> m_sprites;
};


#endif //TILESON_SFMLDEMOMANAGER_H