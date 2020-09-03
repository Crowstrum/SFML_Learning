#include "Entity.hpp"

class Ship : public Entity
{
public:
    enum Type
    {
        Mantis,
        Raptor
    };

public:
    explicit Ship(Type type);

private:
    Type mType;
};