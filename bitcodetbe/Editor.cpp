#include "Editor.h"
#include "Utility.h"
#include <utility> // c++ library
#include <string>
#include <iostream>
#include  <SFML/Graphics.hpp>

Editor::Editor(std::pair<int, int> screenResolution, std::string applicationName, sf::Font font) {
    Editor::font = font;
    Editor::applicationName = applicationName;
    Editor::screenResolution = screenResolution;
}

void Editor::StartEditor() {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Bitcode");
    // Character - 65
    sf::Font font;

    if (!font.loadFromFile("C:/Users/ivano/OneDrive/Desktop/8bitfont.ttf")) {
        std::cout << "Error loading the font file" << std::endl;
        system("pause");
    }

    sf::Text text;
    text.setFont(font);
    sf::Event event;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }
    }
}

