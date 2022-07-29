#pragma once

enum Modes {human, randomBot, smartBot};

class GameManager
{
public:

    GameManager() {};
    ~GameManager() {};

    int countPlayers();
    Modes choosePlayers(int);
    void startGame();

private:
    int m_gameMode;

};