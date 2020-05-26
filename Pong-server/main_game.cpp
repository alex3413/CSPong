
#include "OGLPong.h"

void Hide(){
  HWND Hide;
  AllocConsole(); 
  Hide = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Hide,0);
}
game settings;
Ball ball ;
reflection leftP;
reflection rightP;

int main(int argc, char** argv) {
	
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2,1);
	if(WSAStartup(DLLVersion, &wsaData) != 0){
		std::cout<<"Error WSA Startup\n";
	}
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	settings.start_settings();
	glutInitWindowPosition (settings.winXPos,settings.winYPos);
	glutInitWindowSize(settings.winWid, settings.winHeid);
	glutCreateWindow("Ping_POng");
	glutDisplayFunc(draw);
	glutTimerFunc(settings.delay, &Timer, 0);
	//glutTimerFunc(1000, &mainSocket, 1);
	glutKeyboardFunc(keyboardf);
	glutKeyboardUpFunc(keyboardUpf);
	glClearColor(0,0,0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-settings.orthoWid, settings.orthoWid, -settings.orthoHeid, settings.orthoHeid);
	//Hide();
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)mainSocket,(LPVOID)(1), NULL, NULL);
	glutMainLoop();
	
	return 0;
}
