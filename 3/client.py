import socket
import threading

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(("127.0.0.1", 8080))

def receive():
    while True:
        data = s.recv(1024)

        if not data:
            break

        print("\nReceived:", data.decode())

threading.Thread(target=receive, daemon=True).start()

while True:
    msg = input("You: ")

    s.send(msg.encode())

    if msg == "exit":
        break

s.close()
