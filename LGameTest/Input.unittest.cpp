#include "pch.h"
#include "../LGame/Game.h"
#include "../LGame/Input.h"

TEST(Input, ContinueGameStateTest)
{
    Game game; // Create a game object

    SFMLKeyboardInput input; // Create an sfml keyboard input object

    input.m_continue = true; // Set the continue input to true
    
    // Check the game is in the right state to begin with
    EXPECT_EQ(GameState::View, game.getGameState());

    // Update the game state with the continue button pressed in the input object
    game.updateGameState(&input);

    // Check that the game state has changed correctly
    EXPECT_EQ(GameState::MoveLPiece, game.getGameState());
}