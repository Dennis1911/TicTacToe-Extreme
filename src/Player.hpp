#pragma once
#include <string>
#include "GameManager.hpp"

class Player
{
public:
    Player()
        : m_playerType(human)
        , m_playerName("Player")
        , m_playerLetter("x")
    {};
/*
    Player(const Modes playerType, const std::string playerName, const std::string playerLetter)
        : m_playerType(playerType)
        , m_playerName(playerName)
        , m_playerLetter(playerLetter)
    {};
*/
    Modes getPlayerType();
    std::string getPlayerName();
    std::string setPlayerLetter();

protected:
    Modes m_playerType;
    std::string m_playerName;
    std::string m_playerLetter;
};