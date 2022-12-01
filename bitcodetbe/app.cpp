#include <iostream>
#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include <string>
#include <map>
#include <vector>
#include <stack>

using sf::Keyboard;

char GetInputCharacter(Keyboard::Key keystroke, std::map<Keyboard::Key, char>& alphabetMap);
void PrintLine(std::string stringToPrint);
void DisplayLineOnScreen(std::string lineToDisplay, sf::Text& textHolder, sf::RenderWindow& window);
void DisplayCharOnScreen(char inputChar, sf::Text& textHolder, sf::RenderWindow& window);
int GetStringLen(std::string stringToCheck);
std::string RemoveCharFromString(std::string stringToRemoveFrom);
std::string DeleteAndGetLastStringFromStack(std::stack<std::string>& text_lines);
void DisplayAllLines(std::vector<std::string>& text_content, sf::Text& textHolder, sf::RenderWindow& window);
std::string GetEntireText(std::vector<std::string>& text_content);

int main()
{
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

    std::vector<std::string> text_content;
    std::stack<std::string> text_lines;

    std::string current_line = "";

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode != '\b') {
                        std::string all_text = GetEntireText(text_content);
                        current_line += static_cast<char>(event.text.unicode);
                        window.clear();
                        DisplayLineOnScreen(all_text + current_line, text, window);
                    }

                }
            }
            
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Enter) {
                    text_lines.push(current_line);
                    current_line += '\n';
                    window.clear();
                    //DisplayLineOnScreen(current_line, text, window);
                    text_content.push_back(current_line);
                    DisplayAllLines(text_content, text, window);
                    current_line = "";
                }
                if (event.key.code == sf::Keyboard::Backspace) {
                    if (!GetStringLen(current_line) == 0) {
                        // if the current_line is not null
                        std::string all_text = GetEntireText(text_content);
                        current_line = RemoveCharFromString(current_line);
                        std::cout << current_line;
                        window.clear();
                        DisplayLineOnScreen(all_text + current_line, text, window);
                        continue;
                    }

                    if (GetStringLen(current_line) <= 0) {
                        window.clear();
                        std::string all_text = GetEntireText(text_content);
                        current_line = DeleteAndGetLastStringFromStack(text_lines);
                        text_content.pop_back();
                        DisplayLineOnScreen(all_text, text, window);
                    }
                }
            }
        }
    }
    return 0;
}

char GetInputCharacter(Keyboard::Key keystroke, std::map<Keyboard::Key, char>& alphabetMap)
{
    for (auto i : alphabetMap) {
        if (i.first == keystroke) {
            return i.second;
        }
    }
    return 0;
}

void PrintLine(std::string stringToPrint) {
    std::cout << stringToPrint; 
}

void DisplayLineOnScreen(std::string lineToDisplay, sf::Text& textHolder, sf::RenderWindow& window) {
    textHolder.setString(lineToDisplay);
    window.draw(textHolder);
    window.display();
}

void DisplayCharOnScreen(char inputChar, sf::Text& textHolder, sf::RenderWindow& window) {
    textHolder.setString(inputChar);
    window.draw(textHolder);
    window.display();
}

int GetStringLen(std::string stringToCheck) {
    int count = 0;
    while (stringToCheck[count] != '\0') {
        count++;
    }
    return count;
}

std::string RemoveCharFromString(std::string stringToRemoveFrom) {
    //stringToRemoveFrom.pop_back();
    stringToRemoveFrom.resize(stringToRemoveFrom.size() - 1);
    return stringToRemoveFrom;
}

std::string DeleteAndGetLastStringFromStack(std::stack<std::string>& text_lines) {
    std::string top_line = text_lines.top();
    text_lines.pop();
    return top_line;
}

void DisplayAllLines(std::vector<std::string>& text_content, sf::Text& textHolder, sf::RenderWindow& window) {
    std::string all_text = "";
    for (auto line : text_content) {
        all_text += line;
    }
    DisplayLineOnScreen(all_text, textHolder, window);
}

std::string GetEntireText(std::vector<std::string>& text_content) {
    std::string all_text = "";
    for (auto line : text_content) {
        all_text += line;
    }
    return all_text;
}