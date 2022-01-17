#include "pieces.h"

/**
* Returns the block type of the piece (0 = no block, 1 = normal block, 2 = pivot block) -> Definition in Readme file
  Parameters:
* pPiece: piece to draw
* pRotataion: orientation (out of 4 possible values -> up, down, left, right)
* pX: Horizontal position of the block
* pY: Vertical position of the block
*/
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
	return mPieces[pPiece][pRotation][pX][pY];
}

/**
*Returns the horizontal displacement of a piece
 Parameters:
* pPiece: piece to be drawn
* pRotation: orientation (out of 4 possible values -> up, down, left, right)
*/
int Pieces::GetXInitialPosition(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][0];
}

/**
* Returns the vertical displacement of a piece
  Parameters:
* pPiece: piece to be drawn
* pRotation: orientation (out of 4 possible values -> up, down, left, right)
*/

int Pieces::getYInitialPosition(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][1];
}

