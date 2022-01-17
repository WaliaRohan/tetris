#include "Board.h"

/*
* Initiate all board blocks with free positions
*/
void Board::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			mBoard[i][j] = POS_FREE;
		}
}


/*
* Store a piece in the board by filling the blocks on the board
* 
* Parameters:
* 
*	pX:			Horizontal position (in blocks) on board
*	pY:			Vertical position (in blocks) on board
*	pPiece:		Piece to create on board
*	pRotataion:	1 of 4 possible rotation values
*/
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
	// Store each block of the piece into the board
	// first iterators (i1, j1) keep track of where each block from piece will go on the board
	// second iterators (i2, j2) help in avoiding empty blocks from the mPieces matrix
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Store only the blocks from pieces that are not empty
			if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
				mBoard[i1][j1] = POS_FILLED;
		}
	}
}

/*
* Game is over if a piece reaches to the top of the board
* 
* Returns true if game is over, false otherwise
* 
*/
bool Board::IsGameOver()
{
	// Only need to check rows in the board
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return true; 
	}

	return false;
}

/*
* Delete a line of the board by removing all above lines above it
* 
* Parameters:
* 
*	pY:	Vertical position of the line to delete (in blocks)
*/
void Board::DeleteLine(int pY)
{
	// Move all upper lines one row down
	for (int j = pY; j > 0; j--) // experiment with j >= 0;
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			mBoard[i][j] = mBoard[i][j - 1]; // experiment with mBoard[i][j - 1] = mBoard[i][j];
		}
	}
}

/*
* Check and delete all lines that should be removed
*/
void Board::DeletePossibleLines()
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}

		if (i == BOARD_WIDTH) DeleteLine(j);
	}
}

bool Board::IsFreeBlock(int pX, int pY)
{
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	else
		return false;
}