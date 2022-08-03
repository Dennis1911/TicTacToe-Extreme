#include <string>
#include <iostream>

#include "Playboard.hpp"

using namespace std;

int Playboard::setSymbol(const Symbol symbol, const int xVal)
{
    //Konvertiere in Array-Wert
    int x = xVal - 1;

    if (x >= m_width || x < 0)
        return -1;

    int posY = -1;
    for (int y = m_height - 1; y >= 0; y--)
    {
        if (m_field.at(x).at(y) == Symbol::z)
        {
            m_field.at(x).at(y) = symbol;
            posY = y + 1;
            m_lastPlacedX = x + 1;
            m_lastPlacedY = posY;
            break;
        }
    }
    return posY;
}

std::vector<std::vector<Symbol>> Playboard::getPlayboard() const
{
    return m_field;
}

void Playboard::printPlayboard(const int x, const int y, const std::vector<std::vector<Symbol>> field)

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
		default:
			cout << "  ";
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
				printPlayboard(x-1, y-1, field);;
			}
		}
		cout << endl;
	}
}
