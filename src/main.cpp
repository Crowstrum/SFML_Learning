#include "Game.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace Textures
{
    enum ID
    {
        Landscape,
        Spaceship,
        Missle
    };
}
int main()
{
    Game game;
    game.run();
    return 0;
}