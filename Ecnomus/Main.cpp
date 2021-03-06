﻿#include <iostream>
#include "BusinessLogic.h"
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

struct Packet
{
	int x, y, length;
	char *msg;
	
};
/*
1.Initialize Winsock.
2.Create a socket.
3.Bind the socket.
4.Listen on the socket for a client.
5.Accept a connection from a client.
6.Receive and send data.
7.Disconnect.
*/

using namespace std;

void main() {

	// Initialize Winsock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &data);
	if (wsOk != 0)
	{
		cerr << "Can't start winsock! Tactical Retreat!" << endl;
		return;
	}

	// Create socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Couldn't create socket!" << endl;
		return;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // or inet_pton

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	//Tell winsock the socket is for listening
	listen(listening, SOMAXCONN);

	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];  // Client's remote name
	char service[NI_MAXHOST]; // Service (i.e port)

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << " connected on port " << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port" <<
			htons(client.sin_port) << endl;
	}

	// Close listening socket
	closesocket(listening);
	cout << "Server created!" << endl << "Waiting for a Player..." << endl;

	// While loop: accept and echo message back to client
	BusinessLogic opponentBoard;
	char buffer[sizeof(Packet)];
	opponentBoard.print();
	while (true)
	{
		ZeroMemory(buffer, sizeof(Packet));

		// Wait for client to send data
		int bytesRecieved = recv(clientSocket, buffer, sizeof(Packet), 0);
		if (bytesRecieved == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesRecieved == 0)
		{
			cout << "client disconnected " << endl;
			break;
		}

		Packet *msgrcv = reinterpret_cast<Packet*>(buffer);
		std::string result  = opponentBoard.onSendCoordinateSquare(msgrcv->x, msgrcv->y);
		
		std::cout << "Player sent>>" << std::endl;
		std::cout << "X >" << msgrcv->x << " Y >" << msgrcv->y << std::endl;
		std::cout <<"Result on Bot bord: "<<  result << std::endl;
		
		Packet packet;
		char response_ptr[sizeof(result) + 1];
		strcpy(response_ptr, result.c_str());
		packet.msg = response_ptr;		
		packet.length = result.length();
		
	
		std::cout << std::endl << "Bot turn. Enter coordinates x (enter) y (enter)" << std::endl;
		std::cin >> packet.x >> packet.y;

		char* tmp = reinterpret_cast<char*>(&packet);
		int sendResult = send(clientSocket, tmp, sizeof(packet) + 1, 0);
		if (sendResult != SOCKET_ERROR)
		{
			std::cout << "Player turn>>" << std::endl;

		}
	}

	// Close
	closesocket(clientSocket);

	// Cleanup Winsock
	WSACleanup();
}

