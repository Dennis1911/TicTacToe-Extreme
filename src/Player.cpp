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

string Player::setPlayerSymbol() // hier rather Symbol übergeben und dann vllt hier die String conversion machen?
{
    
    string m_playerSymbol = "Symbols[1]";
    return m_playerSymbol;
}
