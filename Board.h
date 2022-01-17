#pragma once

#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_LINE_WIDTH			// Width of the lines on either size of the board (left and right)
#define BLOCK_SIZE 16				// Width and height of each block on the board
#define BOARD_POSITION 320			// Board center position from left of the screen
#define BOARD_WIDTH 10				// Board width in blocks
#define BOARD_HEIGHT 29				// Board height in blocks
#define MIN_VERTICAL_MARGIN 20		// Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20	// Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5				// Max number of horizontal and vertical blocks that can be used by a piece (I, L, N etc.)

class Board
{
public:
	Board(Pieces* pPieces, int pScreenHeight);

	int GetXPosInPixels(int pPos);
	int GetYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsMovementPossible(int pX, int pY, int pPiece, int pRotataion);
	void StorePiece(int pX, int pY, int pPiece, int pRotataion);
	void DeletePossibleLines();
	bool IsGameOver ();

private:

	enum {POS_FREE, POS_FILLED};			// POS_FREE = free position (block) on board, POS_FILLED = Filled position (block) on board
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];	// Variable to track positions on board (free/filled)
	Pieces* mPieces;
	int mScreenHeight;

	void InitBoard();
	void DeleteLine(int pY);
};













#endif
