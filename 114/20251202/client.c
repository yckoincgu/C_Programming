// client.c - Windows-compatible client for MinGW/MSYS2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Hello from Client!";
    int bytes_received;
    
    printf("=== TCP Client for Windows ===\n");
    
    // 1. Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Winsock initialized.\n");
    
    // 2. Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    printf("Socket created.\n");
    
    // 3. Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);
    
    // 4. Connect to server
    printf("Connecting to server %s:%d...\n", SERVER_IP, PORT);
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed: %d\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }
    printf("Connected to server!\n");
    
    // 5. Send message
    printf("Sending message: %s\n", message);
    if (send(client_socket, message, strlen(message), 0) < 0) {
        printf("Send failed: %d\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }
    
    // 6. Receive response
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == SOCKET_ERROR) {
        printf("Receive failed: %d\n", WSAGetLastError());
    } else if (bytes_received == 0) {
        printf("Server disconnected.\n");
    } else {
        printf("Server response: %s\n", buffer);
    }
    
    // 7. Cleanup
    closesocket(client_socket);
    WSACleanup();
    printf("Client terminated.\n");
    
    return 0;
}