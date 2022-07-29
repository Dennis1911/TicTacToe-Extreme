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

string Player::setPlayerLetter()
{
    string Letters[] = {"x", "o", "a", "b", "c"}; 
    m_playerLetter = Letters[1];
    return m_playerLetter;
}