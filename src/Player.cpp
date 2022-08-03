#include <iostream>

#include "Player.hpp"
#include "InputHandler.hpp"

using namespace std;

/*
Modes Player::getPlayerType()
{}
*/
string Player::getPlayerName()
{
    m_playerName = InputHandler::getString("What is your name?: ");
    return m_playerName;
}

string Player::setPlayerSymbol()
{
    string Symbols[] = {"x", "o", "a", "b", "c"}; 
    m_playerSymbol = Symbols[1];
    return m_playerSymbol;
}