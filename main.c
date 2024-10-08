#include "graphTe.h"
#include <stdio.h>
#include <stdlib.h>

float penSpeed=7;

//subprogram for refreshing the new board graphic
void refreshImage() 
{
	fill(rgb(0, 0, 0));
	image(0, 0, 1029, 843, "assets/etch.bmp");
}

//subprogram for the key inputs (movement and board reset)
void movePen(int* x, int* y) 
{
	if(checkKeyLiveInput(0x41))
		(*x) -= penSpeed;
	if(checkKeyLiveInput(0x44))
		(*x) += penSpeed;
	if(checkKeyLiveInput(0x57))
		(*y) -= penSpeed;
	if(checkKeyLiveInput(0x53))
		(*y) += penSpeed;
	if(checkKeyLiveInput(0x4B))
		refreshImage();
	Sleep(40);
} 

//main program
int main()
{
	int cursorX = 500, cursorY = 410, penWidth=5;
	const color cursorColor = rgb(0, 0, 0);
	POINT mPos;

	initHost();

	setWindowTitle("EtchASketch - Gabriel-Alex Ciocan");
	setWindowSize(1060, 880);
	update();

	refreshImage();

	menu:

	while(1)
	{
		//main menu mouse inputs
		mPos = getMousePosition();
		image(0, 0, 1029, 843, "assets/gameface.bmp");

		if(mPos.x >= 325 && mPos.x <= 700 && mPos.y >= 285 && mPos.y <= 345)
		{
			image(0, 0, 1029, 843, "assets/startgame.bmp");
			if(checkKeyLiveInput(VK_LBUTTON))
				break;
		}

		if(mPos.x >= 435 && mPos.x <= 585 && mPos.y >= 460 && mPos.y <= 520)
		{
			image(0, 0, 1029, 843, "assets/exitgame.bmp");
			if(checkKeyLiveInput(VK_LBUTTON))
				exit(0);	
		}
		display();
	}

	refreshImage();

	while(1)
	{
		//drawing
		rect(cursorX, cursorY, penWidth, penWidth, cursorColor);
		display();

		movePen(&cursorX, &cursorY);

		if(checkKeyLiveInput(VK_ESCAPE)) 
			goto menu;
	}
	
	releaseHost();
}