#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {

	char c;
	char *message = "GET / HTTP/1.0\r\n\r\n";
	struct hostent *serverinfo = gethostbyname(argv[1]);
	struct sockaddr_in serverAddress;

	bzero(&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(2727);

	bcopy((char *)serverinfo->h_addr, (char *)&serverAddress.sin_addr, serverinfo->h_length);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));


	write(sockfd, message, strlen(message));

	while(read(sockfd,&c,1)) {
		printf("%c", c);
	}

	close(sockfd);
	return 0;
}
