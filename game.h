#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

int nodeId = 0;
int buttonDesicion;
std::string buttonText;
std::string text1;
std::string text2;
std::string text3;
bool optionClicked;
float xButtonPos;
float yButtonPos = 800;
int buttonCount;

class game{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow *window;
        sf::Text text;
        sf::Font font;
        sf::RectangleShape button;
        bool endGame;
        sf::Event sfEvent;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        bool mouseHeld;
        std::vector<sf::RectangleShape> buttons;

        void initWindow();
        void initVariables();
        void initFonts();
        void initButton();
        void initText();

    public:
        //Constructors and Deconstructors
        game();
        ~game();

        //Accesors

        //Modifiers

        //Functions
        const bool running() const;
        void pollEvents();

        void update();
        void updateGame();
        void updateButton();
        void updateMousePositions();
        void updateDesicions();
        void render();
        void renderButtonText(sf::RenderTarget &target);
        void renderBackground();
        void generateBackground(std::string, std::string, sf::RenderTarget &target);

};

#include "game.cpp"