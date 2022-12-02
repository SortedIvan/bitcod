#pragma once
#include <string>
#include <utility>
#include  <SFML/Graphics.hpp>

class Editor
{
    private:
        std::pair<int, int> screenResolution;
        std::string applicationName;
        sf::Font font;
    public:
        Editor(std::pair<int, int> screenResolution, std::string applicationName, sf::Font font);
        void StartEditor();
        std::pair<int, int> getScreenResolution();
        std::string GetApplicationName();
        sf::Font GetFont();


};
