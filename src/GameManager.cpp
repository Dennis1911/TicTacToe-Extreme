#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <ctime>


#include "GameManager.hpp"
#include "InputHandler.hpp"
#include "Player.hpp"
#include "Playboard.hpp"
#include "enum.hpp"


using namespace std;

// choose how many players will play
int GameManager::countPlayers()
{
    int maxPlayers = 10; // temp muss weg
    int playerCount = InputHandler::getIntFromRange("Gebe die Anzahl der Spieler an: ", 1, maxPlayers);// from range weil max players == fields
    
    cout << "Anzahl der Spieler: " << playerCount << endl;
    return playerCount;
}

// choose which types of players will play
Modes GameManager::choosePlayers()
{
    string textRequest = "Which type is the next Player?: ";
    string playerModeStr = InputHandler::getString(textRequest);
    int playerMode = stoi(playerModeStr);
    Modes mode;
    switch (playerMode)
    {
    case 1:
        mode = human;
        break;
    case 2:
        mode = randomBot;
        break;
    case 3:
        mode = smartBot;
        break;
    
    default:
        cout << "Invalid Input! Only enter numbers between 1 and 3." << endl;
        choosePlayers();
        break;
    }
    
    return mode;
}

// return the x or y coordinates from the different PlayerTypes
int GameManager::makeMove(Axis axis, Modes mode, bool validMove)
{
    int xCord{-1};
    int yCord{-1};
    switch (mode)
    {
    case human:
        if (axis == xAxis)
        {
            xCord = InputHandler::getIntFromRange("Enter x coordinate: ", 1, 6) - 1; // playboard size
        }
        else if(axis == yAxis)
        {
            yCord = InputHandler::getIntFromRange("Enter y coordinate: ", 1, 6) - 1; // playboard size
        }
        break;

    case randomBot:
        if (axis == xAxis)
        {
            xCord = rand() % 6; // playboard size - 1 ... ansonsten wegen + 1 zu groß
        }
        else if(axis == yAxis)
        {
            yCord = rand() % 6;  
        }
        break;
    
    case smartBot:

        if (axis == xAxis)
        {
            if (m_blockCords.empty() || validMove == false)
            {
                 xCord = rand() % 6;
            }
            else
            {
                xCord = m_blockCords.at(1);
            }
            
        }
        else if(axis == yAxis)
        {
            if (m_blockCords.empty() || validMove == false)
            {
               yCord = rand() % 6;
            }
            else
            {
                yCord = m_blockCords.at(0);
            }
        break;
    }
    }
    if (axis == xAxis)
    {
        return xCord;
    }
    else
    {
        return yCord;
    }
}

// 
void GameManager::startGame()
{
    Player* player{NULL};
    Player playerInit;
    int playerCount = countPlayers();
    int randomBotCount{1};
    int smartBotCount{1};
    srand(time(0)); // for better random numbers
    cout << "Human: 1" << endl;
    cout << "SmartBot: 2" << endl;
    cout << "RandomBot: 3" << endl;
    list<Player> playerList;

    for (int i = 1; i <= playerCount; i++) // ausgliedern? playerInitialize....
    {
        Modes gamemode = choosePlayers();
        cout << "Player " << i << " is " << gamemode << endl;
        string playerName;
        switch (gamemode)
        {
        case 1:
            playerName = InputHandler::getString("What is your name?: ");
            //playerName = playerInit.getPlayerName(); // check for doppeltes vorkommen von Namen - for loop in string checkName liefert namen
            break;
        case 2:
            playerName = "Randombot " + to_string(randomBotCount);
            randomBotCount++;
            break;
        case 3:
            playerName = "Smartbot " + to_string(smartBotCount);
            smartBotCount++;
            break;
        }
        
        Symbol playerSymbol = Symbol(i - 1);
        player = new Player(gamemode, playerName, playerSymbol);
        
        playerList.insert(playerList.begin(), *player); // List with all players
    }
    playerList.reverse(); // reverse list so that first named player begins
    runningGame(playerList);
}

void GameManager::runningGame(list<Player>& playerList)
{
    Playboard playboard(6,6);
    bool gameover{false};
    int currentPlayer{0};
    string playerName;
    bool validMove{true};
    bool playerHasWon{false};
    do
    {
        playboard.printPlayboard(playboard);
        list<Player>::iterator it = next( playerList.begin(), currentPlayer);

        playerName = it->getPlayerName();
        cout << playerName << " it's your turn:" << endl;

        Symbol playerSymbol = it->getPlayerSymbol();
        Modes playerMode = it->getPlayerType();

        // get xCord and yCord from the different PlayerTypes
        int xCord = makeMove(xAxis, playerMode, validMove);
        int yCord = makeMove(yAxis, playerMode, validMove);

        // check for valid symbol at cords
        validMove = playboard.checkSymbol(playerSymbol, xCord, yCord);

        // place player.symbol at cords
        if (validMove)
        {
            playboard.setSymbol(playerSymbol, xCord, yCord);
            playerHasWon = playboard.ifWon(playerSymbol, xCord, yCord);
            gameover = playerHasWon || playboard.playboardIsFull();
            m_blockCords = playboard.smartBotBlock(playerSymbol, xCord, yCord);
            currentPlayer++;
        }
        else
        {
            cout << "This field is full. Place elsewhere." << endl;
        }
    
    if (currentPlayer >= playerList.size()) // loop through the list from the beginning
    {
        currentPlayer = 0;
    }
    } while (gameover == false); 
    playboard.printPlayboard(playboard);

    gameoverText(playerHasWon, playerName);
    
}

void GameManager::gameoverText(bool playerHasWon, string playerName)
{
    cout << "Gameover!" << endl;
    if (playerHasWon)
    {
        cout << playerName << " is the winner!" << endl;
    }
    else
    {
        cout << "No winner, the playboard is full." << endl;
    }
    
    
}