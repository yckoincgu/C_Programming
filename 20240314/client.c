#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") 

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    // Actual communication
    char message[] = "Hello from client";
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    printf("Message from server: %s\n", buffer);

    closesocket(client_socket);
    WSACleanup();
    return 0;
}

