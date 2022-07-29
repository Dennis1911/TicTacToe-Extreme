#include <iostream>

#include "GameManager.hpp"
#include "InputHandler.hpp"

using namespace std;

int GameManager::countPlayers()
{
    int maxPlayers = 10; // temp muss weg
    int playerCount = InputHandler::getIntFromRange("Gebe die Anzahl der Spieler an: ", 1, maxPlayers);// from range weil max players == fields
    system("cls");
    
    cout << "Anzahl der Spieler: " << playerCount << endl;
    return playerCount;
}

// choose how many and which types of players will play
Modes GameManager::choosePlayers(int playerCount)
{
    // cout << "Who should be " << i << "sein?" << endl;
        string textRequest = "Who should be player ";// << stoi(i) << "be?"; // stoi aber nach str??
        string playerModeStr = InputHandler::getString(textRequest);
        int playerMode = stoi(playerModeStr);
        Modes mode;
        if (playerMode == 1)
        {
            mode = smartBot;
        }
    return mode;
}

void GameManager::startGame()
{
    int playerCount = countPlayers();
    cout << "Human: 1" << endl;
    cout << "SmartBot: 2" << endl;
    cout << "RandomBot: 3" << endl;
    for (int i = 1; i <= playerCount; i++) // wahrscheinlich for loop auserhalb und so das multiset füllen
    {
        Modes gamemode = choosePlayers(playerCount);
        cout << "Player " << i << " is " << gamemode << endl;
        //Modes mode = playerMode; // bei enum switch case oder wie kann man aus einer Zahl ein Mode machen??
        // unordered multiset adden
    }
}