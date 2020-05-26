#include "OGLPong.h"
using namespace std;
struct Coord{
	int x;
	int y;
	int pl;
};
void clientHandler(SOCKET, SOCKADDR_IN&);

void mainSocket(int value){
	
	int port = 1234;
	SOCKADDR_IN address;
	address.sin_addr.s_addr = inet_addr("172.29.74.60");
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	
	SOCKET gameSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	DWORD nonblock = 1;
	if(ioctlsocket(gameSocket, FIONBIO, &nonblock) != 0){
		cout<<"Failed non blocking socket"<<endl;
	}
	
	clientHandler(gameSocket, address);
	closesocket(gameSocket);
//	glutTimerFunc(1, &mainSocket, 1);
}

void clientHandler(SOCKET sockett, SOCKADDR_IN &address){
	SOCKET sock = sockett;
	Coord coo;
	coo.x = 0;
	int cooSize = sizeof(coo);
	char msg[64] = "OK";
	int coordYrightP=0;
	int coordYleftP=0;
	int ballX;
	int ballY;
	while(true){
		char packet[256];
		int sizePacket = sizeof(packet);
		SOCKADDR_IN from;
		int fromL = sizeof(from);
		
		int err = recvfrom(sock, (char*)&coo, cooSize,0,0,0);
	//	err = recvfrom(sock, (char*)&ballX, sizeof(int),0,0,0);
	//	err = recvfrom(sock, (char*)&ballY, sizeof(int),0,0,0);
	//	int receive = recvfrom(sock, (char*)&coordYleftP, sizeof(int), 0, (SOCKADDR*)&from, &fromL);
		if(err < 0 ){
		//	cout<<"Failed recv : "<<WSAGetLastError()<<endl;
		}
	//	leftP.y = coo.pl;
	//	ball.x = coo.x;
	//	ball.y = coo.y;
		leftP.up = leftP.down = true;
		leftP.y = coo.pl;
		ball.x = coo.x;
		ball.y = coo.y;
		coordYrightP = rightP.y;
		cout<<"CoordY = "<<coo.pl<<"; rightP.y = "<<coo.y<<"; right.x = "<<coo.x<<endl;
		Sleep(100);
		
		//sendto(sock, (char*)&coordYleftP, sizeof(int), 0, (SOCKADDR*)&from, fromL);
		int sendBytes = sendto(sock, (char*)&coordYrightP, sizeof(int), 0, (SOCKADDR*)&address, sizeof(SOCKADDR_IN));
		
		if(sendBytes != sizeof(int)){
			cout<<"Failed sendBytes "<<sendBytes<<endl;
		}
		
		int fromPort = ntohs(from.sin_port);
		//cout<<coordY<<endl;
	}
}
