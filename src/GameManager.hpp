#pragma once

#include <string>
#include <list>
#include <vector>

#include "Player.hpp"

enum Axis {xAxis, yAxis};

class GameManager
{
public:

    GameManager() {};
    ~GameManager() {};

    int countPlayers();
    Modes choosePlayers();
    int makeMove(Axis, Modes, bool);
    void startGame();
    void runningGame(std::list<Player>&);
    void gameoverText(bool, std::string);

private:
    int m_gameMode;
    std::vector<int> m_blockCords;

};