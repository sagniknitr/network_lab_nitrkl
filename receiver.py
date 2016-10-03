import socket
from thread import *
from time import sleep
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 8892))
u = raw_input('Username: ')
print 'To send: recipient>message'
i=0
window=3
print 'Sending with window size 3'
def se(s):
    while 1:
        s.send( raw_input())
        print s.recv(1024)
def re(s):
    global i
    while 1:
	#global i
        s.send(u[i:i+window])
        i+=window
        r = s.recv(1024)
	if(r=='ACK'):
	 print 'Successfully received message'
	if(r=='NACK'):
	 print 'Sending data again'
	 continue
        if r != 'No messages':
            print r
        sleep(0.05)
start_new_thread(se ,(s,))
start_new_thread(re ,(s,))
while 1:
    pass

