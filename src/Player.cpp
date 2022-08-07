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
