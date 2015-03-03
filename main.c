#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <memory.h>


int checkTCPConnetcion(char ip_address[15],int port) {
  int sockfd;
  
  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	printf("Socket ERROR\n");
	return -1;
  }
  return 0;
}

int main(int argc, char **argv) {
  checkTCPConnetcion("213.186.120.101", 80);
  return 0;
}
