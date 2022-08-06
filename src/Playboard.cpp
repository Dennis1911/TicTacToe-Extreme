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

void Playboard::printSymbol(const int xCord, const int yCord, const std::vector<std::vector<Symbol>> field)

{
	
	Symbol checksymbol = field[xCord][yCord];
	switch (checksymbol)
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
			char abc = char(checksymbol + 95);
			cout << abc;
	}
}


void Playboard::printPlayboard(const Playboard& playboard)
{
	int width = m_width;
	int height = m_height;
	std::vector<std::vector<Symbol>> field = playboard.getPlayboard();

	for (int yCord = 0; yCord <= height; yCord++) // one row higher
	{
		for (int xCord = 0; xCord <= width; xCord++) // filling up a row with spaces or chips (if placed)

		{
			if (xCord == 0 && yCord == 0)
			{
				cout << "  ";
				continue;
			}
			if (xCord == 0)
			{
				cout << yCord << " ";
				continue;
			}
			if (yCord == 0)
			{
				cout << xCord << " ";
				continue;
			}
			else
			{
				printSymbol(xCord-1, yCord-1, field);
			}
		}
		cout << endl;
	}
}

bool Playboard::ifWon(const Symbol symbol, const int xCord, const int yCord)
{
    return streak(symbol, xCord - 1, yCord, -1, 0) + streak(symbol ,xCord + 1, yCord, 1, 0) >= 2 ||
        streak(symbol, xCord, yCord - 1, 0, -1) + streak(symbol, xCord, yCord + 1, 0, 1) >= 2 ||
        streak(symbol, xCord - 1, yCord - 1, -1, -1) + streak(symbol, xCord + 1, yCord + 1, 1, 1) >= 2 ||
        streak(symbol, xCord - 1, yCord + 1, -1, 1) + streak(symbol, xCord + 1, yCord - 1, 1, -1) >= 2;
}


int Playboard::streak(const Symbol symbol, const int xCord, const int yCord, const int xdir, const int ydir)
{
	bool validInput = xCord < m_width && xCord >= 0 && yCord >= 0 && yCord < m_height;
	if (validInput)
    {
        if (m_field[xCord][yCord] == symbol)
        {
            return streak(symbol,xCord + xdir, yCord + ydir, xdir, ydir) + 1;
        }
    }

    return 0;
}
