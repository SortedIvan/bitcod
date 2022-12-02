#pragma once
#include <string>
#include <utility>
#include <vector>
#include  <SFML/Graphics.hpp>

class Editor
{
    private:
        std::pair<int, int> screenResolution;
        std::string applicationName;
        sf::Font font;
        sf::Text text;
    public:
        Editor(std::pair<int, int> screenResolution, std::string applicationName, sf::Font font);
        void StartEditor();
        std::pair<int, int> getScreenResolution();
        std::string getApplicationName();
        sf::Font getFont();
        


};
