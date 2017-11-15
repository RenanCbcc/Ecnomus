#include<iostream>
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

void main() {

	//intialize socket
	WSADATA wsDATA;
	WORD ver = MAKEWORD(2, 2);
	int wsOK = WSAStartup(ver, &wsDATA);

	if (wsOK != 0) {
		std::cout << "Cannot initialize the socket! QUITTING!" << std::endl;
		return;
	}
	//create a socket
	//In  Unix systens a socket is just a number, but in windows is a typer
	//socket(addres_family v4, I want a tcp connection, no flags);
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cout << "Cannot initialize the socket!	QUITTING!" << std::endl;
		return;

	}


	//bind the socket to ip address
	//I want to link socket and ip address
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(1984); // host to network short
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	//Tell the socket is for listening
	listen(listening, SOMAXCONN/*Number of maximum connections*/);

	//Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clienteSocket = accept(listening, (sockaddr*)&client, &clientSize); //Random socket that will be returnd for the client;

	if (clienteSocket == INVALID_SOCKET) {
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
	closesocket(listening);

	//while loop: accept and uppercase a message
	char buff[4096];
	while (true) {
		ZeroMemory(buff, 4096);
		// Wait for client to send data
		int bytesReceived = recv(clienteSocket, buff, 4096, 0);
		if (bytesReceived == SOCKET_ERROR) {
			std::cout << "Error in recv(). QUITTING" << std::endl;
			break;
		}

		if (bytesReceived == 0) {
			std::cout << "Client disconnected ;(" << std::endl;
			break;
		}
		//Process the instructions
		for (int i = 0; i < bytesReceived; i++)
		{
			buff[i] = toupper(buff[i]);
		}
		std::cout << sizeof(bytesReceived);
		send(clienteSocket, buff, bytesReceived + 1, 0);
	}
	//Close the socket
	closesocket(clienteSocket);

	//Clean up socket
	WSACleanup();

}

