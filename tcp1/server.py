import socket 
import threading
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",8081))
s.listen(3)
clients=[]
def say(conn):
	while True:
		data=conn.recv(1024)
		print(data.decode())
		for i in clients:
			if i!=conn:
				i.send(data)
			
while True:
	conn,addr=s.accept()
	clients.append(conn)
	threading.Thread(target=say,args=(conn,)).start()
s.close()

