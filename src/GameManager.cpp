#include <iostream>
#include <list>

#include "GameManager.hpp"
#include "InputHandler.hpp"
#include "Player.hpp"


using namespace std;

// choose how many and
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

void GameManager::startGame()
{
    Player* player{NULL};
    Player playerInit;
    int playerCount = countPlayers();
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
            playerName = playerInit.getPlayerName();
            break;
        case 2:
            playerName = "RandomBot";
            break;
        case 3:
            playerName = "SmartBot";
            break;
        
        default:
            break;
        }
        player = new Player(gamemode, playerName, "x");
        
        playerList.insert(playerList.begin(), *player);
        //Modes mode = playerMode; // bei enum switch case oder wie kann man aus einer Zahl ein Mode machen??
        // unordered multiset adden
        // cout << *playerListIter << endl; // DENNIS HIER ... Liste richtig füllen gerade ist noch gamemode 
    }
    runningGame(playerList);

}

void GameManager::runningGame(list<Player>& playerList)
{
    bool gameover = false;
    int currentPlayer = 0;
    do
    {
        list<Player>::iterator it = next( playerList.begin(), currentPlayer);
        cout << &it << endl; // hier statt playerType den Name ausgeben
        currentPlayer++;
        if (currentPlayer == 5)
        {
            gameover = true;
        }
        
        
        // gameover = checkForWin();
    } while (gameover == false);
    

}

// std::list<int>::iterator it = std::next( myList.begin(), n );
// list element n