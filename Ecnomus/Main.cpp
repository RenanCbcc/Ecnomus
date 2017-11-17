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


#define DEFAULT_MSGBUFFLEN 512
#define DEFAULT_COMBUFFLEN 2
#define DEFAULT_PORT 1984


void nain() {

	//intialize socket
	WSADATA wsaData;
	int iResult;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	WORD ver = MAKEWORD(2, 2);
	
	iResult = WSAStartup(ver, &wsaData);

	
	if (iResult = WSAStartup(ver, &wsaData)!= 0) {
		std::cout << "Cannot initialize the socket! QUITTING!" << std::endl;
		return;
	}
	//create a socket
	//In  Unix systens a socket is just a number, but in windows is a typer
	//socket(addres_family v4, I want a tcp connection, no flags);
	ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenSocket == INVALID_SOCKET) {
		std::cout << "Cannot initialize the socket!	QUITTING!" << std::endl;
		return;

	}


	//bind the socket to ip address
	//I want to link socket and ip address
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(DEFAULT_PORT); // host to network short
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(ListenSocket, (sockaddr*)&hint, sizeof(hint));

	//Tell the socket is for listening
	listen(ListenSocket, SOMAXCONN/*Number of maximum connections*/);

	//Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	ClientSocket = accept(ListenSocket, (sockaddr*)&client, &clientSize); //Random socket that will be returnd for the client;

	if (ClientSocket == INVALID_SOCKET) {
		std::cout << "Cannot initialize the socket!	QUITTING!" << std::endl;
		return;

	}

	char host[NI_MAXHOST];// remote name of the client.
	char service[NI_MAXSERV];

	ZeroMemory(host, NI_MAXHOST); // set memory.
	ZeroMemory(service, NI_MAXSERV);
	//check if we can get any infomation
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		std::cout << host << " connected on port " << service << std::endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " <<
			ntohs(client.sin_port) << std::endl;
	}
	//Close listening socket, i do not expect another clients.
	closesocket(ListenSocket);

	BusinessLogic battleship;
	char buff[DEFAULT_MSGBUFFLEN];
	char request[] = {"Send corordenates X and Y"};
	//while loop: accept and uppercase a message
	while (true) {
		ZeroMemory(buff, DEFAULT_MSGBUFFLEN);

		send(ClientSocket, request, sizeof(request)+1, 0);
		// Wait for client to send data
		iResult = recv(ClientSocket, buff, 4096, 0);
		if (iResult == SOCKET_ERROR) {
			std::cout << "Error in recv(). QUITTING" << std::endl;
			break;
		}

		if (iResult == 0) {
			std::cout << "Client disconnected ;(" << std::endl;
			break;
		}
		//Process the instructions
		battleship.print();
		std::string answer = battleship.onSendCoordinateSquare(buff[0], buff[1]);
		char response[sizeof(answer)+1];
		strcpy(response, answer.c_str());
		
		send(ClientSocket, response, sizeof(response) + 1, 0);
	}
	//Close the socket
	closesocket(ClientSocket);

	//Clean up socket
	WSACleanup();

}

