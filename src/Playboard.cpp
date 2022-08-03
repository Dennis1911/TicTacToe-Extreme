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
				printSymbol(x-1, y-1, field);
			}
		}
		cout << endl;
	}
}
