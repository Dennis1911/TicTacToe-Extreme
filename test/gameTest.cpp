#include "gtest/gtest.h"
#include "gameManager.hpp"

#include <vector>


class GameTest
	: public ::testing::Test
{
protected:
	GameManager m_game;

	virtual void SetUp() override
	{
		m_game = GameManager();
	}

	void testSmartBot(std::vector<int> cords) // Helferfunktion
	{
		m_game.runningGame(humanPlayer, smartBot);
        // input should be cords for the humanPlaer
        // then see what the smartBot does
	}
};

TEST_F(GameTest, TestSmartBotHeShouldBlock)
{
    // Given
    std::vector<int> cords;
    cords.insert(cords.begin(), 2);
    cords.insert(cords.begin(), 2);
    cords.insert(cords.begin(), 1);
    cords.insert(cords.begin(), 1);
    testSmartBot(cords);

    // When
    playerType gameover = m_game.gameoverText(); // if Gameover with playerType smartBot then Test successfull 

    // Then
    EXPECT_EQ(gameover, smartBot);

}