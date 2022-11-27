#include "game.h"

//Constructors and Deconstructors
game::game(){
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initButton();
    this->initText();
}

game::~game(){
    delete this->window;
}

void game::initWindow(){
    this->endGame = false;
}

void game::initVariables(){
    this->videoMode = sf::VideoMode(1000,900);
    this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
}

//Accesors

//Modifiers

//Functions
const bool game::running() const{
    return this->window->isOpen();
}

void game::pollEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        switch(this->sfEvent.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->sfEvent.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
        }
    }
}

//Update Funtions
void game::update(){
    this->pollEvents();
    this->updateMousePositions();
    this->updateDesicions();
}

void game::updateButton(){
    float xPos;
    float yPos;
    std::stringstream ss;

    ss<<buttonText;
    this->text.setString(ss.str());

    xPos = xButtonPos;
    yPos = yButtonPos;

    this->button.setPosition(sf::Vector2f(xPos, yPos));
    this->text.setPosition(sf::Vector2f(xPos, yPos));
}

void game::updateMousePositions(){
    /*
        Update Mouse Position
    */
   this->mousePosWindow = sf::Mouse::getPosition(*this->window);
   this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void game::updateDesicions(){
    if(this->buttons.size() < buttonCount + 1){
        this->buttons.push_back(this->button);
    }

    //Check collisions
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(this->mouseHeld == false){
            this->mouseHeld = true;
            for(size_t i = 0; i<this->buttons.size(); i++){
                std::cout<<"Buttons:"<<this->buttons.size()<<"\n";
                if(this->buttons[i].getGlobalBounds().contains(this->mousePosView)){

                    if(this->buttons[i].getFillColor() == sf::Color::Red){
                        optionClicked = true;
                        buttonDesicion = 0;
                        std::cout<<"Option "<<buttonDesicion<<" Clicked \n";
                        this->buttons.clear();
                    }

                    else if(this->buttons[i].getFillColor() == sf::Color::Blue){
                        optionClicked = true;
                        buttonDesicion = 1;
                        std::cout<<"Option "<<buttonDesicion<<" Clicked \n";
                        this->buttons.clear();
                    }

                    else if(this->buttons[i].getFillColor() == sf::Color::Magenta){
                        optionClicked = true;
                        buttonDesicion = 2;
                        std::cout<<"Option "<<buttonDesicion<<" Clicked \n";
                        this->buttons.clear();
                    }
                }
            }     
        }
    }
    else{
        this->mouseHeld = false;
    }
    
}

//Render Funtions
void game::render(){
    this->window->clear();

    this->renderBackground();
    this->renderButtonText(*this->window);

    this->window->display();
}

void game::renderButtonText(sf::RenderTarget &target){
    for(size_t i = 0; i<this->buttons.size(); i++){
        if(i == 0){
            xButtonPos = 50;
            buttonText = text1;
            this->button.setFillColor(sf::Color::Red);
            this->updateButton();
        }
        if(i == 1 && !(nodeId == 7) && !(nodeId == 6) && !(nodeId == 5)){
            xButtonPos = 350;
            buttonText = text2;
            this->button.setFillColor(sf::Color::Blue);
            this->updateButton();
        }
        if(i == 2 && nodeId == 2){
            xButtonPos = 650;
            buttonText = text3;
            this->button.setFillColor(sf::Color::Magenta);
            this->updateButton();
        }
        target.draw(this->button);
        target.draw(this->text);
    }

}

void::game::renderBackground(){
    switch(nodeId){
        case 0:
            this->generateBackground("res/img/0.jpg","You wake up in prision, what do you do?",*this->window);
            break;
        case 1:
            this->generateBackground("res/img/1.jpg","You decide to wake up, whats next?",*this->window);
            break;
        case 2:
            this->generateBackground("res/img/2.jpg","There are 3 door, choose one and get freedom",*this->window);
            break;
        case 3:
            this->generateBackground("res/img/3.jpg","You win the fight against the wolf",*this->window);
            break;
        case 4:
            this->generateBackground("res/img/4.jpg","What were you thinking ._.",*this->window);
            break;
        case 5:
            this->generateBackground("res/img/5.jpg","Chimps are underrated je je",*this->window);
            break;
        case 6:
            this->generateBackground("res/img/Win.jpg","Niceeee you are free ;)",*this->window);
            break;
        case 7:
            this->generateBackground("res/img/Lose.jpg","You die fighting with these monsters",*this->window);
            break;
    }
}

void game::generateBackground(std::string textureLink, std::string bgText, sf::RenderTarget &target){
    sf::Texture texture;
    sf::Sprite sprite;
    float xPos;
    float yPos;
    std::stringstream ss;

    if(!texture.loadFromFile(textureLink)){
        std::cout<<"ERROR::GAME::generateBackground::FAILED TO LOAD TEXTURE";
    }

    sprite.setTexture(texture);
    target.draw(sprite);

    buttonText = bgText;
    ss<<buttonText;
    this->text.setString(ss.str());
    xPos = 50;
    yPos = 700;
    this->text.setPosition(sf::Vector2f(xPos, yPos));
    target.draw(this->text);
    



}

void game::initFonts(){
    if(!this->font.loadFromFile("res/fonts/OpenSans-Regular.ttf")){
        std::cout<<"ERROR::GAME::INITFONTS::FAILED TO LOAD FONTS";
    }
}

void game::initButton(){
    this->button.setFillColor(sf::Color::White);
    this->button.setSize(sf::Vector2f(200.f, 30.f));
}

void game::initText(){
    this->text.setFont(this->font);
    this->text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::White);
    this->text.setString("EMPTY TEXT");
}

