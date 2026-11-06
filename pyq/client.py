import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",8080))
num1=input("Enter number ")
num2=input("Enter number ")
sign=input("Enter sign ")
sign=num1+" "+num2+" "+sign
s.send(sign.encode())
res=s.recv(1024).decode()
print(res)
