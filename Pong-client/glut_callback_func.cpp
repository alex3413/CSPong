
#include "OGLPong.h"
void keyboardf(unsigned char key, int x,int y){
	switch(key){
		case 'q':
			leftP.up = true;
			break;
		case 'a':
			leftP.down = true;
		case 'z':
			if(leftP.hold){
				leftP.hold=false;
				ball.vx = settings.ballSpeedX;
			}
			break;
			
		case 'p':
			rightP.up = true;
		//	std::cout<<rightP.y<<std::endl;
			break;
		case 'l':
			rightP.down = true;
		//	std::cout<<rightP.y<<std::endl;
		case 'm':
			if(rightP.hold){
				rightP.hold=false;
				ball.vx = -settings.ballSpeedX;
			}
			break;
	}
}
void keyboardUpf(unsigned char key, int x,int y){
	switch (key){
		case 'q':
			leftP.up = false;
			break;
		case 'a':
			leftP.down = false;
			break;
			
			
		case 'p':
			rightP.up = false;
			break;
		case 'l':
			rightP.down = false;
			break;
	}
	
}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		rightP.draw(1,0,0);
		leftP.draw(0,1,0);
		ball.draw();
		settings.drawField();
	glEnd();
	settings.drawScore();
	glutSwapBuffers();
	
}
void Timer (int value){
 settings.win();
 settings.keyControl();
 leftP.move();
 rightP.move();
 ball.move();
 ball.reflection();
 leftP.care();
 rightP.care();
 settings.keyReset();
 glutPostRedisplay();
 glutTimerFunc(settings.delay,&Timer,0);
 
}




