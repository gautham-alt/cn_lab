import socket
import threading

clients = []

def chat(conn):
    while True:
        msg = conn.recv(1024)

        if not msg:
            break
           
        print(msg)
        for c in clients:
            if c != conn:
                c.send(msg)

    clients.remove(conn)
    conn.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(("0.0.0.0", 8080))
server.listen(5)

print("Server waiting...")

while True:
    conn, addr = server.accept()

    clients.append(conn)

    threading.Thread(target=chat, args=(conn,)).start()
