#include<iostream>
#include "BusinessLogic.h"
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

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
	char buffer[512];
	BusinessLogic battleship;
	battleship.print();
	while (true)
	{
		ZeroMemory(buffer, 512);

		// Wait for client to send data
		int bytesRecieved = recv(clientSocket, buffer, 512, 0);
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

		std::string answer = battleship.onSendCoordinateSquare(buffer[0]-'0', buffer[2] - '0');
		battleship.print();
		char response[sizeof(answer) + 1];
		strcpy(response, answer.c_str());
		send(clientSocket, response, answer.length() + 1, 0);
		
		std::cout << std::endl << "Bot turn. Enter co-ordinates x,y";

	}

	// Close
	closesocket(clientSocket);

	// Cleanup Winsock
	WSACleanup();
}

