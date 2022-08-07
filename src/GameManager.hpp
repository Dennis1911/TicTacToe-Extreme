#pragma once

#include <string>
#include <list>

#include "Player.hpp"

enum Axis {xAxis, yAxis};

class GameManager
{
public:

    GameManager() {};
    ~GameManager() {};

    int countPlayers();
    Modes choosePlayers();
    int makeMove(Axis, Modes);
    void startGame();
    void runningGame(std::list<Player>&);

private:
    int m_gameMode;

};