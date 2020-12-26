# TCP_home_station
TCP station for home automation.

Station for home automation. TCP server designed for control of stand alone home sensors and actuators.

Every device should have standardized firmware with ability to perform at least simple operations regarding its purpose. 

Every device is controlled by a station and the control algorithm should be executed as a station thread.

Idea is to control several devices at the same time and to save MCU power/time. 

Interesting example is to collect data from several devices and use them as neural network input. 

Neural network should be executed on the station computer. This example is simple blinking led

which includes ESP8266 (nodemcu) GPIO firmware, station server + gpio communication driver, testing client to run on PC

and simulate real device.

More advanced examples can be expected soon.


Tree:

├── ESP

│   ├── avl.py

│   ├── device_driver.py

│   ├── esp8266-20170108-v1.8.7.bin

│   ├── gpio_tree.txt

│   ├── main.py

│   ├── __pycache__

│   │   ├── avl.cpython-36.pyc

│   │   └── device_driver.cpython-36.pyc

│   ├── run_system.sh

│   └── upload_file.sh

├── inc

│   ├── device.c

│   ├── device.h

│   ├── gpio_driver.c

│   ├── gpio_driver.h

│   ├── libs.a

│   ├── tcp_server.c

│   └── tcp_server.h

├── main

├── main.c

├── makefile

└── test_client

    └── tcp_client.c
    

4 directories, 20 files
