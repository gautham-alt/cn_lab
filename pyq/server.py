import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",8080))
s.listen(1)
conn,addr=s.accept()

num1,num2,sign=conn.recv(1024).decode().split()
if sign=='+':
	num1=int(num1)
	num2=int(num2)
	num1+=num2
	conn.send(str(num1).encode())
else:
	print("noooo")
conn.close()
s.close()
