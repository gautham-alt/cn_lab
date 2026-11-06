import socket
import threading
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",8081))

def rec():
	while True:
		msg=s.recv(1024)
		print("\nrecived",msg.decode())
		print("ENter ",end="",flush = True)
threading.Thread(target=rec,daemon=True).start()
while True:

	data=input("Enter : ")
	if data=="":
		break
	s.send(data.encode())
	
s.close()
