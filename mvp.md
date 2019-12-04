# Minimal Viable Product (MVP) 

## Outline MVP functionality

The game displays a 4x4 grid of squares, in which there are 4 pieces; two coins (1x1) and two L pieces (an L shape within a 3x2 space). Each player gets 1 L piece, though the coins are shared between both.

The game displays the visuals though SFML, using rectangle shapes to form the pieces. One L piece is red, while the other is blue. The coins are drawn in black. 

The game has two players and moves in turns, with each player getting to move their L piece to any place on the board, with any 90 degree rotation, per turn, as long as the piece does not overlap any other pieces. Once the player has moved their L piece, they have the option of moving the coin to any spot on the board as long as it does not overlap another piece, then the turn ends.

The game uses keyboard input to move the pieces, with the arrow keys to position the pieces (moving tile by tile around the board) and the R key, used to rotate the L pieces by 90 degrees clockwise.

## List the features of the MVP
- Board and pieces are drawn to screen.
- The pieces can move around the board with keyboard input.
- The pieces should not be able to overlap other pieces.

## Out Of Scope

Ideally the game would include a winning condition check, in which when a player can no longer make any moves without overlapping another piece, the game is won by the previous player.
The game would also include a text that displays to the player the number of possible moves at the beginning of each turn.

The game would also include sound and visual visual effects for moving pieces, along with textures for the pieces and board, and music.


## List of stories needed to complete the MVP

### **Flip**

As the player, I want to be able to flip the pieces so that I can place it in more positions.

This should be controlled by a key press event, and will result in the L-piece being flipped along its y-axis. ( |_ to _| )

If the player holds the key, the piece should only be flipped once.

### **Rotate**

As the player, I want to be able to rotate my L-piece so that I can place it in more positions.

This should be controlled by key press events, and will result in the L-piece being instantly rotated clockwise by 90 degrees.

If the player holds the key, the piece should only be rotated once.

### **Ownership**

As the player, I want to have ownership as a piece so that the other player cannot move it.

I will only be able to move my piece during my turn and I will not be able to move the other piece

### **Turns**

As the game, I want to be able to keep track of turns so I can delegate input responsibilities to the correct player.

The turns will be changed once the player has updated his L-piece and decided if they wish to move the neutral piece. 

### **Validate Move**

As the game, I want to ensure a players move is legal (does not overlap an existing piece, and stays within the bounds of the board).

### **Movement**

As the player, I want to be able to move my pieces so that I can change the state of the game.

This should be achieved by taking arrow key input from the keyboard, and moving the pieces up/down/left/right by one cell.

Once the piece has been moved to the desired position, the player will press a key (e.g. Spacebar) to confirm their move.

Checking if this move is possible will be delegated to the 'Validate Move' story.

### **Render**

As the player, I want to be able to perceive the state of the game board so that I can make an informed decision on where to put my piece/s.

### **Board**

As the player, I want to know where the existing pieces are, so that I can decide where I can put my pieces.
This should be achieved by drawing the board and pieces, in their positions, to an SFML render window.

### **Check for possible move**

As the game, I want to know if at least one legal move is possible so that I can determine whether one player has lost.

I will have to read from the board and check if the current player can move his piece by looping around all the points on the board and finding out if it can be placed there by checking surrounding tiles. If I find one possible solution i will stop searching and the game is not over.
