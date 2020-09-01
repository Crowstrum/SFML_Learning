#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
    private:
        RenderWindow mWindow;
        Texture mTexture;
        Sprite mPlayer;
        void processEvents();
        void update(Time dTime);
        void render();
        void handlePlayerInput(Keyboard::Key key, bool isPressed);

        float mSpeed = 100.0f;
        bool mIsMovingUp = false;
        bool mIsMovingDown = false;
        bool mIsMovingLeft = false;
        bool mIsMovingRight = false;
        //fixed timestep update speed
        static const Time TimePerFrame;

    public:
        Game();
        void run();
};
#endif