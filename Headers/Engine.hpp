#pragma once

#include "Pendulum.hpp"

class Engine {
    private:
        //Vars

        //Pendulums
        std::vector<Pendulum> pendulums;

        //Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;

        sf::Event event;

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //Functions
        void initWindow();
        void initVars();

    public:
        //Constructors and Destructors
        Engine();
        virtual ~Engine();

        //Accessors
        const bool running() const;

        //Functions
        void pollEvents();
        void addPendulum(const Pendulum& pendulum);

        //Update Functions
        void update();

        //Render Functions
        void renderPendulums(sf::RenderTarget& target);
        void render();
};