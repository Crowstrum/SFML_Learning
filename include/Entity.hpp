#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/graphics.hpp>

class Entity
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vX, float vY);
    sf::Vector2f getVelocity() const;

private:
    sf::Vector2f mVelocity;
};

#endif