#pragma once
#include <string>

#include "enum.hpp"
// #include "GameManager.hpp"

enum Modes {human = 1, randomBot = 2, smartBot = 3, noMode = 4};

class Player
{
public:
    Player()
        : m_playerType(Modes::noMode)
        , m_playerName("Player")
        , m_playerSymbol(Symbol::none)
    {};

    Player(const Modes playerType, const std::string playerName, const Symbol playerSymbol)
        : m_playerType(playerType)
        , m_playerName(playerName)
        , m_playerSymbol(playerSymbol)
    {};

    Modes getPlayerType();
    std::string getPlayerName();
    std::string setPlayerSymbol();
    

private:
    Modes m_playerType;
    std::string m_playerName;
    Symbol m_playerSymbol;
};