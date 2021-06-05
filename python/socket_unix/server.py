import os
import socket
import select
import sys
 
sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
path = './tt.d'
if os.path.exists(path):
   os.unlink(path)
sock.bind(path)
sock.listen(5)
 
infds, outfds, errfds = select.select([sock,],[],[],5)
if len(infds) != 0:
   con,addr = sock.accept()
   print con.recv(1024)
   con.close()
   sock.close()
print '5 seconds later no data coming'
