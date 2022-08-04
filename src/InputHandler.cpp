#include <iostream>
#include <string>

#include "InputHandler.hpp"

using namespace std;

string InputHandler::getString(string message)
{
    cout << message << endl;
    string newText;
    cin >> newText;
    return newText;
}

int InputHandler::getIntFromRange(string message, int min, int max)
{
    bool correctInput = false;
	int returnInt = 0;
	do
	{
		try {
		returnInt = std::stoi(getString(message));
		}
		catch (std::invalid_argument) {
			std::cout << "Gebe eine gueltige Eingabe an!" << std::endl;
			continue;
		}
		if (returnInt >= min && returnInt <= max)
		{
			correctInput = true;
		}
		else
		{
			std::cout << "Gebe eine gueltige Eingabe an!" << std::endl;
		}
	} while (correctInput == false);
	return returnInt;
}
