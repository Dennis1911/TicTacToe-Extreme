#pragma once

#include <vector>

enum Symbol {x, o, a, b, c, d, e, f, g, h, i, j, k, l, m, n, p, q, r, s, t, u, v, w, y, z}; // kann man wohl auch in Parameter schreiben

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
                col.push_back(Symbol::z);
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

    std::vector<std::vector<Symbol>> getPlayboard() const;

private:
int m_width;
int m_height;
int m_lastPlacedX;
int m_lastPlacedY;
std::vector<std::vector<Symbol>> m_field;
};