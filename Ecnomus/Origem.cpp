#include "BusinessLogic.h"
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

struct Packet
{
	int x, y, length;
	char *msg;

};

/*
1.Initialize Winsock.
2.Create a socket.
3.Connect to the server.
4.Send and receive data.
5.Disconnect.*/

//Put this file in another window of visual studio and run it after the Server.
void nain() {
	std::string ipaddress = "127.0.0.1";
	int port = 54000;

	//1.Initialize Winsock.
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) {
		std::cout << "Cannot start wisock. Erro #" << wsResult << std::endl;
	}

	//2.Create a socket.
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		std::cout << "Cannot create socket. Erro #" << WSAGetLastError() << std::endl;
		WSACleanup();
		return;
	}
	//Fill in a hint structure in order to tell winsock what port to connect it.
	sockaddr_in hint = { AF_INET,htons(port) };
	inet_pton(AF_INET, ipaddress.c_str(), &hint.sin_addr);

	//3.Connect to the server.
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR) {
		std::cout << "Cannot create socket. Erro #" << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
	//4.Send and receive data.
	char buffer[sizeof(Packet)];
	Packet msg;
	BusinessLogic playerBoard;
	playerBoard.print();

	do {
		std::cout << std::endl << "Your turn. Enter co-ordinates x (enter) y (enter)" << std::endl;
		std::cin >> msg.x >> msg.y;

		if (msg.x> 0 && msg.y > 0) {
			//Send it

			char* tmp = reinterpret_cast<char*>(&msg);
			int sendResult = send(sock, tmp, sizeof(Packet) + 1, 0);

			if (sendResult != SOCKET_ERROR)
			{
				//Wait for response
				ZeroMemory(buffer, sizeof(Packet));

				int bytesReceived = recv(sock, buffer, sizeof(Packet), 0);
				Packet *response = reinterpret_cast<Packet*>(buffer);
				if (bytesReceived > 0) {
					std::cout << "Bot turn>>" << std::endl;
					std::cout << "X >" << response->x << " Y >" << response->y << std::endl;
					std::cout << "Result: " << playerBoard.onSendCoordinateSquare(response->x, response->y) << std::endl;
					playerBoard.print();
				}
			}

		}
	} while (msg.x> 0 && msg.y > 0);

	//5.Disconnect.
	closesocket(sock);
	WSACleanup();

}