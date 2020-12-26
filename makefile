CC = gcc
CFLAGS = -L"inc/" -Wall -g
VPATH = inc
LIBS = -lpthread -l s

LCFILES = device.c tcp_server.c gpio_driver.c

all: lib app

app: main.c
	$(CC) $(CFLAGS) -o main main.c $(LIBS)

lib:
	cd ./inc/; \
	$(CC) -c -g $(LCFILES); \
	ar rs libs.a *.o; \
	rm *.o
	cd ..

clean:
	rm *.p
