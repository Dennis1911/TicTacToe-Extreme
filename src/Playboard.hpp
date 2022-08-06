#pragma once

#include <vector>

#include "enum.hpp"


class Playboard
{
public:
    Playboard(const int width, const int height) :
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
    /* kann der wirklich weg bleiben??
    Playboard& operator=(const Playboard& create)
    {
        this->m_width = create.m_width;
        this->m_height = create.m_height;
        this->m_field = create.m_field;
    };
*/
    int setSymbol(const Symbol symbol, const int xVal, const int yVal);

    void printPlayboard(const Playboard& playboard);
    int getWidth();
    int getHeight();
    void printSymbol(const int x, const int y, const std::vector<std::vector<Symbol>> field);
    bool ifWon(const Symbol symbol, const int xCord, const int yCord);
    int streak(const Symbol symbol, const int xCord, const int yCord);

    std::vector<std::vector<Symbol>> getPlayboard() const;

private:
int m_width;
int m_height;
int m_lastPlacedX;
int m_lastPlacedY;
int m_streakCounter;
std::vector<std::vector<Symbol>> m_field;
};