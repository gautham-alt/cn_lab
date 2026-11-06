import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
msg=input("ENter sentence")
s.sendto(msg.encode(),("127.0.0.1",8080))
data,addr=s.recvfrom(1024)
print("formal english ",data.decode())
s.close()
