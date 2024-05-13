# coding:utf-8
import threading
from socket import *

HOST = ''
PORT = 21567
BUFSIZ = 1024
ADDR = (HOST, PORT)

tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerSock.bind(ADDR)
tcpSerSock.listen(8)


def thread_it(func, *args):
    '''������������߳�'''
    t = threading.Thread(target=func, args=args)
    t.setDaemon(False)
    t.start()


def acceptSuc(tcpCliSock, addr):
    print('��һ���ͻ������ӳɹ�')
    while True:
        try:
            recv_data = tcpCliSock.recv(BUFSIZ)
        except ConnectionResetError:
            print('��һ���ͻ��˹ر�������')
        if recv_data:
            data = recv_data.decode('utf-8')
            print('���յ�%s' % data)
            tcpCliSock.send((data + " received").encode())


while True:
    print('waiting for connection...')
    tcpCliSock, addr = tcpSerSock.accept()
    print('...connnecting from:', addr)
    thread_it(acceptSuc, tcpCliSock, addr)
    print(tcpCliSock)