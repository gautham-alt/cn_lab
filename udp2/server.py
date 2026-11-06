import socket
import time


s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",8080))
while True:
	t=time.ctime()
	data,addr=s.recvfrom(1024)
	s.sendto(t.encode(),addr)
s.close()
