#pragma once

#include <string>
#include <list>

#include "Player.hpp"


class GameManager
{
public:

    GameManager() {};
    ~GameManager() {};

    int countPlayers();
    Modes choosePlayers();
    void startGame();
    void runningGame(std::list<Player>&);

private:
    int m_gameMode;

};