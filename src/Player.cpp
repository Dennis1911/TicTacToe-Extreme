#include <iostream>
#include <string>

#include "Player.hpp"
#include "InputHandler.hpp"

using namespace std;


string Player::getPlayerName()
{

    return m_playerName;
}

Symbol Player::getPlayerSymbol()
{
    return m_playerSymbol;
}

Modes Player::getPlayerType()
{
    return m_playerType;
}

string Player::setPlayerSymbol() // hier rather Symbol übergeben und dann vllt hier die String conversion machen?
{
    
    string m_playerSymbol = "Symbols[1]";
    return m_playerSymbol;
}

/*
vector<int> smartBotMove()
{
    vector<int> cords;
    if (smartBotBlock(const Symbol symbol, const int xCord, const int yCord))
    {
        return cords;
    }
    
}
*/