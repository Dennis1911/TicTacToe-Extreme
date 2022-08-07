#pragma once

#include <vector>

#include "enum.hpp"

class Playboard
{
public:
    Playboard(const int width, const int height) :
        m_moveCount(0),
        m_width(width),
        m_height(height) {
        for (int x = 0; x < width; x++)
        {
            std::vector<Symbol> col;
            for (int y = 0; y < height; y++)
            {
                col.push_back(Symbol::none);
            }
            m_field.push_back(col);
        }
    };
	~Playboard() {};

    bool checkSymbol(const Symbol symbol, const int xCord, const int yCord);
    void setSymbol(const Symbol symbol, const int xCord, const int yCord);

    void printPlayboard(const Playboard& playboard);
    int getWidth();
    int getHeight();
    void printSymbol(const int x, const int y, const std::vector<std::vector<Symbol>> field);
    bool ifWon(const Symbol symbol, const int xCord, const int yCord);
    std::vector<int> smartBotBlock(const Symbol symbol, const int xCord, const int yCord);
    int streak(const Symbol symbol, const int xCord, const int yCord, const int xdir, const int ydir);
    bool playboardIsFull();
    int getMaxPlayers();

    std::vector<std::vector<Symbol>> getPlayboard() const;

private:
int m_width;
int m_height;
int m_streakCounter;
int m_moveCount;
std::vector<std::vector<Symbol>> m_field;
};