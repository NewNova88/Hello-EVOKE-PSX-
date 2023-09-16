#ifndef		_CONSTANTS_H_
#define		_CONSTANTS_H_

#define 	OT_LENGTH	 		1

#define 	PACKETMAX			18

#define		DEBUG				0

#define		MODE_NTSC			0
#define		MODE_PAL			1

#define 	SCREEN_WIDTH		320
#define 	SCREEN_HEIGHT		240


#define		SQUARE_SIZE			6
#define		SQUARE_NB			(SCREEN_WIDTH/SQUARE_SIZE)

/* 
=========================================================================
|	The higher the value, the bigger is the amplitude of the sinewave	|
=========================================================================
*/
#define		SPEED_RANGE			12

/* 
=========================================================================================
|	The higher the value, the faster the vector changes but it also means less height	|
=========================================================================================
*/
#define		HEIGHT_SPEED		10*SPEED_RANGE 
		
#define		HORIZONTAL_SPEED	2

#if HORIZONTAL_SPEED>0
	#define H_DIRECTION			1
#elif HORIZONTAL_SPEED<0
	#define H_DIRECTION			-1
#elif HORIZONTAL_SPEED==0
	#define H_DIRECTION			0
#endif

#endif
/*
===============================================
| This demo has been presented at Evoke 2023  |
|  Decided to open the source for everyone	  |
|											  |
|				© New Nova					  |
===============================================
*/
