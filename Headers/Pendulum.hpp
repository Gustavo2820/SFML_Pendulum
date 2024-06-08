#pragma once

#include<iostream>
#include<cmath>

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Window/Event.hpp>

class Pendulum {
    private:
        //Vars
        float length;
        float mass;
        sf::Vector2f origin; //Coordinates of the pendulum string
        sf::Vector2f position; //Coordinates of the pendulum ball/end of the pendulum string

        //Physics Vars
        float angle; //In radians
        float angularVelocity;
        float angularAcceleration;
        float gravity;

        //SFML forms
        sf::CircleShape ball;
        sf::RectangleShape line;

        void initVars();
    public:
        //Constructors and Destructors
        Pendulum();
        Pendulum(float length, float x, float  y, float angle);
        virtual ~Pendulum();

        //Accessors
        
        //Functions
        sf::Vector2f polarToCartesian(sf::Vector2f PolarCoordinate, float radius);
        sf::Vector2f addVectors(sf::Vector2f vector1, sf::Vector2f vector2);
        //Update Functions
        void update();

        //Render Functions
        void render(sf::RenderTarget& target);
};