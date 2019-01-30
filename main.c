#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 4) {
        printf("usage: %s IPv4 first_port last_port\n", argv[0]);
        exit(1);
    }

}
