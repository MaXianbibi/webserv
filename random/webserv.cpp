#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>



bool g_continue = true;

int sighandler(int signum)
{
    (void)signum;
    g_continue = false;
    return 1;
}

void fatal(const char* msg) 
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main()
{
    while(1){
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener == -1)
        fatal("socket");

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080)
    };
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listener, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0)
        fatal("bind");

    if (listen(listener, SOMAXCONN) < 0)
        fatal("listen");

    printf("Listening on %s:%d\n", inet_ntoa(addr.sin_addr), 8080);

    struct sockaddr_in client_name;
    socklen_t client_len = sizeof(struct sockaddr_in);
    int client = accept(listener, (struct sockaddr*)&client_name, &client_len);
    if (client == -1)
        fatal("accept");

    printf("Received connection from %s\n", inet_ntoa(client_name.sin_addr));

    char buffer[8192] = {0};
    while (g_continue)
    {
        int bytes = read(client, buffer, sizeof(buffer));
        if (bytes < 0)
            fatal("read");
        else if (bytes == 0)
            break ;
        
        buffer[bytes] = '\0';
        printf("Received message: %s\n", buffer);

        write(client, buffer, bytes);
    }

    close(client);
    close(listener);}
    return 0;
}