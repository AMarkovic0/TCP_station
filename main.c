#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<sys/time.h>

#include"inc/tcp_server.h"
#include"inc/device.h"
#include"inc/gpio_driver.h"

#define PORT 12345u

void* client_thread( void* vargp );

char myIP[ MAX_IP_SIZE ];

int main( int argc , char* argv[] )
{
	pthread_t thread_id[ NUM_OF_DEVICES ];

	int newSocket[ NUM_OF_DEVICES ];
	struct sockaddr_in newAddr[ NUM_OF_DEVICES ];
	socklen_t addrSize[ NUM_OF_DEVICES ];

	getIP( myIP );

	tcp_server_init( myIP , PORT , LOG_ON );
	tcp_server_listen( NUM_OF_DEVICES , LOG_ON );

	for( uint8_t i = 0 ; i < NUM_OF_DEVICES ; i++ )
	{
		tcp_server_accept( &newSocket[ i ] , &newAddr[ i ] , &addrSize[ i ] , LOG_ON );

		pthread_create( &thread_id[ i ] , NULL , client_thread , (void*)&newSocket[ i ] );

		sleep( 0.4 );
	}
	
	for( uint8_t i = 0 ; i < NUM_OF_DEVICES ; i++ )
		pthread_join( thread_id[ i ] , NULL );

	close( sockfd );

	printf( "End of the program. \r\n" );

	return 0;
}

void* client_thread( void* vargp )
{
	int sock = *( (int*)vargp );	
	_client_dev device;
		
	device_init( &device , sock );
	_gpio ESP = { { GPIO_NONE } , { GPIO_OFF } , &device };
        
	printf("Data sending to client %d. \r\n" , device.id );
	gpio_handshake( &ESP );
	sleep( 1 );

	gpio_pin16_out( &ESP );
	sleep( 2 );
       
	while( gpio_heartbeat( ESP , 1 ) )
	{	
		gpio_pin16_toggle( &ESP );
		sleep( 1 );
	}

	printf( "Client %d dissconnected. \r\n" , ESP.device->id );

	return NULL;
}

