#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc < 4) {
        printf("usage: %s IPv4 first_port last_port\n", argv[0]);
        exit(1);
    }

    char* IPv4 = argv[1];
    int port_start = atoi(argv[2]);
    int port_end = atoi(argv[3]);
    
    int socket_fd;
    struct sockaddr_in socket_address;
    int status;

    memset(&socket_address, 0, sizeof(struct sockaddr_in));
    socket_address.sin_family = AF_INET;
    if (inet_pton(AF_INET, IPv4, &socket_address.sin_addr) <= 0) {
        printf("invalid addr\n");
        exit(1);
    }


    for (int port = port_start; port <= port_end; ++port) {
        if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("error creating socket\n");
            exit(1);
        }
        socket_address.sin_port = htons(port);
        status = connect(socket_fd, (struct sockaddr*)&socket_address, sizeof(socket_address));
        printf("scanning port %d: open\n");
        close(socket_fd);
    }
}
