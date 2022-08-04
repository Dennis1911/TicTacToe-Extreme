#include <iostream>
#include <list>

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
    // cout << "Who should be " << i << "sein?" << endl;
        string textRequest = "Which type is the next Player?: ";// << stoi(i) << "be?"; // stoi aber nach str??
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

// 
void GameManager::startGame()
{
    Player* player{NULL};
    Player playerInit;
    int playerCount = countPlayers();
    int randomBotCount{0};
    int smartBotCount{0};
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
            //playerName = playerInit.getPlayerName(); // check for doppeltes vorkommen von Namen
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
        
        Symbol playerSymbol = Symbol(playerCount);
        player = new Player(gamemode, playerName, playerSymbol);
        
        playerList.insert(playerList.begin(), *player); // Liste mit allen Spielern
    }
    runningGame(playerList);
}

void GameManager::runningGame(list<Player>& playerList)
{
    Playboard playboard(6,6);
    bool gameover = false;
    int currentPlayer = 0;
    do
    {
        list<Player>::iterator it = next( playerList.begin(), currentPlayer);
        cout << &it << endl; // wie kann man bei einem iterator auf eine Klasse auf die Inhalte zugreifen??

        string playerName = it->getPlayerName();
        cout << playerName << " it's your turn:" << endl;

        int xCord = InputHandler::getIntFromRange("Enter x coordinate: ", 1, 6);
        int yCord = InputHandler::getIntFromRange("Enter y coordinate: ", 1, 6);

        // check for valid symbol at cords
        // place player.symbol at cords
        if (true)
        {
            playboard.setSymbol(x, xCord - 1, yCord - 1);
            playboard.printPlayboard(playboard);
            // check for win here
            currentPlayer++;
        }
        else
        {
            cout << "This field is full. Place elsewhere." << endl;
            currentPlayer--;
        }
        
        

        if (currentPlayer == playerList.size()) // gameover = checkForWin();
        {
            gameover = true;
        }
        
    } while (gameover == false);
        
}

// std::list<int>::iterator it = std::next( myList.begin(), n );
// list element n