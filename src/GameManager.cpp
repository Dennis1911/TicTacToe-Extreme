#include <iostream>

#include "GameManager.hpp"
#include "InputHandler.hpp"

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
        if (playerMode == 1) // hier switch case
        {
            mode = human;
        }
        else if (playerMode == 2)
        {
            mode = randomBot;
        }
        
    return mode;
}

void GameManager::startGame()
{
    int playerCount = countPlayers();
    cout << "Human: 1" << endl;
    cout << "SmartBot: 2" << endl;
    cout << "RandomBot: 3" << endl;
    Modes playerList[playerCount];
    for (int i = 1; i <= playerCount; i++) // wahrscheinlich for loop auserhalb und so das multiset füllen
    {
        Modes gamemode = choosePlayers();
        cout << "Player " << i << " is " << gamemode << endl;
        playerList[i - 1] = gamemode;
        //Modes mode = playerMode; // bei enum switch case oder wie kann man aus einer Zahl ein Mode machen??
        // unordered multiset adden
    }
    cout << playerList[0] << endl;
}