import socket
import threading
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",8081))
s.listen(5)
clients=[]
def chat(conn):
	while True:
		data=conn.recv(1024)
		if not data:
			break
		print(conn ,": ",data.decode())
		for i in clients:
			if i!=conn:
				i.send(data)
while True:
	conn,addr=s.accept()
	clients.append(conn)
	threading.Thread(target=chat,args=(conn,)).start()

