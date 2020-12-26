import avl
from machine import Timer

class device(object):
    def __init__(self):
        sta_if = None
        serverX = None
        fun_tree = None
        fun_root = None
        thread_id = None
        h_bit_timer = None

    def do_connect(self, ssid, password):
        import network
        self.sta_if = network.WLAN(network.STA_IF)
        if not self.sta_if.isconnected():
            print("Connecting to network...")
            self.sta_if.active(True)
            self.sta_if.connect(ssid , password)
            while not self.sta_if.isconnected():
                pass
        print("Network config:", self.sta_if.ifconfig())
        del network
        return

    def to_server_connect(self, IP, PORT):
        import socket
        self.serverX = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
        self.serverX.connect((IP, PORT))
        print("Connected to server.")
        del socket
        return

    def h_beat_send(self):
        self.serverX.send(self.thread_id);
        return

    def h_beat(self, f):
        self.h_bit_timer = Timer(-1)
        self.h_bit_timer.init(period=f, mode=Timer.PERIODIC, callback=lambda t:self.h_beat_send())
        return

    def sort_function_list(self, function_list):
        for j in range(0, len(function_list)):
            for k in range(j, len(function_list)):
                if(str(function_list[k]) > str(function_list[j])):
                    tmp = function_list[k]
                    function_list[k] = function_list[j]
                    function_list[j] = tmp
        return function_list

    def setup(self, function_list):
        self.do_connect( "adams family" , "prvo100evra" )
        self.to_server_connect( "192.168.1.30" , 12345 )
        self.thread_id = ""
        self.fun_tree = avl.AVL_Tree()
        self.fun_root = None
        function_list = self.sort_function_list(function_list)
        print(function_list)
        key = 1
        for j in function_list:
            self.fun_root = self.fun_tree.insert( self.fun_root , key , j )
            key = key + 1

        return


