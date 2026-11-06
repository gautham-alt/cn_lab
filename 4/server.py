import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("0.0.0.0",8080))
data,addr=s.recvfrom(1024)
msg=data.decode()
d={"tbh":"to be honest","ig":"I guess"}
for a,b in d.items():
	msg=msg.replace(a,b)
s.sendto(msg.encode(),addr)
