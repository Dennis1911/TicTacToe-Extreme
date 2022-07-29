#include <iostream>

#include "GameManager.hpp"
#include "InputHandler.hpp"

using namespace std;

int GameManager::countPlayers()
{
    int maxPlayers = 10; // temp muss weg
    int playerCount = InputHandler::getIntFromRange("Gebe die Anzahl der Spieler an: ", 1, maxPlayers);// from range weil max players == fields
    system("cls");
    // int playerCount = 10; // temp
    cout << "Anzahl der Spieler: " << playerCount << endl;
    return playerCount;
}

// choose how many and which types of players will play
Modes GameManager::choosePlayers(int playerCount)
{
    for (int i = 0; i <= playerCount; i++)
    {
        /* code */
    }
    
    return human;
}

void GameManager::startGame()
{
    int playerCount = countPlayers();
    Modes gamemode1 = choosePlayers(playerCount);
}

// InputManager schreiben... Damit man Spieleranzahl bestimmen kann... danach jeweils pro Spieler abfragen, welcher Typ gewählt wird