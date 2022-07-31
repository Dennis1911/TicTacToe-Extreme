#pragma once
#include <string>
// #include "GameManager.hpp"

enum Modes {human = 1, randomBot = 2, smartBot = 3, none = 4};

class Player
{
public:
    Player()
        : m_playerType(Modes::none)
        , m_playerName("Player")
        , m_playerLetter("x")
    {};

    Player(const Modes playerType, const std::string playerName, const char* playerLetter)
        : m_playerType(playerType)
        , m_playerName(playerName)
        , m_playerLetter(playerLetter)
    {};

    Modes getPlayerType();
    std::string getPlayerName();
    std::string setPlayerLetter();

protected:
    Modes m_playerType;
    std::string m_playerName;
    std::string m_playerLetter;
};