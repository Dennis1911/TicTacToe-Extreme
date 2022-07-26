#include "gtest/gtest.h"
#include "../src/game.hpp"


class GameTest
	: public ::testing::Test
{
protected:
	Game m_game;

	virtual void SetUp() override
	{
		m_game = Game();
	}

	void rollOnlyThisNumber(int nRolls, int rollResults) // Helferfunktion
	{
		for (int i = 0; i < nRolls; ++i)
		{
			m_game.roll(rollResults);
		}
	}
};

TEST_F(GameTest, ScoreIsZeroWithOnlyZeroRolls)
{
    // Given
    rollOnlyThisNumber(20,0);

    // When
    int score = m_game.getScore();

    // Then
    EXPECT_EQ(score, 0);

}

TEST_F(GameTest, ScoreIsTenWithOnlyOnesRolls)
{
    // Given
    rollOnlyThisNumber(20,1);

    // When
    int score = m_game.getScore();

    // Then
    EXPECT_EQ(score, 20);

}
/*
TEST_F(GameTest, ScoreIsTenWithOnlyOnesRolls)
{
    // Given
    rollOnlyThisNumber(20,1);

    // When
    int score = m_game.getScore();

    // Then
    EXPECT_EQ(score, 20);

}
*/
/*
TEST_F(GameTest, ScoreIsTenWithOnlyRolls)
{
    // Given
    rollOnlyThisNumber(20,1);

    // When
    int score = m_game.getScore();

    // Then
    EXPECT_EQ(score, 20);

}
*/