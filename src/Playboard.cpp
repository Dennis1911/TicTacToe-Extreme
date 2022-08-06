#include <string>
#include <iostream>

#include "Playboard.hpp"

using namespace std;



int Playboard::setSymbol(const Symbol symbol, const int xVal, const int yVal)
{
    m_field.at(xVal).at(yVal) = symbol;

}

std::vector<std::vector<Symbol>> Playboard::getPlayboard() const
{
    return m_field;
}

void Playboard::printSymbol(const int x, const int y, const std::vector<std::vector<Symbol>> field)

{
	
	Symbol checkColor = field[x][y];
	switch (checkColor)
	{
		case Symbol::x:
			cout << "x ";
			break;
		case Symbol::o:
			cout << "o ";
			break;
        case Symbol::none:
            cout << "  ";
            break;
		default:
			char abc = char(checkColor + 95);
			cout << abc;
	}
}


void Playboard::printPlayboard(const Playboard& playboard)
{
	int width = m_width;
	int height = m_height;
	std::vector<std::vector<Symbol>> field = playboard.getPlayboard();

	for (int y = 0; y <= height; y++) // one row higher
	{
		for (int x = 0; x <= width; x++) // filling up a row with spaces or chips (if placed)

		{
			if (x == 0 && y == 0)
			{
				cout << "  ";
				continue;
			}
			if (x == 0)
			{
				cout << y << " ";
				continue;
			}
			if (y == 0)
			{
				cout << x << " ";
				continue;
			}
			else
			{
				printSymbol(x-1, y-1, field);
			}
		}
		cout << endl;
	}
}

bool Playboard::ifWon(const Symbol symbol, int xCord, int yCord)
{
	m_streakCounter = 0;
	if (Playboard::streak(symbol, xCord, yCord) == 3) 
	{
		return true; // gameover
	}
	else
	{
		return false; //no one has won
	}
}


int Playboard::streak(const Symbol symbol, int xCord, int yCord)
{
	bool validInput = xCord <= m_width && xCord >= 0 && yCord >= 0 && yCord <= m_height;
	if (validInput)
	{
		bool rightSymbol = m_field[xCord][yCord] == symbol;
		// if diagonal
		if (validInput && rightSymbol)
		{
			m_streakCounter++;
			streak(symbol, xCord - 1, yCord -1);
			cout << " what happens here" << endl;
		}
		else if (validInput && m_field[xCord + 2][yCord + 2] == symbol)
		{
			m_streakCounter++;
			streak(symbol, xCord + 3, yCord + 3);
			cout << " what happens here" << endl;
		}
	}
	return m_streakCounter;
}
