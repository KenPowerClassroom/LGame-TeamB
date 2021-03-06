#include "pch.h"
#include "../LGame/Game.h"
#include "MockInput.h"
#include "MockRenderer.h"

TEST(Input, ContinueGameStateTest)
{
    // Create mock classes to satisfy the game Default constucter
    MockInput input; 
    MockRenderer renderer;

    Game game(input, renderer); // Create a Game object

    input.m_continue = true; // Set the continue input to true
    
    // Check the game is in the right state to begin with
    EXPECT_EQ(GameState::View, game.getGameState());

    // Update the game state with the continue button pressed in the input object
    game.updateGameState(&input);

    // Check that the game state has changed correctly
    EXPECT_EQ(GameState::MoveLPiece, game.getGameState());
}