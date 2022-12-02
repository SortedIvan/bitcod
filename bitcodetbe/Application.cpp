#include <iostream>
#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include "Editor.h"
#include <utility>

int main()
{
    std::pair<int, int> screenResolution;
    screenResolution.first = 1500;
    screenResolution.second = 1000;
    sf::Font font;

    if (!font.loadFromFile("../bitcodetbe/8bitfont.ttf")) {
        std::cout << "Error loading the font file" << std::endl;
        system("pause");
    }

    Editor editor(screenResolution, "Bitcode", font);
    editor.StartEditor();
    return 0;
}
