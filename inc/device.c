#include"device.h"

void device_init( _client_dev* client , int id )
{
        client->id = id;
        client->state = CLIENT_BORN;
        memset( client->r_buffer , 0 , BUF_SIZE );
        memset( client->w_buffer , 0 , BUF_SIZE );
}

void devq_push( _dev_q* queue , void ( *fun )( void* ) )
{
	if( NULL == queue->head )
	{
		queue->head = ( _d_node* )calloc( 1 , sizeof( _d_node ) );
		queue->head->fun = fun;
		queue->head->next = NULL;
		queue->size++;
		return;
	}

	_d_node* tmp = queue->head;
	while( NULL != tmp->next )
	{
		tmp = tmp->next;
	}
	tmp->next = ( _d_node* )calloc( 1 , sizeof( _d_node ) );
	tmp->next->fun = fun;
	tmp->next->next = NULL;
	queue->size++;
	return;
}

void devq_pop( _dev_q* queue )
{
	if( 0 == queue->size )
		return;

	_d_node* next = queue->head->next;
	free( queue->head );
	queue->head = next;
	queue->size--;
	return;
}

int devq_isempty( _dev_q* queue )
{
	return ( 0 == queue->size );
}

unsigned long devq_size( _dev_q* queue )
{
	return queue->size;
}

void devq_exe( _dev_q* queue )
{
	queue->head->fun( NULL );
	devq_pop( queue );
	return;
}

void devq_loop( _dev_q* queue )
{
	_d_node* tmp = queue->head;
	while( 1 )
	{
		tmp->fun( NULL );
		tmp = tmp->next;
		if( tmp = NULL )
		{
			tmp = queue->head;
		}
	}

	return;
}
