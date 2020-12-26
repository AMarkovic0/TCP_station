import device_driver
from machine import Pin
import time

pin0 = None
pin2 = None
pin4 = None
pin5 = None
pin12 = None
pin13 = None
pin14 = None
pin15 = None
pin16 = None #Pin(16, Pin.OUT, value=1)

def pin0_out():
    global pin0
    pin0 = Pin(0, Pin.OUT, value=0)
    return

def pin0_in():
    global pin0
    pin0 = Pin(0, Pin.IN, pull=Pin.PULL_UP)
    return

def pin0_on():
    global pin0
    pin0.value(0)
    return

def pin0_off():
    global pin0
    pin0.value(1)
    return

def pin0_toggle():
    global pin0
    pin0.value(not pin0.value())
    return

def pin2_out():
    global pin2
    pin2 = Pin(2, Pin.OUT, value=1)
    return

def pin2_in():
    global pin2
    pin2 = Pin(2, Pin.IN, pull=Pin.PULL_UP)
    return

def pin2_on():
    global pin2
    pin2.value(0)
    return

def pin2_off():
    global pin2
    pin2.value(1)
    return

def pin2_toggle():
    global pin2
    pin2.value(not pin2.value())
    return

def pin4_out():
    global pin4
    pin4 = Pin(4, Pin.OUT, value=0)
    return

def pin4_in():
    global pin4
    pin4 = Pin(4, Pin.IN, pull=Pin.PULL_UP)
    return

def pin4_on():
    global pin4
    pin4.value(0)
    return

def pin4_off():
    global pin4
    pin4.value(1)
    return

def pin4_toggle():
    global pin4
    pin4.value(not pin4.value())
    return

def pin5_out():
    global pin5
    pin5 = Pin(5, Pin.OUT, value=0)
    return

def pin5_in():
    global pin5
    pin5 = Pin(5, Pin.IN, pull=Pin.PULL_UP)
    return

def pin5_on():
    global pin5
    pin5.value(0)
    return

def pin5_off():
    global pin5
    pin5.value(1)
    return

def pin5_toggle():
    global pin5
    pin5.value(not pin5.value())
    return

def pin12_out():
    global pin12
    pin12 = Pin(12, Pin.OUT, value=1)
    return

def pin12_in():
    global pin12
    pin12 = Pin(12, Pin.IN, pull=Pin.PULL_UP)
    return

def pin12_on():
    global pin12
    pin12.value(0)
    return

def pin12_off():
    global pin12
    pin12.value(1)
    return

def pin12_toggle():
    global pin12
    pin12.value(not pin12.value())
    return

def pin13_out():
    global pin13
    pin13 = Pin(13, Pin.OUT, value=0)
    return

def pin13_in():
    global pin13
    pin13 = Pin(13, Pin.IN, pull=Pin.PULL_UP)
    return

def pin13_on():
    global pin13
    pin13.value(0)
    return

def pin13_off():
    global pin13
    pin13.value(1)
    return

def pin13_toggle():
    global pin13
    pin13.value(not pin13.value())
    return

def pin14_out():
    global pin14
    pin14 = Pin(14, Pin.OUT, value=0)
    return

def pin14_in():
    global pin14
    pin14 = Pin(14, Pin.IN, pull=Pin.PULL_UP)
    return

def pin14_on():
    global pin14
    pin14.value(0)
    return

def pin14_off():
    global pin14
    pin14.value(1)
    return

def pin14_toggle():
    global pin14
    pin14.value(not pin14.value())
    return

def pin15_out():
    global pin15
    pin15 = Pin(15, Pin.OUT, value=0)
    return

def pin15_in():
    global pin15
    pin15 = Pin(15, Pin.IN, pull=Pin.PULL_UP)
    return

def pin15_on():
    global pin15
    pin15.value(0)
    return

def pin15_off():
    global pin15
    pin15.value(1)
    return

def pin15_toggle():
    global pin15
    pin15.value(not pin15.value())
    return

def pin16_out():
    global pin16
    pin16 = Pin(16, Pin.OUT, value=0)
    return

def pin16_in():
    global pin16
    pin16 = Pin(16, Pin.IN, pull=Pin.PULL_UP)
    return

def pin16_on():
    global pin16
    pin16.value(0)
    return

def pin16_off():
    global pin16
    pin16.value(1)
    return

def pin16_toggle():
    global pin16
    pin16.value(not pin16.value())
    return

my_device = device_driver.device()
function_list = [f for f in globals().values() if callable(f)]
my_device.setup(function_list)
my_device.fun_tree.preOrder(my_device.fun_root)

my_device.serverX.send("init")
my_device.thread_id = my_device.serverX.recv(1)

print(my_device.thread_id)

my_device.h_beat(100)
data = ""
while(1):
    data = my_device.serverX.recv(2)
    print(int(data))
    func = my_device.fun_tree.find(my_device.fun_root , int(data))
    func()
    data = ""
