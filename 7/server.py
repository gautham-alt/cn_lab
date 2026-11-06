import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",8080))

while True:
	data,addr=s.recvfrom(1024)
	data=data.decode()
	d={"hi": "hello","idk":"i dont know"}
	for a,b in d.items():
		data=data.replace(a,b)
	s.sendto(data.encode(),addr)
s.close()
