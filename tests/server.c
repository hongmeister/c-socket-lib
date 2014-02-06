/**
 * Example echo server
 *
 * This is the server script
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/socket.h"

int main()
{
    char buff[100];
    int bytes;
    
    Socket *s = init_socket(AF_INET, SOCK_STREAM);
    s->bind(s, "127.0.0.1", 12345);
    s->listen(s, 5);
    
    ClientAddr client_addr;
    Socket *c = s->accept(s, &client_addr);
    
    printf("Client connected at %s:%d\n", client_addr.ip_addr, client_addr.port);
    
    while (1) {
        c->recv(c, buff, sizeof(buff));
        printf("Got: %s\n", buff);
        c->send(c, buff);
        printf("Sending: %s\n", buff);
    }
    
    socket_close(c);
    socket_close(s);
}