#include "tcp_server.h"

const uint8_t NUM_OF_DEVICES = 10;

int sockfd;
struct sockaddr_in serverAddr;

uint8_t tcp_server_init( char* ip , unsigned int port , _logs log )
{
	signal( SIGPIPE , SIG_IGN ); // block SIGPIPE signal in case client disconnect
	
	sockfd = socket( PF_INET , SOCK_STREAM , 0 );
	if( log && ( -1 == sockfd ) )
	{
		printf( "Socket creation failed. \r\n" );
		return -1;
	}
	else if( !log && ( -1 == sockfd ) )
	{
		return -1;
	}
	else if( log )
		printf( "Socket creation sucessfull. \r\n" );

	memset( &serverAddr , '\0' , sizeof( serverAddr ) );

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons( port );
	serverAddr.sin_addr.s_addr = inet_addr( ip );

	if( bind( sockfd , ( struct sockaddr* )&serverAddr , sizeof( serverAddr ) ) && log )
	{
		printf( "Bind failed %d. \r\n" , errno );
		return -1;
	}
	else if( bind( sockfd , ( struct sockaddr* )&serverAddr , sizeof( serverAddr ) ) && !log )
	{
		return -1;
	}
	else if( !bind( sockfd , ( struct sockaddr* )&serverAddr , sizeof( serverAddr ) ) && log )
		printf( "Bind sucessfull" );

	return -1;
}

uint8_t tcp_server_listen( int num_of_devices , _logs log )
{
	if( listen( sockfd , num_of_devices ) && log )
	{
		printf( "Listen failed. \r\n" );
		return -1;
	}
	else if( listen( sockfd , num_of_devices ) && !log )
	{
		return -1;
	}
	else if( log )
		printf( "Server listening... \r\n" );

	return 1;
}

uint8_t tcp_server_accept( int* newSocket_ , struct sockaddr_in* newAddr_ ,  socklen_t* addr_size_ , _logs log )
{
	int newSocket;
	struct sockaddr_in newAddr;
	socklen_t addr_size = sizeof( newAddr );

	newSocket = accept( sockfd , ( struct sockaddr* )&newAddr , &addr_size );
	if( ( newSocket < 0 ) && log )
	{
		printf( "Acception failed. \r\n" );
		return -1;
	}
	else if( ( newSocket < 0 ) && !log )
	{
		return -1;
	}
	else if( log )
		printf( "Client sucessfully accepted. \r\n" );

	*newSocket_ = newSocket;
	*newAddr_ = newAddr;
	*addr_size_ = addr_size;

	return 1;
}


int tcp_server_send( _client_dev client , char* w_buf )
{
	return send( client.id , w_buf , strlen( w_buf ) , 0 );
}

int tcp_server_recv( _client_dev client , char* r_buf )
{
	return recv( client.id , r_buf , BUF_SIZE , MSG_DONTWAIT );
}

void getIP( char* IPaddr )
{
	unsigned char ip_address[ MAX_IP_SIZE ];
    	int fd;
    	struct ifreq ifr;

    	/*AF_INET - to define network interface IPv4*/
    	/*Creating soket for it.*/
    	fd = socket( AF_INET , SOCK_DGRAM , 0 );

    	/*AF_INET - to define IPv4 Address type.*/
    	ifr.ifr_addr.sa_family = AF_INET;

    	/*eth0 - define the ifr_name - port name
    	where network attached.*/
    	memcpy( ifr.ifr_name , WIFI_INTERFACE , IFNAMSIZ-1 );

    	/*Accessing network interface information by
    	passing address using ioctl.*/
    	ioctl( fd , SIOCGIFADDR , &ifr );
    	/*closing fd*/
    	close( fd );

    	/*Extract IP Address*/
    	strcpy( IPaddr , inet_ntoa( ( ( struct sockaddr_in * )&ifr.ifr_addr )->sin_addr ) );

    	printf("System IP Address is: %s\n", IPaddr );

}
