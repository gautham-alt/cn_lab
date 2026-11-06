import socket
import threading
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1", 8081))
def rec():
	while True:
		data=s.recv(1024)
		print("\nrecived ",data.decode())
		print("Enter  ",end="",flush=True)
threading.Thread(target=rec,daemon=True).start()
while True:
	msg=input("Enter ")
	
	s.send(msg.encode())
	if msg=="":
		break
s.close()
