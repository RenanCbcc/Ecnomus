
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

/*
1.Initialize Winsock.
2.Create a socket.
3.Connect to the server.
4.Send and receive data.
5.Disconnect.*/
void ain() {
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
	char buffer[512];
	std::string userInput;
	do {
		std::cout << std::endl << "Your turn. Enter co-ordinates x,y";
		std::cin >> userInput;

		if (userInput.size()>0) {
			//Send it
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				//Wait for response
				ZeroMemory(buffer, 512);
				int bytesReceived = recv(sock, buffer, 512, 0);
				if (bytesReceived > 0) {
					std::cout << "SERVER>" << std::string(buffer, 0, bytesReceived) << std::endl;
				}
			}
		}
	} while (userInput.size()>0);

	//5.Disconnect.
	closesocket(sock);
	WSACleanup();

}