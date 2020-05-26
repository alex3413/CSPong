//#pragma once
#include "OGLPong.h"
void game::start_settings(){
	leftP.size = 200;
 	rightP.size = 200;
 	leftP.x= -510;
 	rightP.x = 510;
 //while(ball.vx == 0)
 //	ball.vx = (rand()%3 - 1)*ballSpeedX;
 	
 	ball.x = 0;
 	ball.y = 0;
 	ball.vy = 0;
 	
 	ball.r = 1; ball.g = 1; ball.b = 1;
 }
 void game::win(){
 	if((scoreL == 8)||(scoreR == 8)){
 		glutTimerFunc(2000,exit,0);
		settings.delay = 10000;
 	}
 if(ball.x < leftP.x + pThickness - ballSpeedX){
 //	start_settings();
 	rightP.hold = true;
 	scoreR++;
 }
 if(ball.x > rightP.x - pThickness + ballSpeedX){
 // start_settings();
 	leftP.hold = true;
 	scoreL++;
 }
}
 void game::keyControl(){
 	if((leftP.up) && (!leftP.down))
 		leftP.vy = pSpeedY;
 		
 	if((!leftP.up) && (leftP.down))
 		leftP.vy = -pSpeedY;
 		
 	if((rightP.up) && (!rightP.down))
 		rightP.vy = pSpeedY;
 		
 	if((!rightP.up) && (rightP.down))
 		rightP.vy = -pSpeedY;
 }
 void game::keyReset(){
 leftP.vy = 0;
 rightP.vy = 0;
 }
 void game::drawField(){
 glColor3f(1,1,1);
 glVertex2f(-fieldSizeX - borderT, -fieldSizeY - borderT);
 glVertex2f(fieldSizeX + borderT, -fieldSizeY - borderT);
 glVertex2f(fieldSizeX + borderT, -fieldSizeY);
 glVertex2f(-fieldSizeX - borderT, -fieldSizeY);
 glVertex2f(-fieldSizeX - borderT, fieldSizeY + borderT);
 glVertex2f(fieldSizeX + borderT, fieldSizeY + borderT);
 glVertex2f(fieldSizeX + borderT, fieldSizeY);
 glVertex2f(-fieldSizeX - borderT, fieldSizeY);

 glVertex2f(-fieldSizeX - borderT, -fieldSizeY - borderT);
 glVertex2f(-fieldSizeX, -fieldSizeY - borderT);
 glVertex2f(-fieldSizeX, fieldSizeY + borderT);
 glVertex2f(-fieldSizeX - borderT, fieldSizeY + borderT);

 glVertex2f(fieldSizeX, -fieldSizeY - borderT);
 glVertex2f(fieldSizeX + borderT, -fieldSizeY - borderT);
 glVertex2f(fieldSizeX + borderT, fieldSizeY + borderT);
 glVertex2f(fieldSizeX, fieldSizeY + borderT);
	
	glColor3f(ball.r, ball.g, ball.b);
 for(float i = -fieldSizeY; i <= fieldSizeY; i+=4*mLineT){
 glVertex2f(-mLineT, i + mLineT);
 glVertex2f(mLineT, i + mLineT);
 glVertex2f(mLineT, i - mLineT);
 glVertex2f(-mLineT, i - mLineT);
 }
 }
 void game::drawScore(){
 	glRasterPos2f(textPosX - 50, textPosY +20);
 	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + scoreL);

 glRasterPos2f(textPosX +30, textPosY +20);
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + scoreR);

 if(scoreL == 8){
	 glRasterPos2f(textPosX - 200, textPosY +40);
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
 }
 
 if(scoreR == 8){
	 glRasterPos2f(textPosX + 150, textPosY +40);
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
 }


 }



