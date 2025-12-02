// server.c - Windows-compatible server for MinGW/MSYS2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char *response = "Hello from Server!";
    int bytes_received;
    
    printf("=== TCP Server for Windows ===\n");
    
    // 1. Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Winsock initialized.\n");
    
    // 2. Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    printf("Socket created.\n");
    
    // 3. Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Listen on all interfaces
    server_addr.sin_port = htons(PORT);        // Convert port to network byte order
    
    // 4. Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    printf("Bind successful on port %d\n", PORT);
    
    // 5. Listen for connections
    if (listen(server_socket, 3) == SOCKET_ERROR) {
        printf("Listen failed: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    printf("Server listening...\n");
    printf("Waiting for client connection...\n");
    
    // 6. Accept connection
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
    if (client_socket == INVALID_SOCKET) {
        printf("Accept failed: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    printf("Client connected from: %s:%d\n", 
           inet_ntoa(client_addr.sin_addr), 
           ntohs(client_addr.sin_port));
    
    // 7. Receive message from client
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == SOCKET_ERROR) {
        printf("Receive failed: %d\n", WSAGetLastError());
    } else if (bytes_received == 0) {
        printf("Client disconnected.\n");
    } else {
        printf("Client says: %s\n", buffer);
        
        // 8. Send response
        send(client_socket, response, strlen(response), 0);
        printf("Response sent to client.\n");
    }
    
    // 9. Cleanup
    printf("Closing connections...\n");
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    printf("Server terminated.\n");
    
    return 0;
}