#ifndef _DEVICE_H_
#define _DEVICE_H_

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define BUF_SIZE 1024

typedef enum client_states{ CLIENT_BORN , CLIENT_HANDSHAKE , CLIENT_INIT , CLIENT_OPERATIONAL , CLIENT_LOOP }client_states;

typedef struct device_node
{
	void ( *fun )( void* );
	struct device_node* next;
}_d_node;

typedef struct device_queue
{
	_d_node* head;
	unsigned long size;
}_dev_q;

typedef struct client_device
{
        int id;
        client_states state;
        char r_buffer[ BUF_SIZE ];
        char w_buffer[ BUF_SIZE ];
        _dev_q dev_q;
}_client_dev;

void device_init( _client_dev* client , int id );
void devq_push( _dev_q* queue , void ( *fun )( void* ) );
void devq_pop( _dev_q* queue );
int devq_isempty( _dev_q* queue );
unsigned long devq_size( _dev_q* queue );
void devq_exe( _dev_q* queue );
void devq_loop( _dev_q* queue );

#endif //_DEVICE_H_
