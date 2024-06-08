#include "../Headers/Engine.hpp"
#include "../Headers/Pendulum.hpp"

//Init functions
void Engine::initWindow() {
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600; 

    this->videoMode.height = windowHeight;
    this->videoMode.width = windowWidth;
    this->window = new sf::RenderWindow(this->videoMode, "Pendulum", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);

    //Centering Window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;
    int windowPosX = (screenWidth - windowWidth) / 2;
    int windowPosY = (screenHeight - windowHeight) / 2;
    this->window->setPosition(sf::Vector2i(windowPosX, windowPosY));
}

void Engine::initVars() {
    this->window = nullptr;
}

//Constructors and Destructors
Engine::Engine () {
    this->initVars();
    this->initWindow();
}

Engine::~Engine() {
    delete this->window;
}

//Accessors
const bool Engine::running() const {
    return this->window->isOpen();
}

//Functions
void Engine::pollEvents()
{
    //Polling de Eventos
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    break;
                }
                break;
            }
        }
}

void Engine::addPendulum(const Pendulum& pendulum) {
    this->pendulums.push_back(pendulum);
}

//Update Functions
void Engine::update() {
    this->pollEvents();

    for(int i = 0 ; i < this->pendulums.size() ; i++) {
        pendulums[i].update();
    }
}

//Render Functions
void Engine::renderPendulums(sf::RenderTarget& target) {
    for(int i = 0 ; i < this->pendulums.size() ; i++) {
        pendulums[i].render(target);
    }
}

void Engine::render() {
    this->window->clear(sf::Color::Black);
    this->renderPendulums(*this->window);
    this->window->display();
}