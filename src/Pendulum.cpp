#include "../Headers/Engine.hpp"
#include "../Headers/Pendulum.hpp"

//Constructors and Destructors
Pendulum::Pendulum(float length, float x, float  y, float angle) {
    this->length = length;
    this->origin = sf::Vector2f(x, y);
    this->angle = angle;
    this->gravity = 0.005;
    sf::Vector2f cartesianCoordinate = this->polarToCartesian(sf::Vector2f(this->angle, this->length), this->length);
    this->position = this->addVectors(this->origin, cartesianCoordinate);

    this->angularAcceleration = 0.0;
    this->angularVelocity = 0.0;

    this->ball.setRadius(40.0);
    this->ball.setFillColor(sf::Color::Blue);
    this->ball.setPosition(this->position);

    this->line.setSize(sf::Vector2f(this->length, 3));  
    this->line.setFillColor(sf::Color::White);
    this->line.setOrigin(0, 1.5);  // Origin set to the middle of the thickness
    this->line.setPosition(this->origin);
    this->line.setRotation((this->angle + M_PI / 2) * 180 / M_PI); 
}

Pendulum::~Pendulum() {
    
}

//Functions
sf::Vector2f Pendulum::polarToCartesian(sf::Vector2f polarCoordinate, float radius) {
    sf::Vector2f cartesianCoordinate;
    cartesianCoordinate.x = radius * sin(polarCoordinate.y);
    cartesianCoordinate.y = radius * cos(polarCoordinate.y);
    
    return cartesianCoordinate;
}

sf::Vector2f Pendulum::addVectors(sf::Vector2f vector1, sf::Vector2f vector2) {
    sf::Vector2f result;
    result.x = vector1.x + vector2.x;
    result.y = vector1.y + vector2.y;
    return result;
}

//Update Function
void Pendulum::update() {
    this->angularAcceleration = -1.0 * this->gravity * sin(this->angle);
    this->angularVelocity += angularAcceleration;
    this->angle += angularVelocity;

    sf::Vector2f polarCoordinate = sf::Vector2f(this->length, this->angle);

    sf::Vector2f cartesianCoordinate = this->polarToCartesian(polarCoordinate, this->length);
    this->position = this->addVectors(this->origin, cartesianCoordinate);

    this->line.setPosition(this->origin);

    this->line.setRotation((-this->angle + M_PI / 2) * 180 / M_PI);

    this->ball.setPosition(this->position);

    sf::Vector2f ballOffset = sf::Vector2f(this->ball.getRadius(), this->ball.getRadius());
    this->ball.move(-ballOffset);
}

//Render Functions
void Pendulum::render(sf::RenderTarget& target) {
    target.draw(this->line);
    target.draw(this->ball);
}
