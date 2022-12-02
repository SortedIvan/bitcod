#include "Editor.h"
#include "Utility.h"
#include <utility> // c++ library
#include <string>
#include <iostream>
#include  <SFML/Graphics.hpp>

bool MainLoop(sf::RenderWindow& window, sf::Event& event);

Editor::Editor(std::pair<int, int> screenResolution, std::string applicationName, sf::Font font) {
    Editor::font = font;
    Editor::applicationName = applicationName;
    Editor::screenResolution = screenResolution;
    Editor::text = sf::Text();
    text.setFont(font);
}

std::string Editor::getApplicationName() {
    return applicationName;
}

sf::Font Editor::getFont() {
    return font;
}

std::pair<int, int> Editor::getScreenResolution() {
    return screenResolution;
}

bool MainLoop(sf::RenderWindow& window, sf::Event& event) {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
                return true;
            }
        }
    }
    return false;
}


void Editor::StartEditor() {
    // Character - 65
    sf::Font font;
    sf::RenderWindow window(sf::VideoMode(screenResolution.first, screenResolution.second), applicationName);
    sf::Event event;
    window.clear(sf::Color::Black); // Before anything, make screen black;
    window.display();


    MainLoop(window, event);

}


