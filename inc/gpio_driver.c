#include"gpio_driver.h"

int gpio_handshake( _gpio* gpio_device )
{
        while( 0 != strcmp( gpio_device->device->r_buffer , "init" ) )
        {
                memset( gpio_device->device->r_buffer , 0 , BUF_SIZE );
                tcp_server_recv( *gpio_device->device , gpio_device->device->r_buffer );
		sleep(1);
        }
        memset( gpio_device->device->r_buffer , 0 , BUF_SIZE );
        sprintf( gpio_device->device->w_buffer , "%d" , gpio_device->device->id );
        tcp_server_send( *gpio_device->device , gpio_device->device->w_buffer );

	// Empty TCP stack
	sleep( 1 );
	tcp_server_recv( *gpio_device->device , gpio_device->device->r_buffer );
	memset( gpio_device->device->r_buffer , 0 , BUF_SIZE );

        return 1;
}

int gpio_heartbeat( _gpio gpio_device , int min_beats )
{
	tcp_server_recv( *gpio_device.device , gpio_device.device->r_buffer );
       	printf( "Thread %d is running! \r\n" , gpio_device.device->id );
        printf( "Heart bit message: %s \r\n" , gpio_device.device->r_buffer );
        if( strlen( gpio_device.device->r_buffer ) < min_beats )
		return 0;
	memset( gpio_device.device->r_buffer , 0 , BUF_SIZE );
	return 1;
}

int gpio_pin16_out( _gpio* gpio_dev )
{
	return tcp_server_send( *gpio_dev->device , "17" );
}

int gpio_pin16_in( _gpio* gpio_dev )
{
	return tcp_server_send( *gpio_dev->device , "20" );
}

int gpio_pin16_on( _gpio* gpio_dev )
{
	return tcp_server_send( *gpio_dev->device , "18" );
}

int gpio_pin16_off( _gpio* gpio_dev )
{
	return tcp_server_send( *gpio_dev->device , "19" );
}

int gpio_pin16_toggle( _gpio* gpio_dev )
{
	return tcp_server_send( *gpio_dev->device , "16" );
}

/////////////////////////////////////////////////

int gpio_pin0_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "42" );
}

int gpio_pin0_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "45" );
}

int gpio_pin0_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "43" );
}

int gpio_pin0_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "44" );
}

int gpio_pin0_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "41" );
}

/////////////////////////////////////////////////

int gpio_pin2_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "12" );
}

int gpio_pin2_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "15" );
}

int gpio_pin2_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "13" );
}

int gpio_pin2_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "14" );
}

int gpio_pin2_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "11" );
}

/////////////////////////////////////////////////

int gpio_pin4_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "7" );
}

int gpio_pin4_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "10" );
}

int gpio_pin4_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "8" );
}

int gpio_pin4_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "9" );
}

int gpio_pin4_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "6" );
}

/////////////////////////////////////////////////

int gpio_pin5_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "2" );
}

int gpio_pin5_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "5" );
}

int gpio_pin5_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "3" );
}

int gpio_pin5_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "4" );
}

int gpio_pin5_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "1" );
}

/////////////////////////////////////////////////

int gpio_pin12_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "37" );
}

int gpio_pin12_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "40" );
}

int gpio_pin12_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "38" );
}

int gpio_pin12_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "39" );
}

int gpio_pin12_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "36" );
}

/////////////////////////////////////////////////

int gpio_pin13_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "32" );
}

int gpio_pin13_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "35" );
}

int gpio_pin13_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "33" );
}

int gpio_pin13_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "34" );
}

int gpio_pin13_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "31" );
}

/////////////////////////////////////////////////

int gpio_pin14_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "27" );
}

int gpio_pin14_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "30" );
}

int gpio_pin14_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "28" );
}

int gpio_pin14_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "29" );
}

int gpio_pin14_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "26" );
}

/////////////////////////////////////////////////

int gpio_pin15_out( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "25" );
}

int gpio_pin15_in( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "23" );
}

int gpio_pin15_on( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "23" );
}

int gpio_pin15_off( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "24" );
}

int gpio_pin15_toggle( _gpio* gpio_dev )
{
        return tcp_server_send( *gpio_dev->device , "21" );
}

/////////////////////////////////////////////////

