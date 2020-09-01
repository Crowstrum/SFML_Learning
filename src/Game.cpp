#include "Game.hpp"
#include "iostream"

using namespace sf;

//fixed time frame 60 frames per second, see run()
const Time Game::TimePerFrame = seconds(1.0f / 60.0f);

Game::Game()
    : mWindow(VideoMode(640, 480), "SFML Game"), mPlayer()
{
    if (!mTexture.loadFromFile("assets/mantis.png"))
    {
        //handle loading error
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.0f, 100.0f);
    mPlayer.scale(Vector2f(2.0f, 2.0f));
}

void Game::run()
{
    //measures elapsed time
    Clock clock;
    //start our update check at 0.
    Time timeSinceLastUpdate = Time::Zero;
    while (mWindow.isOpen())
    {
        //fixed timestep, only run update and event processing
        // add up the time for each loop, restart returns elapsed time, and resets back to 0
        timeSinceLastUpdate += clock.restart();
        //std::cout << " TSLU: " << timeSinceLastUpdate.asSeconds() << " TPF: " << TimePerFrame.asSeconds() << std::endl;
        //once the time > our fixed refresh rate of 1/60, process game events
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        //render the game screen
        render();
    }
}

void Game::processEvents()
{
    Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Game::update(Time dTime)
{
    Vector2f movement(0.0f, 0.0f);
    if (mIsMovingUp)
    {
        movement.y -= 1.0f;
    }
    if (mIsMovingDown)
    {
        movement.y += 1.0f;
    }
    if (mIsMovingLeft)
    {
        movement.x -= 1.0f;
    }
    if (mIsMovingRight)
    {
        movement.x += 1.0f;
    }
    //std::cout << movement.x << " " << movement.y;
    mPlayer.move((movement * mSpeed) * dTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(Keyboard::Key code, bool isPressed)
{
    if (code == Keyboard::W)
    {
        mIsMovingUp = isPressed;
    }
    else if (code == Keyboard::S)
    {
        mIsMovingDown = isPressed;
    }
    else if (code == Keyboard::A)
    {
        mIsMovingLeft = isPressed;
    }
    else if (code == Keyboard::D)
    {
        mIsMovingRight = isPressed;
    }
}
