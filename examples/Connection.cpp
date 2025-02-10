#define WIN32_LEAN_AND_MEAN

#include "Connection.h"
#include "Logging.h"

#include <sstream>
#include <cstring>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

using namespace Example;


void Connection::Connect(unsigned int port, const std::string& host, bool listening)
{
    WSADATA wsaData;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_UDP;

    // Initialize Winsock
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        return;
    }
    
    iResult = getaddrinfo(host.c_str(), std::to_string(port).c_str(), &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        mSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (mSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return;
        }

        // Connect to server.
        iResult = connect(mSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(mSocket);
            mSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (mSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return;
    }
}

void Connection::Disconnect()
{
    // shutdown the connection since no more data will be sent
    int iResult = shutdown(mSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(mSocket);
        WSACleanup();
        return;
    }
}

void Connection::Send(const char* buf, size_t numbytes)
{
   if( numbytes < 1 )
   {
      return;
   }

    int iResult = send( mSocket, buf, numbytes, 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(mSocket);
        WSACleanup();
        return;
    }
}

size_t Connection::Receive(char* buf)
{
    char recvbuf[512];
    int recvbuflen = 0;
    int iResult = recv(mSocket, recvbuf, recvbuflen, 0);
    if ( recvbuflen > 0 )
   	memcpy(buf, recvbuf, recvbuflen);
   return recvbuflen;
}

