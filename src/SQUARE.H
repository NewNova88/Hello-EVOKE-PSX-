#ifndef		_SQUARE_H_
#define		_SQUARE_H_

/*
========================================================
|				Basic SQUARE structure				   |
|	Follow in-code comments to know the organisation   |
|													   |
========================================================
*/
typedef struct SQUARE{
	// TOP LEFT
	int x0;
	int y0;
	//TOP RIGHT
	int x1;
	int y1;
	// DOWN LEFT
	int x2;
	int y2;
	// DOWN RIGHT
	int x3;
	int y3;
	
	// COLOR
	int red;
	int green;
	int blue;
	
	// SIZE INFO
	int size;
}SQUARE;

/*
========================================================
|		Initialize a SQUARE with a given size		   |
|		  to position 0,0 (top left point)			   |
========================================================
*/
void initSQUARE(SQUARE* square, int size);

/*
========================================================
|	  Change the position and color of a SQUARE		   |
========================================================
*/
void updateSQUARE(SQUARE* square,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int red,int green,int blue);

/*
========================================================
|		   Change only the color of a SQUARE		   |
========================================================
*/
void updateColorSQUARE(SQUARE* square, int red, int green, int blue);

/*
========================================================
|	  Move a SQUARE horizontally with a given value    |
|			  The value can be negative				   |
|													   |
|	    Wraps up when the SQUARE go past screen		   |
========================================================
*/
void translateSQUARE_Horizontal(SQUARE* square,int value);

/*
========================================================
|	  Move a SQUARE vertically with a given value	   |
|			   The value can be negative			   |
|													   |
|		Wraps up when the SQUARE go past screen		   |
========================================================
*/
void translateSQUARE_Vertical(SQUARE* square,int value);

/*
========================================================
|		 Place a SQUARE to a given position			   |
|	 	 Point of positionn is the TOP LEFT			   |
========================================================
*/
void placeSQUARE(SQUARE* square, int x, int y);

#endif
/*
===============================================
| This demo has been presented at Evoke 2023  |
|  Decided to open the source for everyone	  |
|											  |
|				© New Nova					  |
===============================================
*/
