#pragma once
#pragma comment(lib, ws2_32.lib)
#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <winsock2.h>
void keyboardf(unsigned char, int,int);
void keyboardUpf(unsigned char, int,int);
void draw();
void Timer (int);
void mainSocket(int);

class reflection{
	public:
		float red, green, blue;
		float x,y;
		float vy;
		float size;
		bool up,down,hold;
	reflection(float ,float ,float);
	reflection();
	
	void draw(float ,float ,float );
	void draw();
	
	void move();
	void care();
};

class game{
	public:
	int orthoWid; // размеры координатной сетки
	int orthoHeid;
	
	int winWid; // размер окна
	int winHeid;
	
	int winXPos; // позиция окна
	int winYPos;
	
	float fieldSizeX; // размеры игрового поля
	float fieldSizeY;
	
	int delay; //временной тик шарика
	
	float pThickness;// толщина платформы
	float ballSize; // размер шарика
	float borderT; // толщина рамки поля
	float mLineT; // толщина линии посередине
	int scoreL; // количество очков игроков
	int scoreR;
	float textPosX; 
	float textPosY;
	float ballSpeedX; // скорость шарика по х
	float pSpeedY; // скорость платформ
	
	game(){
	orthoWid = 700; // размеры координатной сетки
	orthoHeid = 700;
	
	winWid = 700; // размер окна
	winHeid = 700;
	
	winXPos = 100; // позиция окна
	winYPos = 100;
	
	fieldSizeX = 600; // размеры игрового поля
	fieldSizeY = 400;
	
	delay = 1; //временной тик шарика
	
	pThickness = 10;// толщина платформы
	ballSize = 5; // размер шарика
	borderT = 10; // толщина рамки поля
	mLineT = 5; // толщина линии посередине
	scoreL = 0; // количество очков игроков
	scoreR = 0;
	textPosX = 0; 
	textPosY = fieldSizeY+10;
	ballSpeedX = 0.5; // скорость шарика по х
	pSpeedY = 1; // скорость платформ
	}
	void start_settings();
	void win();
	void keyControl();
	void keyReset();
	void drawField();
	void drawScore();
};
class Ball{
	public:
		float r,g,b;
		float x;
		float y;
		float vx;
		float vy;
	void move();
	void reflection();
	void draw();
};

extern game settings;
extern Ball ball ;
extern reflection leftP;
extern reflection rightP;










