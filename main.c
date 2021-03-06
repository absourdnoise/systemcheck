#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <memory.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 256

int checkTCPConnetcion(char ip_address[15], int port) {
  int sockfd, n;
  char recivline[MAXLINE + 1];
  
  struct sockaddr_in servaddr;
  
  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	perror("Socket ERROR");
	return -1;
  }
  else {
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	if(inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
	  perror("inet_pton ERROR");
	  return -1;
	}
	else {
	  if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		perror("connect ERROR");
		return -1;
	  }
	  else {
		while( (n = read(sockfd, recivline, MAXLINE)) > 0) {
		  recivline[n] = 0;
		  if(fputs(recivline, stdout) == EOF) {
			perror("fputs ERROR");
			return -1;
		  }
		}
		if(n < 0) {
		  perror("read ERROR");
		  return -1;
		}
	  }
	}
  }
  return 0;
}

int main(int argc, char **argv) {
  checkTCPConnetcion("213.186.114.98", 110);
  return 0;
}
