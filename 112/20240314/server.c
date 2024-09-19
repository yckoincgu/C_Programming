#include <stdio.h>
#include <winsock2.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int client_len = sizeof(client);
    char buffer[MAX_BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Listen
    listen(server_socket, 3);

    // Accept an incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr*)&client, &client_len)) == INVALID_SOCKET) {
        printf("Accept failed.\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Actual communication
    int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    send(client_socket, buffer, bytes_received, 0);
    printf("Message from client: %s\n", buffer);

    closesocket(server_socket);
    closesocket(client_socket);
    WSACleanup();
    return 0;
}

