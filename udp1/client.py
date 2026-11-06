import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server=("127.0.0.1",8080)
while True:
	msg=input("Enter message : ")
	if msg=="":
		break
	s.sendto(msg.encode(),server)
	data,addr=s.recvfrom(1024)
	print("server sent : ",data.decode())
s.close()
