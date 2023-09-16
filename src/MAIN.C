/*
===============================================
|SQUARE PRIMITIVES EXAMPLE FOR THE PLAYSTATION|
===============================================
*/

/*
===============================================
|			Uses primitives functions 	      |
|			 to make bouncing boxes  		  |
|											  |
|		     Boxes follow sin path			  |
===============================================
*/

#include <stdlib.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#include "square.h"
#include "constants.h"



/*
==============================================
|			Global Variables				 |
==============================================
*/

GsOT myOT[2];
GsOT_TAG myOT_TAG[2][1<<OT_LENGTH];
PACKET GPUPacketArena[2][PACKETMAX];

u_long	_ramsize	=	0x00200000;
u_long	_stacksize	=	0x00004000;

short CurrentBuffer	=	0;

typedef struct FVECTOR{
	float vx;
	float vy;
}FVECTOR;

/*
==============================================
|			Functions Prototypes			 |
============================================== 
*/

void graphics();
void display();
int random(int max);
float scaleDownRange(int value, int scale);
void setFVector(FVECTOR* vect, float vx, float vy);
int round(float value);


/*
==============================================
|				MAIN PROGRAM				 |
==============================================
*/

POLY_F4 f4[SQUARE_NB];

SQUARE square[SQUARE_NB];

int xvalue=0;
	
unsigned long ot[SQUARE_NB];


int main(){
	
	int i;
	int j;
	int frames = 0;
	
	
	FVECTOR velo;
	setFVector(&velo, HORIZONTAL_SPEED, 0);
	
	graphics();
	
	FntLoad(960,256);
	
	SetDumpFnt(FntOpen(5,20,SCREEN_WIDTH, SCREEN_HEIGHT, 0,512));
	
	for(i=0; i<SQUARE_NB;i++){
		initSQUARE(&square[i], SQUARE_SIZE);
		placeSQUARE(&square[i], (0+i*SQUARE_SIZE), 160);
		updateColorSQUARE(&square[i], random(256), random(256), 255);
	}
	FntOpen(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, 1, 255);

	while(frames<7200){
		FntPrint("EVOOOOOOOOOOOOOOOOOKE !!!!!!!!!!!!!!\n");
		if(frames>=1200){
			FntPrint("		My first shitty demo !\n");
		}
		if(frames>=2000){
			FntPrint("			LOVE THE PARTY\n");
		}
		if(frames>=3000){
			FntPrint("No sound because no time....\n");
			FntPrint("Made in a week and a half...\n");
		}
		j = 0;
		while(j<SQUARE_NB){
			if(xvalue>4096){
				xvalue=0;
			}
			else if(xvalue<0){
				xvalue=4096;
			}
			setFVector(&velo, HORIZONTAL_SPEED, scaleDownRange(csin((xvalue+(j*H_DIRECTION))*HEIGHT_SPEED), SPEED_RANGE));
			translateSQUARE_Horizontal(&square[j], round(velo.vx));
			translateSQUARE_Vertical(&square[j], round(velo.vy));
			
			j++;	
		}
		xvalue++;
		display();
		frames++;
	}
	graphics();
	return 0;	
}

/*
==============================================
|			Functions Definitions			 |
==============================================
*/

// Initialize graphics
void graphics(){
	int i;
	SetVideoMode(MODE_NTSC);
	
	GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsNONINTER|GsOFSGPU, 0, 0);
	GsDefDispBuff(0,0,0,SCREEN_HEIGHT);
	
	myOT[0].length	=	OT_LENGTH;
	myOT[1].length	=	OT_LENGTH;
	myOT[0].org		=	myOT_TAG[0];
	myOT[1].org		=	myOT_TAG[1];
	
	GsClearOt(0,0,&myOT[0]);
	GsClearOt(0,0,&myOT[1]);
	
	ClearOTagR(ot, SQUARE_NB);
	for(i=0; i<SQUARE_NB; i++){
		SetPolyF4(&f4[i]);
		addPrim(&ot[i], &f4[i]);
	}
	
	
}

// Place Primitives into OT, and display the frame buffer
void display() {
	
	
	int i;
	FntFlush(-1);
	for(i=0; i<SQUARE_NB; i++){
		setRGB0(&f4[i],square[i].red,square[i].green,square[i].blue);
		setXY4(&f4[i],square[i].x0,square[i].y0,square[i].x1,square[i].y1,square[i].x2,square[i].y2,square[i].x3,square[i].y3);
	
	}
	DrawOTag(ot+SQUARE_NB-1);
	
	CurrentBuffer	=	GsGetActiveBuff();
	
	GsSetWorkBase((PACKET*)GPUPacketArena[CurrentBuffer]);
	
	GsClearOt(0,0,&myOT[CurrentBuffer]);
	
	DrawSync(0);
	
	VSync(0);
	
	GsSwapDispBuff();
	
	GsSortClear(50,50,50,&myOT[CurrentBuffer]);
	
	GsDrawOt(&myOT[CurrentBuffer]);
}

// Generate a random number
int random(int max){
	srand((int)GsGetVcount());
	return (rand() % max);
}

// Scale a big range of number to a smaller one, retaining behaviour
float scaleDownRange(int value, int scale){
	float s_min = -(scale/2);
	float s_max = scale/2;
	
	float result = ( ((s_max-s_min)*(value - (-ONE) )) / (ONE - (-ONE)) ) + s_min;
	
	return result;
}

// Set a float vector
void setFVector(FVECTOR* vect, float vx, float vy){
	vect->vx = vx;
	vect->vy = vy;
}

// Round a float value to int with x.5+ => x+1 and x.4- => x
int round(float value){
	if(value>0){
		if(value<1){
			if(value>=0.5){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			if((value-(int)value)>=0.5){
				return (int)value+1;
			}
			else{
				return (int)value;
			}
		}
	}
	else if(value<0){
		if(value>-1){
			if(value<=-0.5){
				return -1;
			}
			else{
				return 0;
			}
		}
		else{
			if((value-(int)value)<=-0.5){
				return (int)value-1;
			}
			else{
				return (int)value;
			}
		}
	}
	return (int)value;
}
/*
===============================================
| This demo has been presented at Evoke 2023  |
|  Decided to open the source for everyone	  |
|											  |
|				© New Nova					  |
===============================================
*/