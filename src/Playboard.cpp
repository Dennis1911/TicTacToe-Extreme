#include <string>
#include <iostream>

#include "Playboard.hpp"

using namespace std;

// checks if no symbol is at a specific coordinate
bool Playboard::checkSymbol(const Symbol symbol, const int xCord, const int yCord)
{
	bool validInput = xCord < m_width && xCord >= 0 && yCord >= 0 && yCord < m_height;
	if (validInput)
	{
		if(m_field.at(xCord).at(yCord) == none)
	{
		return true;
	}
	}
	return false;
}

void Playboard::setSymbol(const Symbol symbol, const int xVal, const int yVal)
{
    m_field.at(xVal).at(yVal) = symbol;
}

std::vector<std::vector<Symbol>> Playboard::getPlayboard() const
{
    return m_field;
}

// prints a players symbol to the playboard (x, o, a, b, c,...)
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
			cout << abc << " ";
	}
}

// prints the playboard according to the size of the board (given in parameter.txt)
void Playboard::printPlayboard(const Playboard& playboard)
{
	int width = m_width;
	int height = m_height;
	std::vector<std::vector<Symbol>> field = playboard.getPlayboard();

	for (int yCord = 0; yCord <= height; yCord++) // vertical
	{
		for (int xCord = 0; xCord <= width; xCord++) // horizontal - filling up a row with spaces or symbols (if any are placed)

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
bool Playboard::playboardIsFull()
{
	int fields = m_height * m_width;
	cout << fields << endl;
	m_moveCount++;
	bool playboardFull {fields <= m_moveCount};

	return playboardFull;
}

// check for 3 identical symbols in a row, vertically and diagonally and if playboard is full
bool Playboard::ifWon(const Symbol symbol, const int xCord, const int yCord)
{
	
    return streak(symbol, xCord - 1, yCord, -1, 0) + streak(symbol ,xCord + 1, yCord, 1, 0) >= 2 ||
        streak(symbol, xCord, yCord - 1, 0, -1) + streak(symbol, xCord, yCord + 1, 0, 1) >= 2 ||
        streak(symbol, xCord - 1, yCord - 1, -1, -1) + streak(symbol, xCord + 1, yCord + 1, 1, 1) >= 2 ||
        streak(symbol, xCord - 1, yCord + 1, -1, 1) + streak(symbol, xCord + 1, yCord - 1, 1, -1) >= 2;
}

// checks if a Player has 2 symbols in a row - so that the smartBot can block
vector<int> Playboard::smartBotBlock(const Symbol symbol, const int xCord, const int yCord)
{
    bool blockHorizontal {streak(symbol, xCord - 1, yCord, -1, 0) + streak(symbol ,xCord + 1, yCord, 1, 0) >= 1};
    bool blockVertical {streak(symbol, xCord, yCord - 1, 0, -1) + streak(symbol, xCord, yCord + 1, 0, 1) >= 1};
    bool blockDiag1 {streak(symbol, xCord - 1, yCord - 1, -1, -1) + streak(symbol, xCord + 1, yCord + 1, 1, 1) >= 1};
    bool blockDiag2 {streak(symbol, xCord - 1, yCord + 1, -1, 1) + streak(symbol, xCord + 1, yCord - 1, 1, -1) >= 1};

	vector<int> blockCords;

	if (blockHorizontal)
	{
		int blockX;
		int blockY;
		if (checkSymbol(symbol, xCord - 1, yCord))
		{
			int blockX = xCord - 1;
			int blockY = yCord;
			bool validInput = blockX < m_width && blockX >= 0 && blockY >= 0 && blockY < m_height;
			//setSymbol(symbol, blockX, blockY);
			blockCords.insert(blockCords.begin(), blockX);
			blockCords.insert(blockCords.begin(), blockY);

			return blockCords;
		}
		else if (checkSymbol(symbol, xCord + 1, yCord))
		{
			int blockX = xCord + 1;
			int blockY = yCord;
			bool validInput = blockX < m_width && blockX >= 0 && blockY >= 0 && blockY < m_height;
			//setSymbol(symbol, blockX, blockY);
			blockCords.insert(blockCords.begin(), blockX);
			blockCords.insert(blockCords.begin(), blockY);

			return blockCords;
		}
		else
		{
			return blockCords;
		}	
	}
}

// count the symbols that are next to each other
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
