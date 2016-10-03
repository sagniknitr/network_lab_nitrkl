import socket
from thread import *
import string
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 8892))
s.listen(10)
window=3
c = {}
rec="HelloWorld"
ACK='0'
def clientthread(conn):
    while 1:

        data = conn.recv(4096)
        print"Receiving Packets"
        e = data
        i=len(e)
	print 'no of words received'
	print i
	print e
        j=0
        while(i!=0):
         if len(e) == 3:
          if (data == rec[j:j+window]):
            j+=window
            ACK='1'
          else:
           ACK='0'
         try:
          if ACK=='1':
           data='ACK'
           conn.send(data)
          else:
           data='NACK'
           conn.send(data)
           data='Please Send Again'
           conn.send(data)
           break
         except:
             data='No messages'
             

        conn.close()
while 1:
    conn, addr = s.accept()
    clientthread(conn)
s.close()
