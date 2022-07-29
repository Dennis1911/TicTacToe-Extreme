#pragma once

enum Modes {human = 1, randomBot = 2, smartBot = 3};

class GameManager
{
public:

    GameManager() {};
    ~GameManager() {};

    int countPlayers();
    Modes choosePlayers();
    void startGame();

private:
    int m_gameMode;

};