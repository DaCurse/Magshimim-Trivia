import socket
import json


def bytes_to_num(byte_arr, count):
    num = int(byte_arr[count - 1])
    for i in range(count - 2, -1, -1):
        num |= int(byte_arr[i]) << ((count - 1 - i) * 8)
    return num


def num_to_byte(num, count):
    byte_arr = [0] * count
    for i in range(0, count):
        byte_arr[count - 1 - i] = num >> (i * 8)
    return byte_arr


def build_packet(code, json_obj):
    j = json.dumps(json_obj) + '\0'
    packet = bytes([code, *num_to_byte(len(j), 4)])
    packet += j.encode()
    return packet


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.IPPROTO_TCP)
s.connect(('127.0.0.1', 8080))

logged_in = False

while True:
    if not logged_in:
        action = int(input('Choose option:\n1) Login\n2) Signup\nEnter the number of the option you chose: '))

        if action == 1:
            username = input('Enter username: ')
            password = input('Enter password: ')
            s.send(build_packet(101, {'username': username, 'password': password}))
        elif action == 2:
            username = input('Enter username: ')
            password = input('Enter password: ')
            email = input('Enter email: ')
            s.send(build_packet(102, {'username': username, 'password': password, 'email': email}))
    else:
        action = int(input('Choose option:\n1) Get players in room\n2) Join room\n3) Create room\nEnter the number of the option you chose: '))
        if action == 1:
            room_id = int(input('Enter room id: '))
            s.send(build_packet(103, {'roomId': room_id}))
        elif action == 2:
            room_id = int(input('Enter room id: '))
            s.send(build_packet(104, {'roomId': room_id}))
        elif action == 3:
            room_name = input('Enter room name: ')
            room_users = int(input('Enter room max users: '))
            room_count = int(input('Enter room question count: '))
            room_time = int(input('Enter room answer timeout: '))
            s.send(build_packet(105, {'roomName': room_name, 'maxUsers': room_users, 'questionCount': room_count, 'answerTimeout': room_time}))
            

    
    msg = s.recv(1024)
    print(msg)
    print(msg[0])
    print(bytes_to_num(list(msg[1:5]), 4))
    print(json.loads(msg[5:].decode()))

    if msg[0] == 201:
        print('Error in request')
        break
    if msg[0] == 202:
        print('Logged in')
        logged_in = True
    if msg[0] == 203:
        print('Signed up, you can log in now')


