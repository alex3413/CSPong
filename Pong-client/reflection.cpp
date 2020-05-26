
#include "OGLPong.h"
reflection::reflection(float r ,float g ,float b){
		red = r; green = g; blue = b;
		vy=0;
		y = 0;
		up = false;
		down = false;
		hold = false;
	}
reflection::reflection(){
		red=1.0f; green=1.0f; blue=1.0f;
		vy=0;
		y = 0;
		up = false;
		down = false;
		hold = false;
	}

void reflection::draw(float r,float g,float b){
	red = r; green = g; blue = b;
	glColor3f(r,g,b);
	glVertex2f(x+settings.pThickness,y+size/2);
	glVertex2f(x+settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y+size/2);
}

void reflection::draw(){
	glColor3f(red,green,blue);
	glVertex2f(x+settings.pThickness,y+size/2);
	glVertex2f(x+settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y+size/2);
	
}
void reflection::move(){
	y +=vy;
	if(y < -settings.fieldSizeY + size/2){
		y = -settings.fieldSizeY + size/2;
		vy = 0;
	}
	if(y > settings.fieldSizeY - size/2){
		y = settings.fieldSizeY - size/2;
		vy = 0;
	}
}
void reflection::care(){
	if(hold){
		ball.vx = 0;
		if(x < 0)
			ball.x = x + 2*settings.pThickness;
		if(x > 0)
			ball.x = x - 2*settings.pThickness;
		ball.vy=vy;
		ball.y = y;
	}
}
