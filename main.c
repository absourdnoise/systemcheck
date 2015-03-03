#include <stdio.h>
#include <stdlib.h>



int checkTCPConnetcion(char ip_address[15],int port) {
  printf("Cheking %s:%d\n", ip_address, port);
  return 0;
}

int main(int argc, char **argv) {
  checkTCPConnetcion("213.186.120.101", 80);
  return 0;
}
