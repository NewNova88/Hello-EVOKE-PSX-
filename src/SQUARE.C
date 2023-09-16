#include "square.h"
#include "constants.h"

void initSQUARE(SQUARE* square, int size){
	// TOP LEFT
	square->x0=0;
	square->y0=0;
	// TOP RIGHT
	square->x1=size;
	square->y1=0;
	// DOWN LEFT
	square->x2=0;
	square->y2=size;
	// DOWN RIGHT
	square->x3=size;
	square->y3=size;
	
	// COLOR
	square->red=255;
	square->green=255;
	square->blue=255;
	
	square->size=size;
}
void updateSQUARE(SQUARE* square,int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int red,int green,int blue){
	// TOP LEFT
	square->x0=x0;
	square->y0=y0;
	// TOP RIGHT
	square->x1=x1;
	square->y1=y1;
	// DOWN LEFT
	square->x2=x2;
	square->y2=y2;
	// DOWN RIGHT
	square->x3=x3;
	square->y3=y3;
	
	// COLOR
	square->red=red;
	square->green=green;
	square->blue=blue;
}
void updateColorSQUARE(SQUARE* square, int red, int green, int blue){
	square->red = red;
	square->green = green;
	square->blue = blue;
}
void translateSQUARE_Horizontal(SQUARE* square,int value){
	if(value>0){
		if(square->x0>=SCREEN_WIDTH){
			square->x0=0-square->size;
			square->x1=0;
			square->x2=0-square->size;
			square->x3=0;
		}
	}
	else if(value<0){
		if(square->x1<=0){
			square->x0=SCREEN_WIDTH;
			square->x1=SCREEN_WIDTH+square->size;
			square->x2=SCREEN_WIDTH;
			square->x3=SCREEN_WIDTH+square->size;
		}
	}
	square->x0+=value;
	square->x1+=value;
	square->x2+=value;
	square->x3+=value;
}	
void translateSQUARE_Vertical(SQUARE* square,int value){
	if(value>0){
		if(square->y0>=SCREEN_HEIGHT){
			square->y0=0-square->size;
			square->y1=0-square->size;
			square->y2=0;
			square->y3=0;
		}
	}
	else if(value<0){
		if(square->y2<=0){
			square->y0=SCREEN_HEIGHT;
			square->y1=SCREEN_HEIGHT;
			square->y2=SCREEN_HEIGHT+square->size;
			square->y3=SCREEN_HEIGHT+square->size;
		}
	}
	square->y0+=value;
	square->y1+=value;
	square->y2+=value;
	square->y3+=value;	
}
void placeSQUARE(SQUARE* square, int x, int y){
	updateSQUARE(
		square,
		x,y,
		x+square->size,y,
		x,y+square->size,
		x+square->size,y+square->size,
		square->red,square->green,square->blue
	);
}
/*
===============================================
| This demo has been presented at Evoke 2023  |
|  Decided to open the source for everyone	  |
|											  |
|				© New Nova					  |
===============================================
*/
