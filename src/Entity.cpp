#include "Entity.hpp"

using namespace sf;

void Entity::setVelocity(Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vX, float vY)
{
    mVelocity.x = vX;
    mVelocity.y = vY;
}

Vector2f Entity::getVelocity() const
{
    return mVelocity;
}