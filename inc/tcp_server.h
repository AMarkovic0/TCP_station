#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<errno.h>
#include<unistd.h>
#include<signal.h>

//Networking headers:
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<net/if.h>
#include<sys/ioctl.h>

#include"device.h"

#define MAX_IP_SIZE 15
#define WIFI_INTERFACE "wlp2s0"

typedef enum logging { LOG_ON = 1 , LOG_OFF = 0 } _logs;

uint8_t tcp_server_init( char* ip , unsigned int port , _logs log );
uint8_t tcp_server_listen( int num_of_devices , _logs log );
uint8_t tcp_server_accept( int* newSocket_ , struct sockaddr_in* newAddr ,  socklen_t* addr_size , _logs log );
int tcp_server_send( _client_dev client , char* w_buf );
int tcp_server_recv( _client_dev client , char* r_buf );
void getIP( char* IPaddr );

extern const uint8_t NUM_OF_DEVICES;

extern int sockfd;
extern struct sockaddr_in serverAddr;

#endif // _TCP_SERVER_H_

