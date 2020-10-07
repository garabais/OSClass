#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>

int main() {
	struct sockaddr_in serverAddress;
	bzero(&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(2727);
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(sockfd, 5);

	while (1) {
		struct sockaddr_in clientAddress;
		int clientSize = sizeof(clientAddress);
		int clientSocket = accept(sockfd, (struct sockaddr *)&clientAddress, (unsigned int*)&clientSize);
		//char c;
		//while (read(clientSocket, &c, 1)) {
        //    printf("%c", c);
		//}
        char* message = "Hello World";
        write(clientSocket, message, strlen(message));
		close(clientSocket);
	}
}
