import socket

s = socket.socket(
    socket.AF_PACKET,
    socket.SOCK_RAW,
    socket.ntohs(3)
)


print("Packet capturing started...")

while True:
    packet, addr = s.recvfrom(65535)

    print("Packet received")
    print("Source:", addr[0])
    print("Size:", len(packet))
