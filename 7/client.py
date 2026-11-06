import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server=("0.0.0.0",8080)
msg="hi im higautham idk"
s.sendto(msg.encode(),server)
data,addr=s.recvfrom(1024)
print(data.decode())
