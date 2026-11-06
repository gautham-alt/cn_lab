import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server=("127.0.0.1",8080)

msg="yo big boi whats the time"
s.sendto(msg.encode(),server)
data,addr=s.recvfrom(1024)
print("time is ",data.decode())
s.close()
