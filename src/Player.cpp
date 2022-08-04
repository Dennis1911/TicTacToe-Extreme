#include <iostream>
#include <string>

#include "Player.hpp"
#include "InputHandler.hpp"

using namespace std;

/*
Modes Player::getPlayerType()
{}
*/
string Player::getPlayerName()
{
    // m_playerName = InputHandler::getString("What is your name?: ");
    return m_playerName;
}

string Player::setPlayerSymbol() // hier rather Symbol übergeben und dann vllt hier die String conversion machen?
{
    
    string m_playerSymbol = "Symbols[1]";
    return m_playerSymbol;
}
