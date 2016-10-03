import socket
import thread
 

TCP_IP = ''
TCP_PORT = 5021
BUFF = 1024
r=[]
def gen_response():
	return 'this_is_the_return_from_the_server'


def handler(clientsock,addr):
	while 1:
		data = clientsock.recv(BUFF)
		
        while correct_message[i:i+window]:
      
		print 'data:' + repr(data)
		if not data: break
		#o = raw_input('If data recv then 0 for NACK 1 for ACK : ')
		if o == '0':		
			r.append(o)
		else:
			r.append(data)
		clientsock.send(o)
		#print 'sent:' + repr(o)
		#if "close" == data.rstrip(): break
	print r
	clientsock.close()
	print addr, "- closed connection" #log on console


if __name__=='__main__':
    #ADDR = (HOST, PORT)
    #serversock = socket(AF_INET, SOCK_STREAM)
    #serversock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    #serversock.bind(ADDR)
    #serversock.listen(5)
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.bind((TCP_IP, TCP_PORT))
	s.listen(1)
	while 1:
		print 'waiting for connection...'
		clientsock, addr = s.accept()
		print '...connected from:', addr
		thread.start_new_thread(handler, (clientsock, addr))
